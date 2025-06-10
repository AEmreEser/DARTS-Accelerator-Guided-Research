// This module only intends to execute a simple 2D convolution with a filter size of 3x3
// and a stride of 1. The largest output image supported with this configuration is 6x6, and the output image is also square.
// That is enoguh for out intended NNs.

`define DEBUG_PE_ARRAY
module PE_matrix  // Filter is square, d_in and d_out are fixed to be 1 for simplicity
# ( parameter PSUM_WIDTH = 36 )
(
    input logic clk,
    input logic rst,
    input logic start,

    input logic signed [15:0] Filt [3-1:0][3-1:0], 
    input logic signed [15:0] Img [28-1:0][28-1:0],
    
    output logic [6-1:0] counter,
    output logic done,
    output logic signed [PSUM_WIDTH-1:0] output_psum [28-3+1][28-3+1]
);

//logic rstAccumulation;

localparam filter_size_R = 3;

localparam h_in = 28; // Input image height
localparam w_in = 28; // Input image width

localparam h_out = h_in - filter_size_R + 1; 
localparam w_out = w_in - filter_size_R + 1;

localparam NumofRows = filter_size_R;
localparam NumofCols = h_out;

// (28x28) * (3x3) = (26x26) output, (3x26) PE array

/*
localparam OUT_CNT_W = $clog2(w_out);
logic [OUT_CNT_W-1:0] counter;
*/

// Data arrays for PEs
logic signed [15:0] ifmaps_active [h_in-1:0][filter_size_R-1:0];
// logic [15:0] filters [filter_size_R-1:0][filter_size_R-1:0]; // One 1D filter for each PE row, each having 3 elements, already is an input right now
// logic [31:0] psums [NumofRows-1:0][NumofCols-1:0];


logic PE_start;

logic PE_done [NumofRows-1:0][NumofCols-1:0];


logic signed [PSUM_WIDTH-1:0] psums [NumofRows-1:0][NumofCols-1:0];
// PE Intantions

logic signed [PSUM_WIDTH-1:0] adder3_outputs [NumofCols-1:0]; // Outputs of the 3-input adder for each column


logic COLUMN_DONE [25:0];

genvar yagiz;
generate
    for (yagiz = 0; yagiz < NumofCols; yagiz++) begin : column_done_gen
        assign COLUMN_DONE[yagiz] = PE_done[0][yagiz] && PE_done[1][yagiz] && PE_done[2][yagiz];
    end
endgenerate



logic PE_done_all;

assign PE_done_all = COLUMN_DONE[0] && COLUMN_DONE[1] && COLUMN_DONE[2] && COLUMN_DONE[3] && COLUMN_DONE[4] && COLUMN_DONE[5] &&
                     COLUMN_DONE[6] && COLUMN_DONE[7] && COLUMN_DONE[8] && COLUMN_DONE[9] && COLUMN_DONE[10] && COLUMN_DONE[11] &&
                     COLUMN_DONE[12] && COLUMN_DONE[13] && COLUMN_DONE[14] && COLUMN_DONE[15] && COLUMN_DONE[16] && COLUMN_DONE[17] &&
                     COLUMN_DONE[18] && COLUMN_DONE[19] && COLUMN_DONE[20] && COLUMN_DONE[21] && COLUMN_DONE[22] && COLUMN_DONE[23] &&
                     COLUMN_DONE[24] && COLUMN_DONE[25]; // Pretty unncesssary but wanted to make sure all PEs are done. // (PE_done  



always_comb begin // TODO indexleri kontrol edelim
    for (int i = 0; i < h_in; i++) begin
        for (int k = 0; k < filter_size_R; k++) begin
            ifmaps_active[i][k] = Img[i][counter + k];
        end
    end
end

// States and their transitions
typedef enum logic [4:0] {
    IDLE   = 5'b00001,
    PE_START = 5'b00010,
    ACTIVE = 5'b00100,
    SINGLE_CONV_DONE = 5'b01000,
    DONE   = 5'b10000
} state_t;

state_t currentState;
state_t nextState;

always_comb begin
    case (currentState)
        IDLE: begin
            if (start) begin
                nextState = PE_START;
                $display("Started!");
            end else begin
                nextState = IDLE;
            end
        
        end
        
        PE_START: begin
            nextState = ACTIVE;
        end

        ACTIVE: begin
            if (PE_done_all) begin
                nextState = SINGLE_CONV_DONE;
                $display("Single convolution done!");
            end else begin
                nextState = ACTIVE; // Stay in ACTIVE state until all PEs are done
            end
        end

        SINGLE_CONV_DONE: begin
                if (counter < w_out-1) begin
                    nextState = PE_START;
                end else begin
                    nextState = DONE;
                    $display("All done!");
                end
        end

        DONE: begin
            if (!start) begin
                nextState = IDLE; // Go back to IDLE when start is low
            end else begin
                nextState = DONE; // Stay in DONE state until reset or new start signal
            end
        end

        default: nextState = IDLE; // Default case to handle unexpected states, and also the initial state
    endcase
end

always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        currentState <= IDLE;
    end else begin
        currentState <= nextState;
    end
end

always_ff @(posedge clk) begin

    if (rst) begin
        done <= 0;
        counter <= 0;
        for ( int i = 0; i < h_out; i++) begin
            for ( int j = 0; j < w_out; j++) begin
                output_psum[i][j] <= 0;
            end
        end

        for (int i = 0; i < NumofRows; i++) begin
            for (int j = 0; j < NumofCols; j++) begin
                psums[i][j] <= 0;
            end
        end
        PE_start <= 0;
            
    end else begin
        case (currentState)
            IDLE: begin
                done <= 0;
                counter <= 0;
            end
            
            PE_START: begin
                done <= 0;
                PE_start <= 1;
                //rstAccumulation <= 1;
            end
            ACTIVE: begin
                PE_start <= 0;
                //rstAccumulation <= 0;
                $display("Active!");                
            end

            SINGLE_CONV_DONE: begin
                for (int col = 0; col < NumofCols; col++) begin
                     output_psum[col][counter] <= adder3_outputs[col];
                end                    
                counter <= counter + 1;
                
                `ifdef DEBUG_PE_ARRAY
                $display("%0t  counter=%0d ",  $time, counter);
                `endif

                // Store the results of the current column in the output array
            end

            DONE: begin
                done <= 1;
            end

        endcase
    end
    
end

// Ifmap 1 2 3 4 5 ... 28

// 1 2 3 4 5 ... 26
// 2 3 4 5 6 ... 27
// 3 4 5 6 7 ... 28


genvar i, j;
generate
    for (j = 0; j < NumofCols; j++) begin : pe_col
        for (i = 0; i < NumofRows; i++) begin : pe_row
            PE #(
                .PSUM_WIDTH(PSUM_WIDTH),
                .FILT_SIZE(filter_size_R)
            ) pe_inst (
                .clk(clk),
                .rst(rst),
                //.rstAccumulation(rstAccumulation),
                .start(PE_start),
                .done(PE_done[i][j]),
                .ifmap(ifmaps_active[i+j]),
                .filt(Filt[i]),
                .output_psum(psums[i][j])
            );
        end

        fixed_3_input_adder #(
            .a_size(PSUM_WIDTH),
            .b_size(PSUM_WIDTH),
            .c_size(PSUM_WIDTH),
            .outSize(PSUM_WIDTH)
        ) adder_inst (
            .a(psums[0][j]),
            .b(psums[1][j]),
            .c(psums[2][j]),
            .result(adder3_outputs[j])
        );
    end
endgenerate



endmodule
