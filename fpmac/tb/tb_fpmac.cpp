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

#include "Vfpmac___024root.h"
#include "Vfpmac.h"

namespace tc {
	struct test_case_mac {
		uint16_t in_a;
		uint16_t in_b;
		uint16_t in_c;
	};

	std::vector<test_case_mac> tc_q = {
		{0B0'00011'0001111111, 0B0'00010'0001111111, 0B0'00000'0000000000},
		{0B0'00011'1111111111, 0B0'00010'1111111111, 0B0'00000'0000000000},
		{0B0'00011'0000000000, 0B0'00010'1111001111, 0B0'00000'0000000000},
		{0B0'00011'1111001111, 0B0'00010'0000000000, 0B0'00000'0000000000},
		{0B0'00011'1111111111, 0B0'00011'1111111111, 0B0'00000'0000000000},
		{0B0'00011'1111111111, 0B0'00011'1111111111, 0B0'00000'0000000000},
		{0B0'11110'1111111111, 0B0'11110'1111111111, 0B0'00000'0000000000},
		{0B0'11111'0000000000, 0B0'00000'0000000000, 0B0'00000'0000000000}, // round tie and round_renorm case
		
		{0B0'11110'0000000000, 0B0'11011'1111111111, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111110, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111101, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111100, 0B0'00000'0000000000}, // tie case
		{0B0'11110'0000000000, 0B0'11011'1111111011, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111010, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111001, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111000, 0B0'00000'0000000000},
		
		{0B0'11110'0000000000, 0B0'11011'1111111111, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111110, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111101, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111100, 0B0'00000'0000000000}, 
		{0B0'11110'0000000000, 0B0'11011'1111111011, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111010, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111001, 0B0'00000'0000000000},
		{0B0'11110'0000000000, 0B0'11011'1111111000, 0B0'00000'0000000000},
		
		{0B0'11110'0000000000, 0B0'11110'1111111111, 0B0'00000'0000000000},
		
		{0B0'11110'0000000000, 0B0'11110'0000000000, 0B0'00000'0000000000}, 
       	{0B0'11110'0000000111, 0B0'11110'0000000111, 0B0'00000'0000000000},
	}; // tc_q
} // tc

#define SIGN_MASK 0b1'00000'0000000000
#define EXP_MASK  0b0'11111'0000000000
#define MNTS_MASK 0b0'00000'1111111111

#define EXP_WIDTH 5
#define MNTS_WIDTH 10
#define GRS_WIDTH 3

#define fp16_sign(x) ((x & SIGN_MASK) >> (EXP_WIDTH + MNTS_WIDTH))
#define fp16_exp(x)  ((x & EXP_MASK) >> MNTS_WIDTH)
#define fp16_mnts(x) (x & MNTS_MASK)

// this keeps the time
vluint64_t sim_time = 0;
// use the command line to change these
vluint64_t n_steps = 99;
vluint64_t trace_depth = 99;

// will fix the seed by default
uint16_t rand_u16t(const bool randomize = false) {
	if (randomize){
		std::random_device rd;                      // Random number generator seed
		std::mt19937 gen(rd());                     // Mersenne Twister engine
		std::uniform_int_distribution<uint16_t> dis(0, 65535);  // Uniform distribution for 16-bit values
		return dis(gen);
	} else { // fixed seed
		static int seed = 123;
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
		static int seed = 123;
		std::mt19937 gen(seed++);                     // Mersenne Twister engine
		std::uniform_int_distribution<uint8_t> dis(0, 63);  // Uniform distribution for 16-bit values
		return dis(gen);
	}
}

[[maybe_unused]]
void split_hf(uint16_t & sign, uint16_t & mnts, uint16_t & exp, uint16_t base) {
	sign = (base & SIGN_MASK);
	mnts = (base & MNTS_MASK);
	exp  = (base & EXP_MASK);
}

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


	Vfpmac* dut = new Vfpmac;

	auto trace = std::make_unique<VerilatedVcdC>();
	dut->trace(trace.get(), trace_depth);
	trace->open("./traces/dump.vcd");

	printf("=============================================================\n");
	for(int i = 0; i < (n_steps + tc::tc_q.size()); i++){
		// drive inputs
		// decided to use two rand 8 bit num generators cause the 16 bit uint generator produces single digit numbers way too frequently
		dut->i_a = (i < tc::tc_q.size()) ? (tc::tc_q[i].in_a) : rand_u8t(random) * rand_u8t(random); // rand_u16t(random) ; 
		dut->i_b = (i < tc::tc_q.size()) ? (tc::tc_q[i].in_b) : rand_u8t(random) * rand_u8t(random); // rand_u16t(random) ;
		dut->i_c = (i < tc::tc_q.size()) ? (tc::tc_q[i].in_c) : rand_u8t(random) * rand_u8t(random); // rand_u16t(random) ;

		if (i == tc::tc_q.size()){
			std::cout << "********************************" << std::endl;
			std::cout <<    "END OF DEFINED TESTCASES" 	    << std::endl;
			std::cout << "********************************" << std::endl;
		}

		if (verbose) {
			printf("Time: %d\n\n", i);
		}

		dut->eval();
		trace->dump(i);

		// in
		const auto & a = dut->i_a;	
		const auto & b = dut->i_b;	
		const auto & c = dut->i_c;	

        // out
		const auto & out = dut->o_result;
		
        printf("Time: %d, out: 0x%x, in_a: 0x%x, in_b: 0x%x, in_c: 0x%x\n", i, dut->o_result, dut->i_a, dut->i_b, dut->i_c);
		printf("=============================================================\n");
	}

	trace->close();

	delete dut;

	exit(EXIT_SUCCESS);
}
