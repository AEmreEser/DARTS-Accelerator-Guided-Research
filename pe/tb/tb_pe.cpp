#include <verilated.h>
#include <iostream>
#include <memory>
#include <random>
#include <cstdint>
#include <stdio.h>
#include <unistd.h>
#include <bitset>
#include <vector>
#include <cassert>

#include <verilated_vcd_c.h>

#include "Vpe___024root.h"
#include "Vpe.h"

// SIM PARAMETERS:%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%:
#define HALF_PERIOD 5

#define IFMAP_WIDTH 16
#define FILT_WIDTH 16
#define OUTPUT_PSUM_WIDTH 16

#define FILT_SIZE 5

#define RANDOM_SEED 123

uint16_t rand_u16t(const bool randomize = false) {
	if (randomize){
		std::random_device rd;                      // Random number generator seed
		std::mt19937 gen(rd());                     // Mersenne Twister engine
		std::uniform_int_distribution<uint16_t> dis(0, 65535);  // Uniform distribution for 16-bit values
		return dis(gen);
	} else { // fixed seed
		static int seed = RANDOM_SEED;
		std::mt19937 gen(seed++);                     // Mersenne Twister engine
		std::uniform_int_distribution<uint16_t> dis(0, 65535);  // Uniform distribution for 16-bit values
		return dis(gen);
	}
}

uint8_t rand_u8t(const bool randomize = false) {
	if (randomize){
		std::random_device rd;                      // Random number generator seed
		std::mt19937 gen(rd());                     // Mersenne Twister engine
		std::uniform_int_distribution<uint8_t> dis(0, 63);  // Uniform distribution for 16-bit values
		return dis(gen);
	} else { // fixed seed
		static int seed = RANDOM_SEED;
		std::mt19937 gen(seed++);                     // Mersenne Twister engine
		std::uniform_int_distribution<uint8_t> dis(0, 63);  // Uniform distribution for 16-bit values
		return dis(gen);
	}
}

namespace tc {
	struct test_case {
		uint16_t in_ifmap;
		uint16_t in_filt;
	};

    // NEED TO USE C++ 17 or newer
	std::vector<test_case> tc_q = {
        // INSERT DEFINED CASES HERE!!!!
    }; // tc_q
} // tc

// use the command line to change these
vluint64_t n_steps = 99;
vluint64_t trace_depth = 99;

int main(int argc, char* argv[]){
    Verilated::mkdir("traces");
    Verilated::traceEverOn(true);

	bool verbose = false;
	bool binary = false;
	bool random = true;

	int opt = -1;
	while((opt = getopt(argc, argv, "v::s::t::b::r")) != -1){

		switch(opt){
			case 'v': 
				verbose = true;
				break;
			case 'r':
				random = true;
				break;
			case 'b':
				verbose = true;
				binary  = true;
				break;
			case 's':
				if(optarg){
					n_steps = atoi(optarg);
					break;
				} else {
					std::cerr << ("No argument provided for s") << std::endl;
					exit(1);
				}
			case 't':
				if(optarg){
					trace_depth = atoi(optarg);
					break;
				} else {
					std::cerr << ("No argument provided for t") << std::endl;
					exit(1);
				}
		} // switch
	}

    Vpe* dut = new Vpe;

	auto trace = std::make_unique<VerilatedVcdC>();
	dut->trace(trace.get(), trace_depth);
	trace->open("./traces/dump.vcd");

    unsigned long long sim_time = 0;

    // reset
    dut->rst = 0;
    dut->eval();
    dut->rst = 1;
    dut->eval();
    dut->rst = 0;
    dut->start = 1;

    int tc_i = 0; // test case index

    std:: cout << "BEGIN SIM" << std::endl << std::endl;

    // main loop
    while( !Verilated::gotFinish() && tc_i < n_steps){
        printf("================= cycle: %d ================", tc_i );

        dut->clk = 0;
        sim_time += HALF_PERIOD;
        dut->eval();


        for(int i_dut_in = 0; i_dut_in < FILT_SIZE; i_dut_in++){
            dut->ifmap[i_dut_in] = rand_u16t(random);
            dut->filt[i_dut_in] = rand_u16t(random);
            std::cout << "INPUTS - ifmap[" << i_dut_in << "]: " << std::bitset<IFMAP_WIDTH> (dut->ifmap[i_dut_in]) << " ---- filt[" << i_dut_in << "]: " << std::bitset<FILT_WIDTH> (dut->filt[i_dut_in]) << std::endl;
        } // for i_dut_in

        dut->clk = 1;
        sim_time += HALF_PERIOD;
        dut->eval();

        std::cout << "OUTPUT - psum: " << std::bitset<OUTPUT_PSUM_WIDTH> (dut->output_psum) << " ---- done: " << std::bitset<1> (dut->done) << std::endl;

        tc_i++; 

        std::cout << std::endl;

    } // got finish
    
    std::cout << "END OF SIM" << std::endl;
    return 0;
}

