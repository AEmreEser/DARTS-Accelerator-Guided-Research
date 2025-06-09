`include "fpmult.sv"
`include "fpadd.v"

module FPMAC
(
    input [15:0] i_a,
    input [15:0] i_b,
    input [15:0] i_c,
    output [15:0] o_result
    // TODO: overflow, underflow flags etc.
);

wire [15:0] w_mult_result;
wire w_mult_snan, w_mult_qnan, w_mult_infinity, w_mult_zero, w_mult_subnormal, w_mult_normal;

// TODO: fix the latch inferences and width problems
FPMult stage_mult(
    .a(i_a),
    .b(i_b),
    .p(w_mult_result),

    .infinity(w_mult_infinity),
    .normal(w_mult_normal),
    .subnormal(w_mult_subnormal),
    .zero(w_mult_zero),
    .qnan(w_mult_qnan),
    .snan(w_mult_snan)
);

// TODO TIE OUTPUT FLAGS OF MULT UNIT TO OUTPUT FLAGS
//      via a state machine

// Don't assign anything to this
reg op_add = 1'b0; // hardwired add

wire w_add_ovf, w_add_udf;

`undef SYN_DEBUG // so that we don't synthesize debug outputs for the adder

FPAdd stage_add(
    .i_op_add_sub(op_add),
    .i_a(w_mult_result),
    .i_b(i_c),
    .o_y(o_result),
    .o_overflow(w_add_ovf),
    .o_underflow(w_add_udf)
);

endmodule
