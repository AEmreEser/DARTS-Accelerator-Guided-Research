`timescale 1ns/10ps

// TODO: 
// Bypass logic for special values (inf, 0, NaN)
// Typical floating point corner cases
// Guard, round, sticky bits -- DONE
// if exponent alignment shift amt is larger than (or equal to?) 11 (mnts width + implicit 1 width), -- DONE
//		we should bypass regular addition and only set the sticky bit 1 (since we're going to pass the entire unit when the smaller one is all zeros, at least one bit must be set which would make the sticky bit 1 eventually
// Do we need to do smt about the bias??
// MUST check if the single stage preshifting logic is causing fan-in/out problems:
// check what sort of shifter is synthesized for pre&post shifting (barrel?)

module FPAdd #(
	// either hf16 or fp32
	parameter EXP_WIDTH 	= 5,
	parameter MNTS_WIDTH 	= 10
)(
	input i_op_add_sub, // 0: add, 1: sub
	// input i_cin,		// carry in - do we need this???
	// operand format: 15 ............ 0
	//				   [SIGN, EXP, MNTS]
	input  [15:0] 	i_a
	,input  [15:0] 	i_b
	// output format: 15 ............ 0
	//				  [SIGN, EXP, MNTS]
	,output [15:0] 	o_y
	,output reg	o_overflow
	,output	reg o_underflow

`ifdef SYN_DEBUG 
	// part 1 debug outputs
	,output [EXP_WIDTH-1:0]  do_exp_a
	,output [EXP_WIDTH-1:0]  do_exp_b
	,output [MNTS_WIDTH-1:0] do_mnts_a
	,output [MNTS_WIDTH-1:0] do_mnts_b
	,output 				 do_sign_a
	,output 				 do_sign_b

	// part 2 debug outputs
	,output reg [MNTS_WIDTH:0] 	do_ext_larger_mnts
	,output reg [MNTS_WIDTH:0] 	do_ext_small_mnts  
	,output reg 				do_large_sign
	,output reg [EXP_WIDTH-1:0] do_large_exp
	,output reg [EXP_WIDTH-1:0]	do_exp_diff		

	// part 3 debug outputs
	,output reg [MNTS_WIDTH + GRS_WIDTH + 1:0] 	do_mnts_adder_out
	,output reg [MNTS_WIDTH + GRS_WIDTH:0] 		do_aligned_large_mnts
	,output reg [MNTS_WIDTH + GRS_WIDTH:0] 		do_shifted_small_mnts
	,output 									do_cond_mnts_complement
	,output										do_mnts_res_cout
`endif
);

localparam EXP_SPAN 	= (EXP_WIDTH - 1);
localparam MNTS_SPAN 	= (MNTS_WIDTH - 1);

localparam SIGN_IND 	= (MNTS_WIDTH + EXP_WIDTH);

localparam EXP_BEG_IND 	= (MNTS_WIDTH);
localparam EXP_END_IND  = (MNTS_WIDTH + EXP_WIDTH - 1);

localparam MNTS_BEG_IND = (0);
localparam MNTS_END_IND = (MNTS_WIDTH - 1);


wire sign_a;
wire [EXP_SPAN:0] exp_a;
wire [MNTS_SPAN:0] mnts_a;

wire sign_b;
wire [EXP_SPAN:0] exp_b;
wire [MNTS_SPAN:0] mnts_b;

assign sign_a = i_a[SIGN_IND];
assign exp_a  = i_a[EXP_END_IND:EXP_BEG_IND];
assign mnts_a  = i_a[MNTS_END_IND:MNTS_BEG_IND];

assign sign_b = i_b[SIGN_IND];
assign exp_b  = i_b[EXP_END_IND:EXP_BEG_IND];
assign mnts_b  = i_b[MNTS_END_IND:MNTS_BEG_IND];

`ifdef SYN_DEBUG
	assign do_sign_a = sign_a;
	assign do_exp_a = exp_a; 
	assign do_mnts_a = mnts_a;

	assign do_sign_b = sign_b;
	assign do_exp_b = exp_b; 
	assign do_mnts_b = mnts_b;
`endif

// PART1 - UNPACKING:
// - reveals mantissa hidden bit
// - reroutes exponents to 'large' and 'small' exp signals
// - calculates absolute value of exp difference
reg large_sign;
reg [EXP_SPAN:0] large_exp;
reg [MNTS_SPAN:0] large_mnts;

reg small_sign;
reg [EXP_SPAN:0] small_exp;
reg [MNTS_SPAN:0] small_mnts;

// Rerouting to large and small
always@(*) begin: reroute_large_small

	if (exp_a > exp_b) begin : a_larger

		large_exp = exp_a;	
		large_mnts = mnts_a;
		large_sign = sign_a;

		small_exp = exp_b;
		small_mnts = mnts_b;
		small_sign = sign_b;

		`ifdef DISP
			$display("exp_a > exp_b");
			$display("exp_a: (%b)bin==(%d)dec, exp_b: (%b)bin==(%d)dec", exp_a, exp_a, exp_b, exp_b);
			$display("large_exp: (%b)bin==(%d)dec, small_exp: (%b)bin==(%d)dec", large_exp, large_exp, small_exp, small_exp);
		`endif

	end else if (exp_b > exp_a) begin : b_larger

		large_exp = exp_b;	
		large_mnts = mnts_b;
		large_sign = sign_b;

		small_exp = exp_a;
		small_mnts = mnts_a;
		small_sign = sign_a;

		`ifdef DISP
			$display("exp_a < exp_b");
			$display("exp_a: (%b)bin==(%d)dec, exp_b: (%b)bin==(%d)dec", exp_a, exp_a, exp_b, exp_b);
			$display("large_exp: (%b)bin==(%d)dec, small_exp: (%b)bin==(%d)dec", large_exp, large_exp, small_exp, small_exp);
		`endif

	end else begin : ab_equals // equals -> check mantissas

		`ifdef DISP
			$display("exp_a==exp_b");
			$display("exp_a: (%b)bin==(%d)dec, exp_b: (%b)bin==(%d)dec", exp_a, exp_a, exp_b, exp_b);
			$display("large_exp: (%b)bin==(%d)dec, small_exp: (%b)bin==(%d)dec", large_exp, large_exp, small_exp, small_exp);
		`endif

		if (mnts_b > mnts_a) begin : b_mnts_larger

			large_exp = exp_b;	
			large_mnts = mnts_b;
			large_sign = sign_b;

			small_exp = exp_a;
			small_mnts = mnts_a;
			small_sign = sign_a;

		`ifdef DISP
			$display("mnts_a < mnts_b");
		`endif

		end else begin : a_mnts_larger_equal

			large_exp = exp_a;	
			large_mnts = mnts_a;
			large_sign = sign_a;

			small_exp = exp_b;
			small_mnts = mnts_b;
			small_sign = sign_b;

		`ifdef DISP
			$display("mnts_a < mnts_b");
		`endif

		end : a_mnts_larger_equal

		`ifdef DISP
			$display("mnts_a: (%b)bin==(%d)dec, mnts_b: (%b)bin==(%d)dec", mnts_a, mnts_a, mnts_b, mnts_b);
			$display("large_mnts:(%b)bin==(%d)dec, small_mnts:(%b)bin==(%d)dec", large_mnts, large_mnts, small_mnts, small_mnts);
			$display("large_exp: (%b)bin==(%d)dec, small_exp: (%b)bin==(%d)dec", large_exp, large_exp, small_exp, small_exp);
		`endif

	end : ab_equals

end : reroute_large_small

// reveal hidden 1
wire [MNTS_SPAN + 1:0] 	ext_larg_mnts = {1'b1, large_mnts}; // 11 bits
wire [MNTS_SPAN + 1:0] 	ext_small_mnts  = {1'b1, small_mnts}; // 11 bits
// absolute value of exp difference
wire [EXP_SPAN:0]		exp_diff		= (large_exp - small_exp);

`ifdef SYN_DEBUG
	assign do_ext_larger_mnts 	= ext_larg_mnts;
	assign do_ext_small_mnts 	= ext_small_mnts;
	assign do_exp_diff 			= exp_diff;
	assign do_large_exp			= large_exp;
	assign do_large_sign		= large_sign;
`endif

`ifdef DISP
	always@(*) begin: display_part1
		$display("ext_larg_mnts: (%b)bin==(%d)dec\next_small_mnts: (%b)bin==(%d)dec", ext_larg_mnts, ext_larg_mnts, ext_small_mnts, ext_small_mnts);
		$display("exp_diff: (%b)bin==(%d)dec", exp_diff, exp_diff);
		$display("\n");
	end
`endif


// PART2. mantissa shifting (ie. preshifting)
localparam GR_no_sticky_WIDTH = 2;
localparam GRS_WIDTH = 3;

// no -1 since we also included the implicit 1 here
wire [MNTS_WIDTH + GR_no_sticky_WIDTH:0] no_sticky_ulp_small_mnts; // width 13

assign no_sticky_ulp_small_mnts = {ext_small_mnts, 2'b0}; // width 13

reg sticky;

// if the addition unit has not been bypassed, it means that neither operand is 0 -> hence there must be at least a single 1 in the smaller mnts which would turn the sticky bit 1 when we try to shift for MNTS_WIDTH OR MORE
localparam MAX_SHIFT = (MNTS_WIDTH + GR_no_sticky_WIDTH + 1); // mantissa + implicit 1 + GR bits == 13 bits in total

always@(*) begin: alw_sticky
	if (exp_diff > (MAX_SHIFT - 1)) begin : max_or_more // >= 13

		sticky = 1'b1;

		`ifdef DISP
			$display("exp_diff == %d(dec) > (MAX_SHIFT - 1)==(%d(dec))",exp_diff, (MAX_SHIFT - 1));
			$display("More than max shift: sticky=1'b1");
		`endif

	end else begin : less_than_max

		case (exp_diff)
			// MIND THE ENDING INDICES --------------------| 
			// we skip the GR bits (never included S) 	   V 
			5'd12 : sticky = |(no_sticky_ulp_small_mnts[11:2]);
			5'd11 : sticky = |(no_sticky_ulp_small_mnts[10:2]); // these correspond to shifting the entire mantissa into the GRS bits (which aren't part of the original mantissa)
			5'd10 : sticky = |(no_sticky_ulp_small_mnts[ 9:2]); // this shiftamt brings the implicit 1 down to the least sig. bit of the mantissa (non GRS)
			5'd9  : sticky = |(no_sticky_ulp_small_mnts[ 8:2]);
			5'd8  : sticky = |(no_sticky_ulp_small_mnts[ 7:2]);
			5'd7  : sticky = |(no_sticky_ulp_small_mnts[ 6:2]);
			5'd6  : sticky = |(no_sticky_ulp_small_mnts[ 4:2]);
			5'd5  : sticky = |(no_sticky_ulp_small_mnts[ 4:2]);
			5'd4  : sticky = |(no_sticky_ulp_small_mnts[ 3:2]);
			5'd3  : sticky = |(no_sticky_ulp_small_mnts[ 2:2]);
			default: begin

				sticky = 1'b0; // means that the shift amt could not push the lsb mantissa bit to the sticky
				`ifdef DISP
					$display("WARN: Default case in case(exp_diff): assigned sticky=0, exp_diff=%b==(%d)dec", exp_diff, exp_diff);
				`endif
			end // default
		endcase

		`ifdef DISP
			$display("for exp_diff=%d(dec), sticky=%b, no_stck_ulp_small_mnts=%b==%d(dec)", exp_diff, sticky, no_sticky_ulp_small_mnts, no_sticky_ulp_small_mnts);
		`endif

	end: less_than_max
end: alw_sticky

// no -1 since we also included the implicit 1 here
// should total 13 bits
wire [MNTS_WIDTH + GRS_WIDTH:0] shifted_small_mnts; // with sticky
assign shifted_small_mnts = { (no_sticky_ulp_small_mnts >> exp_diff), sticky }; 

`ifdef DISP
always@(*) begin
	$display("shifted_small_mnts (final)=%b==%d(dec)", shifted_small_mnts, shifted_small_mnts);
end
`endif

// PART 3: ADD/SUB
// mantissas do sign magn arithmetic
// for same sign add the two, for diff sign, invert b, add to a with CARRY IN SET to 1 (effectively 2's complement)
localparam OP_SUB = 1'b1;
localparam OP_ADD = 1'b0;

wire [MNTS_WIDTH + GRS_WIDTH + 1:0] mnts_adder_out; // 15 bits // + 1 since we might generate a carry bit and have to shift right
reg [MNTS_WIDTH + GRS_WIDTH:0] mnts_res_base;
reg mnts_res_cout;

// deciding whether to complement the smaller mantissa
wire cond_mnts_complement; // if signs diff and sub -> signs same
assign cond_mnts_complement = (sign_a ^ sign_b ^ i_op_add_sub); 
wire [MNTS_WIDTH + GRS_WIDTH:0] aligned_large_mnts;
assign aligned_large_mnts = {ext_larg_mnts, 3'b0}; // implicit bit + large mantissa + GRS bits (all 0)

always@(*) begin : alw_mnts_mag_calc
	`ifdef DISP
	// $display("cond mnts complement: %b", cond_mnts_complement);
	$display("aligned large mnts: %b==%d(dec)", aligned_large_mnts, aligned_large_mnts);
	`endif
	if (cond_mnts_complement) begin : l_min_s
		// mnts_res_cout = 1'b0;
		`ifdef DISP
		$display("cond mnts complement = 1");
		$display("2's comp small mnts: %b==%d==%b", ~(shifted_small_mnts) + 1'b1, ~(shifted_small_mnts) + 1'b1, -shifted_small_mnts);
		`endif

		// mnts_res_base = aligned_large_mnts + ~(shifted_small_mnts) + 1'b1; // 2's complement the small mnts
		{mnts_res_cout, mnts_res_base} = {1'b0, aligned_large_mnts} - shifted_small_mnts;
	end else begin : l_plus_s
		`ifdef DISP
		$display("cond mnts complement = 0");
		$display("sign a: %b, sign b: %b, op add sub: %b", sign_a, sign_b, i_op_add_sub);
		`endif

		{mnts_res_cout, mnts_res_base} = {1'b0, aligned_large_mnts} + shifted_small_mnts;
	end

end: alw_mnts_mag_calc

assign mnts_adder_out = {mnts_res_cout, mnts_res_base};

`ifdef SYN_DEBUG
	assign do_aligned_large_mnts 	= aligned_large_mnts;
	assign do_shifted_small_mnts 	= shifted_small_mnts;
	assign do_mnts_adder_out 		= mnts_adder_out;
	assign do_mnts_res_cout			= mnts_res_cout;
	assign do_cond_mnts_complement 	= cond_mnts_complement;
`endif

`ifdef DISP
always@(*) begin
	$display("mnts cout: %b, mnts_res_base: %b==%d(dec), mnts_adder_out: %d(dec)", mnts_res_cout, mnts_res_base, mnts_res_base, mnts_adder_out);
	$display("\n");
end
`endif

// PART 4: POST-NORMALIZATION
reg [3:0] renorm_shamt;

always@(*) begin: alw_lzc
	//priority encoder:
	casez({mnts_res_cout, mnts_res_base}) // equiv.: mnts_adder_out
		// [c,i,mnts.......GRS] // i: imp1, c: cout
		15'b1_?_??????????_??? : renorm_shamt = 4'hE; // 1 right shift
		15'b0_1_??????????_??? : renorm_shamt = 4'h0; // 0 left shift
		15'b0_0_1?????????_??? : renorm_shamt = 4'h1; // 1 left shift
		15'b0_0_01????????_??? : renorm_shamt = 4'h2; // 2 left shift
		15'b0_0_001???????_??? : renorm_shamt = 4'h3; // 3 left shift
		15'b0_0_0001??????_??? : renorm_shamt = 4'h4; // ...
		15'b0_0_00001?????_??? : renorm_shamt = 4'h5;	
		15'b0_0_000001????_??? : renorm_shamt = 4'h6;	
		15'b0_0_0000001???_??? : renorm_shamt = 4'h7;	
		15'b0_0_00000001??_??? : renorm_shamt = 4'h8;	
		15'b0_0_000000001?_??? : renorm_shamt = 4'h9;	
		15'b0_0_0000000001_??? : renorm_shamt = 4'hA;	
		15'b0_0_0000000000_1?? : renorm_shamt = 4'hB;	
		15'b0_0_0000000000_01? : renorm_shamt = 4'hC;	
		15'b0_0_0000000000_001 : renorm_shamt = 4'hD; // 13 left shift
		default				   : renorm_shamt = 4'hF; // <-> subtracted the same mnts from itself
	endcase
	`ifdef DISP
	$display("for mnts_adder_out: %b, renorm shift amt: %d(dec)", mnts_adder_out, renorm_shamt);
	`endif
end: alw_lzc

// cout == 1 --> CANNOT HOLD FOR (cond_ms_complement == 1) because we always subtrct the smaller mantissa from the larger mantissa
// hence cout will only hold overflow for addition of mantissas

// re-normalization of mantissa: 
// exp += renorm_shamt
// mantissa = mnts_adder_out << (renorm_shamt) // shifts the implicit bit out
// 	UNLESS we have mnts = zero
reg [EXP_WIDTH-1:0] exp_res;
wire sign_res;
assign sign_res = large_sign;
// CONTAINS IMP1:
reg [MNTS_WIDTH+GRS_WIDTH+1:0] shifted_mnts_ulp_cout_unadj_sticky; // 15 bits in total
reg [MNTS_WIDTH+GRS_WIDTH+1:0] shifted_mnts_ulp_cout; // 15 bits in total
reg [MNTS_WIDTH+GRS_WIDTH-1:0] mnts_res_ulp; // 13 bits in total = mnts (10) + grs (3) - NO imp1 or cout
reg r_shift_new_sticky;
reg exp_cout_norm_1;

always@(*) begin : alw_postnormalization_1

	if (mnts_res_cout) begin : right_shift
		`ifdef DISP
		if (cond_mnts_complement) begin
			$display("IMPOSSIBLE SITUATION!!! - YOU MESSED UP FOR REAL THIS TIME EMRE!");
		end

		$display("right postnorma shift");

		`endif

		{exp_cout_norm_1, exp_res} = (large_exp + 1'b1); // TODO: CHECK IF OVERFLOW OCCURS WHEN EXP_RES = (2^EXP_BITS-1-1) - one less from when it occurs here!!!
		o_overflow = (exp_res == {EXP_WIDTH{1'b1}});
		o_underflow = 1'b0;
		shifted_mnts_ulp_cout_unadj_sticky = (mnts_adder_out >> 1); 
		r_shift_new_sticky = shifted_mnts_ulp_cout_unadj_sticky[0] | mnts_adder_out[0]; // oring old S with R to adjust sticky
		mnts_res_ulp = {shifted_mnts_ulp_cout_unadj_sticky[MNTS_WIDTH+GRS_WIDTH - 1:1], r_shift_new_sticky}; // no imp1 or cout

		// prevent latch inference
		shifted_mnts_ulp_cout = {(MNTS_WIDTH+GRS_WIDTH+1+1){1'bx}};

	end else if (renorm_shamt == 4'hF) begin : res_zero
		`ifdef DISP
		$display("mnts result is zero, adjusting exp and sign");
		`endif

		o_overflow = 1'b0;
		o_underflow = 1'b0;
		exp_cout_norm_1 = 1'b0;
		exp_res = {EXP_WIDTH{1'b0}};
		mnts_res_ulp = {(MNTS_WIDTH+GRS_WIDTH){1'b0}};

		// prevent latch inference
		r_shift_new_sticky = 1'bx;
		shifted_mnts_ulp_cout_unadj_sticky = {(MNTS_WIDTH+GRS_WIDTH+1+1){1'bx}};
		shifted_mnts_ulp_cout = {(MNTS_WIDTH+GRS_WIDTH+1+1){1'bx}};

	end else begin : left_shift
		`ifdef DISP
		$display("left postnorm shift");
		`endif
		o_overflow = 1'b0;
		o_underflow = ({1'b0, renorm_shamt} > large_exp) ? 1'b1 : 1'b0; // TODO: DO WE CHECK FOR exp_res < MIN+2 for THIS OR IS IT CORRECT???? // DO WE NEED TO ADD THE BIAS ETC.????
		exp_res = (large_exp - renorm_shamt);
		exp_cout_norm_1 = 1'b0;

		// max left shift amt: (mnts_widt - 1)
		// for left shifts S does not participate in the left shift and we shift 0s into R (source: Stanford book pg 65)
		// synthesizes a decoder circuit:
		shifted_mnts_ulp_cout = {(mnts_adder_out[MNTS_WIDTH + GRS_WIDTH+1:1] << renorm_shamt), mnts_adder_out[0]};// prev: (renorm_shamt == 0) ? (mnts_adder_out[0]) : 1'b0}; // with cout + imp1
		mnts_res_ulp = shifted_mnts_ulp_cout[MNTS_WIDTH+GRS_WIDTH - 1:0]; // NO imp1 or cout

		// prevent latch inference
		r_shift_new_sticky = 1'bx;
		shifted_mnts_ulp_cout_unadj_sticky = {(MNTS_WIDTH+GRS_WIDTH+1+1){1'bx}};
	end

end : alw_postnormalization_1

// TODO: CHECK IF WE NEED TO DO ANYTHING TO THE EXPONENTS FOR BIAS ADJUSTMENTS AFTER ARITHMETIC
/** TODO: OVERFLOW <-> exp_res > (MAX - 1) not MAX: must adjust the checks above **/
/** TODO: UNDERFLOW: need to check if the value is below or eq (MIN + 1) - adjust hte checks above **/

// RNE ROUNDING (default mode of the standard)
wire round_L = mnts_res_ulp[3]; // lsb of the mantissa
wire round_G = mnts_res_ulp[2];
wire round_R = mnts_res_ulp[1];
wire round_S = mnts_res_ulp[0];
// this is what we add to the lsb of the mantissa to do the rounding:
wire round_a = (round_L | round_R | round_S) & round_G; // taken from ercegovac's book pg. 425


`ifdef DISP
always@(*) begin
	$display("mnts_res_ulp (no imp1 no cout): %b, renorm_shamt: %d", mnts_res_ulp, renorm_shamt);
	$display("\n");
	$display("round G: %b, R: %b, S: %b", round_G, round_R, round_S);
	if (~round_R & ~round_S & round_G) begin
		$display("Tie case");
	end
	$display("Round_a: %b", round_a);
	$display("\n");
end
`endif

wire cond_renorm_stage_1, cond_renorm; // cond renorm: mantissa overflow while adding guard PROVIDED THAT exponent didn't overflow in the prev stages
wire [MNTS_WIDTH+-1:0] mnts_rnd_res;
assign {cond_renorm_stage_1, mnts_rnd_res} = mnts_res_ulp[MNTS_WIDTH+GRS_WIDTH-1:3] + {{(MNTS_WIDTH-1){1'b0}},round_a};
assign cond_renorm = cond_renorm_stage_1 & (!o_overflow); // if overflown during normalization#1 - don't renormalize

`ifdef DISP
always@(*) begin
	$display("cond_renorm: %b", cond_renorm);
	$display("o_ovf: %b", o_overflow);
	$display("mnts_rnd_res: %b(bin) = %d(dec)", mnts_rnd_res, mnts_rnd_res);
	$display("\n");
end
`endif

reg exp_ovf_flag;
reg exp_cout_norm_2; // discarded
reg [EXP_WIDTH-1:0] renorm_exp_res;
reg [MNTS_WIDTH-1:0] renorm_mnts_rnd_res;
// renormalize_2 (because we might denormalize while rounding)
always@(*) begin : alw_renorm_2

	if (cond_renorm) begin
		{exp_cout_norm_2, renorm_exp_res} = exp_res + 1'b1;
		exp_ovf_flag = ( renorm_exp_res == {EXP_WIDTH{1'b1}} );
		renorm_mnts_rnd_res = {cond_renorm_stage_1, (mnts_rnd_res[MNTS_WIDTH-1:1])};
	end else begin
		renorm_exp_res = exp_res;
		renorm_mnts_rnd_res = mnts_rnd_res;
		exp_ovf_flag = 1'b0;
		exp_cout_norm_2 = 1'b0;
	end
	`ifdef DISP
	$display("renorm_exp_res: %b", renorm_exp_res);
	`endif

end : alw_renorm_2 

reg [MNTS_WIDTH-1:0] final_mnts_res;

always@(*) begin : alw_inf_mnts_pattern
	if (exp_ovf_flag) begin
		final_mnts_res = {MNTS_WIDTH{1'b0}};
		`ifdef DISP
		$display("ovf flag: %b, morphing output to INF", exp_ovf_flag);
		`endif
	end else begin
		final_mnts_res = renorm_mnts_rnd_res;
	end

end : alw_inf_mnts_pattern

reg [EXP_WIDTH-1:0] final_exp_res;

always@(*) begin : alw_zero_mnts_pattern
	// if not exp overflow (ie not inf) and renormalized result is zero:
	if (~exp_ovf_flag & (renorm_mnts_rnd_res == {MNTS_WIDTH{1'b0}})) begin
		final_exp_res = {EXP_WIDTH{1'b0}};
		`ifdef DISP
		$display("mnts zero with ovf flag: %b, morphing output to ZERO", exp_ovf_flag);
		`endif
	end else begin
		final_exp_res = renorm_exp_res;	
	end
end : alw_zero_mnts_pattern

assign o_y = {sign_res, final_exp_res, final_mnts_res};
// TODO: IMPLEMENT UNDERFLOW HANDLING, ZERO AND INF. INPUT CALCULATION BYPASSING, RETURNING NaN FOR INF - INF
// if we set things to inf, they might dominate in calculations (as inf + anything = inf) -> this is not smt we want when we use this thing's results to adjust weights

endmodule
