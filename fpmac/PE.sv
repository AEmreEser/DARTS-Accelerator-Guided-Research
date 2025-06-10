`timescale 1ns/1ps

`define DEBUG

module PE #(
    parameter FILT_SIZE = 3,
    parameter PSUM_WIDTH = 32)
(
    input logic clk,
    input logic rst,
    
    input logic start,
    output logic done,

    input logic signed [15:0] ifmap       [FILT_SIZE-1:0],
    input logic signed [15:0] filt        [FILT_SIZE-1:0],
    output logic signed [PSUM_WIDTH-1:0] output_psum
    // input logic [PSUM_WIDTH-1 : 0] input_psum [ PSUM_SIZE - 1 : 0 ],
    
);

logic rstAccumulation;

// States
typedef enum logic [1:0] {
    IDLE   = 2'b00,
    CLEAR_PREV = 2'b11, // This state is used to clear the previous accumulation
    ACTIVE = 2'b01,
    DONE   = 2'b10
} state_t;

state_t currentState, nextState;


// Overal architecture of the PE


localparam CNT_W = $clog2(FILT_SIZE);
logic [CNT_W-1:0] counter;
// logic [3:0] counter; // TODO: Check the size of the counter 


logic signed [15:0] ifmap_active;
assign ifmap_active = ifmap[counter];

logic signed [15:0] filt_active;
assign filt_active = filt[counter];


logic signed [31:0] multiplied;

fixed_multiplier u_mult(
    .a(ifmap_active),
    .b(filt_active),
    .mult(multiplied)
);

assign rstAccumulation = (currentState == CLEAR_PREV);

// Need to choose between multiplied and InputPSUM 

logic signed [PSUM_WIDTH-1:0] SUM_input2;

MUX2to1 #(PSUM_WIDTH) mux2 (
    .in0(output_psum),
    .in1('0),
    .sel(rstAccumulation),
    .out(SUM_input2)
);


logic signed [PSUM_WIDTH-1:0] sum_out;

fixed_adder #(
    .a_size(32),
    .b_size(PSUM_WIDTH),
    .outSize(PSUM_WIDTH)
) adder (
    .a(multiplied),
    .b(SUM_input2),
    .result(sum_out)
);

// Next state definitions

always_comb begin : next_state_logic
    case (currentState)
        IDLE: begin
            if (start) begin
                nextState = CLEAR_PREV;
            end else begin
                nextState = IDLE;
            end
        end

        CLEAR_PREV: begin
            nextState = ACTIVE;
        end

        ACTIVE: begin
            if (counter == FILT_SIZE - 1) begin
                nextState = DONE;
            end else begin
                nextState = ACTIVE;
            end
        end

        DONE: begin
            if (start) begin
                nextState = CLEAR_PREV;
            end else begin
                nextState = DONE;
            end

        end
        default: begin
            nextState = IDLE;
        end

    endcase
end

always_ff @(posedge clk or posedge rst) begin : state_register
    if (rst) begin
        currentState <= IDLE;
    end else begin
        currentState <= nextState;
    end
end

always_ff @(posedge clk or posedge rst) begin: register_updates

    if (rst) begin

        output_psum <= '0;

    end else if (currentState == CLEAR_PREV) begin
        output_psum <= '0; // Clear the previous accumulation
    end else if (currentState == ACTIVE) begin
        `ifdef DEBUG
        $display("%0t  ifmap_active=%0d ",  $time, ifmap_active);
        $display("%0t  filt_active=%0d ",  $time, filt_active);
        $display("%0t  multiplied=%0d ",  $time, multiplied);
        $display("%0t  SUM_input2=%0d ",  $time, SUM_input2);
        $display("%0t  sum_out=%0d ",  $time, sum_out);
        `endif
        output_psum <= sum_out[PSUM_WIDTH-1:0];
    end else if (currentState == DONE) begin
        output_psum <= output_psum;
    end else begin
        output_psum <= output_psum; 
    end

end


always_ff @(posedge clk or posedge rst) begin : update_counter_and_done
    if(rst) begin
        counter <= 0;
        done <= 0;
        $display("%0t  counter=%0d  reset",  $time, counter);    
    end else if (currentState == IDLE) begin
        counter <= 0;
        done <= 0;
    end else if (currentState == CLEAR_PREV) begin
        done <= 0;
        counter <= 0; // Reset the counter when clearing previous accumulation
        //$display("%0t  counter=%0d  clear_prev",  $time, counter);
    end else if (currentState == ACTIVE) begin
        done <= 0; 
        if (counter == FILT_SIZE - 1) begin
            counter <= 0;
        end else if (counter == 0) begin
            counter <= counter + 1;
        end else begin
            counter <= counter + 1;
        end
        $display("%0t  counter=%0d  active",  $time, counter);
    end else if (currentState == DONE) begin

        done <= 1;
        counter <= 0;
        $display("%0t  counter=%0d  done",  $time, counter);
    end else begin
        done <= 0;
    end
end

endmodule
