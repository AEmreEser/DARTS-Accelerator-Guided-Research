`timescale 1ns/1ps
module fixed_3_input_adder #(
    parameter a_size = 32,
    parameter b_size = 32,
    parameter c_size = 32,
    parameter outSize = 35
)(
    input  logic signed [a_size-1:0] a,
    input  logic signed [b_size-1:0] b,
    input logic signed [c_size-1:0] c,
    output logic signed [outSize - 1:0] result
);

    // Sanity check
    generate
        if (outSize < a_size) begin : PARAM_CHECK_A
            initial begin
                $error("Parameter mismatch: outSize (%0d) < a_size (%0d).", outSize, a_size);
                $finish;
            end
        end
        if (outSize < b_size) begin : PARAM_CHECK_B
            initial begin
                $error("Parameter mismatch: outSize (%0d) < b_size (%0d).", outSize, b_size);
                $finish;
            end
        end
        if (outSize < c_size) begin : PARAM_CHECK_C
            initial begin
                $error("Parameter mismatch: outSize (%0d) < c_size (%0d).", outSize, c_size);
                $finish;
            end
        end
    endgenerate

    // Sign extension before addition
    wire signed [outSize-1:0] a_ext = {{(outSize - a_size){a[a_size-1]}}, a};
    wire signed [outSize-1:0] b_ext = {{(outSize - b_size){b[b_size-1]}}, b};
    wire signed [outSize-1:0] c_ext = {{(outSize - c_size){c[c_size-1]}}, c};

    assign result = a_ext + b_ext + c_ext;

    
    

endmodule
