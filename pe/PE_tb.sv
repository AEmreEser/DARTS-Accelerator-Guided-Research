// -----------------------------------------------------------------------------
// File: PE_tb.sv               IMPORTANT: This testbench does not work with Verilator somewhy. Need to test it with Xilinx Vivado.
// -----------------------------------------------------------------------------
`timescale 1ns/1ps
module PE_tb;

  /* -------- parameters that must match the DUT -------- */
  localparam int FILT_SIZE  = 5;
  localparam int PSUM_WIDTH = 32;

  /* -------- DUT I/O nets -------- */
  logic  clk  = 0;
  logic  rst  = 1;

  logic  rstAccumulation;
  logic  start;
  logic  done;

// ----------------------- PE ports -----------------------
logic signed [15:0] ifmap       [FILT_SIZE];
logic signed [15:0] filt        [FILT_SIZE];
logic signed [PSUM_WIDTH-1:0] output_psum;


  logic NoError = 1;


  /* -------- 100 MHz clock -------- */
  always #5ns clk <= ~clk;

  /* -------- instantiate the PE -------- */
  PE #(
      .FILT_SIZE (FILT_SIZE),
      .PSUM_width(PSUM_WIDTH)
  ) dut (
      .clk             (clk),
      .rst             (rst),
      .rstAccumulation (rstAccumulation),
      .start           (start),
      .done            (done),
      .ifmap           (ifmap),
      .filt            (filt),
      .output_psum     (output_psum)
  );


logic signed [PSUM_WIDTH-1:0] golden_sum;
int unsigned                  err_cnt = 0;


  /* ------------------------------------------------------------------ */
  function automatic logic [PSUM_WIDTH-1:0]
    golden_prod (logic [15:0] a, logic [15:0] b);
      golden_prod = a * b;          // unsigned 16×16 → 32 bits
  endfunction

  /* ------------------------------------------------------------------ */
    /* ------------------------------------------------------------------ */
  task automatic run_Accumulate (bit random_vec);
    /* ❶ drive new stimulus ------------------------------------------ */
    if (random_vec) begin
      foreach (ifmap[i]) begin
        logic [31:0] tmp = $urandom_range(0, 32'hFFFF_FFFF);
        ifmap[i] = tmp[15:0];
        filt [i] = tmp[31:16];
      end
    end else begin
      ifmap = '{16'd1,16'd2,16'd3,16'd4,16'd5};
      filt  = '{16'd5,16'd4,16'd3,16'd2,16'd1};
      
      
      
    end

    /* ❷ clear the internal partial sums ----------------------------- */
    @(negedge clk);
      rstAccumulation = 1'b1;
      start           = 1'b0;
    @(negedge clk);
      rstAccumulation = 1'b0;

    /* ❸ assert START and keep it high until DONE -------------------- */
    @(negedge clk)  start = 1'b1;
    wait (done == 1'b1);          // PE finished its FILT_SIZE cycles
    
        
    //@(negedge clk)  start = 1'b0; // let PE see the falling edge
    //@(negedge clk) start = 1'b1;
    
    //wait (done == 1'b1);
    
  endtask

  task automatic run_once (bit random_vec);
    /* --- ❶ stimulus ------------------------------------------------ */
    if (random_vec) begin
        foreach (ifmap[i]) begin
            logic [31:0] tmp = $urandom_range(0, 32'hFFFF_FFFF);
            ifmap[i] = tmp[15:0];
            filt [i] = tmp[31:16];
        end
    end else begin
        ifmap = '{16'sd1,16'sd2,16'sd3,16'sd4,16'sd5};
        filt  = '{16'sd5,16'sd4,16'sd3,16'sd2,16'sd1};
    end

    /* --- ❷ clear internal sum ------------------------------------- */
    @(negedge clk);
        rstAccumulation = 1;
        start           = 0;
    @(negedge clk);
        rstAccumulation = 0;

    /* --- ❸ run PE -------------------------------------------------- */
    @(negedge clk) start = 1;
    wait (done);            // PE finishes FILT_SIZE cycles
    @(negedge clk) start = 0;

    /* --- ❹ golden MAC & compare ----------------------------------- */
    golden_sum = '0;
    foreach (ifmap[i])
        golden_sum += ifmap[i] * filt[i];

    if (output_psum !== golden_sum) begin
        $error("[%0t] MISMATCH  DUT=%0d  GOLD=%0d",
               $time, output_psum, golden_sum);
        err_cnt++;
    end
endtask



  /* ------------------------------------------------------------------ */
initial begin
    /* global reset */
    repeat (3) @(negedge clk);
    rst = 0;

    /* deterministic check */
    run_once(0);

    /* 200 random checks */
    repeat (200) run_once(1);

    if (err_cnt == 0) $display("ALL TESTS PASSED :-)");
    else              $display("%0d test(s) FAILED.", err_cnt);

    $finish;
end


  /* optional VCD */
`ifdef TRACE
  initial begin
    $dumpfile("pe_tb.vcd");
    $dumpvars(0, PE_tb);
  end
`endif
endmodule
