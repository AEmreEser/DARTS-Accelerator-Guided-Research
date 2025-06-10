`timescale 1ns/1ps

module MUX2to1 #(
    parameter WIDTH = 32
)(
    input logic [WIDTH-1:0] in0,
    input logic [WIDTH-1:0] in1,
    input logic sel,
    output logic [WIDTH-1:0] out
);

    assign out = sel ? in1 : in0;

endmodule
