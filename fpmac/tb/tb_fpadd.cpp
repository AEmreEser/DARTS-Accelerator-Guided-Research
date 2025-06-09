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

#include "Vfpadd___024root.h"
#include "Vfpadd.h"

namespace tc {
	struct test_case {
		uint16_t in_a;
		uint16_t in_b;
		uint8_t	 in_op_add_sub; // 0: add, 1: sub
	};

	std::vector<test_case> tc_q = {
		// NEED TO USE C++ 17 or newer
		// {0B0'00001'0000000000, 0B0'00001'0000000000, 0},
		// {0B0'01101'0101010101, 0B0'01101'0101010101, 0},
		// {0B0'00000'1111111111, 0B0'11110'0000000000, 0}, // max exponent difference (for unsigned exp)
		// {0B0'00000'1111111111, 0B0'01101'0000000000, 0}, // exp_diff: 13
		// {0B0'00000'1111111111, 0B0'01100'0000000000, 0}, // exp_diff: 12
		// {0B0'00000'1000000000, 0B0'01100'1111111111, 0},
		// {0B0'00011'0000000000, 0B0'01100'0000000000, 0},
		// {0B0'00011'0000000001, 0B0'01100'0000000001, 0},
		// {0B0'00011'0001000000, 0B0'01000'0001000000, 0},
		// mnts add sub test cases
		{0B0'00011'0001111111, 0B0'00010'0001111111, 0},
		{0B0'00011'1111111111, 0B0'00010'1111111111, 1},
		{0B0'00011'0000000000, 0B0'00010'1111001111, 1},
		{0B0'00011'1111001111, 0B0'00010'0000000000, 1},
		{0B0'00011'1111111111, 0B0'00011'1111111111, 1},
		{0B0'00011'1111111111, 0B0'00011'1111111111, 0},
		{0B0'11110'1111111111, 0B0'11110'1111111111, 0},
		{0B0'11111'0000000000, 0B0'00000'0000000000, 1}, // round tie and round_renorm case
		// rounding tests for all possible GRS bits with cond renorm = FALSE :
		{0B0'11110'0000000000, 0B0'11011'1111111111, 0},
		{0B0'11110'0000000000, 0B0'11011'1111111110, 0},
		{0B0'11110'0000000000, 0B0'11011'1111111101, 0},
		{0B0'11110'0000000000, 0B0'11011'1111111100, 0}, // tie case
		{0B0'11110'0000000000, 0B0'11011'1111111011, 0},
		{0B0'11110'0000000000, 0B0'11011'1111111010, 0},
		{0B0'11110'0000000000, 0B0'11011'1111111001, 0},
		{0B0'11110'0000000000, 0B0'11011'1111111000, 0},
		// sub tests:
		{0B0'11110'0000000000, 0B0'11011'1111111111, 1},
		{0B0'11110'0000000000, 0B0'11011'1111111110, 1},
		{0B0'11110'0000000000, 0B0'11011'1111111101, 1},
		{0B0'11110'0000000000, 0B0'11011'1111111100, 1}, 
		{0B0'11110'0000000000, 0B0'11011'1111111011, 1},
		{0B0'11110'0000000000, 0B0'11011'1111111010, 1},
		{0B0'11110'0000000000, 0B0'11011'1111111001, 1},
		{0B0'11110'0000000000, 0B0'11011'1111111000, 1},
		// overflow - inf output
		{0B0'11110'0000000000, 0B0'11110'1111111111, 0}, // o_ovf = 1
		// zero output
		{0B0'11110'0000000000, 0B0'11110'0000000000, 0}, // FIXED --> BUG HERE: should make exp zero
		{0B0'11110'0000000111, 0B0'11110'0000000111, 1},
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


	VFPAdd* dut = new VFPAdd;

	auto trace = std::make_unique<VerilatedVcdC>();
	dut->trace(trace.get(), trace_depth);
	trace->open("./traces/dump.vcd");

	// dut->reset = 1;
	// dut->eval();
	// dut->reset = 0; // do we need this?

	printf("=============================================================\n");
	for(int i = 0; i < (n_steps + tc::tc_q.size()); i++){
		// drive inputs
		// decided to use two rand 8 bit num generators cause the 16 bit uint generator produces single digit numbers way too frequently
		dut->i_a = (i < tc::tc_q.size()) ? (tc::tc_q[i].in_a) : rand_u8t(random) * rand_u8t(random); // rand_u16t(random) ; 
		dut->i_b = (i < tc::tc_q.size()) ? (tc::tc_q[i].in_b) : rand_u8t(random) * rand_u8t(random); // rand_u16t(random) ;
		dut->i_op_add_sub = (i < tc::tc_q.size()) ? ((uint8_t) (tc::tc_q[i].in_op_add_sub)) : (rand_u16t(random) % 2);

		if (i == tc::tc_q.size()){
			std::cout << "********************************" << std::endl;
			std::cout << "END OF DEFINED TESTCASES" 	<< std::endl;
			std::cout << "********************************" << std::endl;
		}

		if (verbose) {
			printf("Time: %d\n\n", i);
		}

		dut->eval();
		trace->dump(i);

		// in
		const auto & a = dut->i_a;	
		const auto & b = dut->i_a;	

		// Part 0 debug outputs
		const auto & do_sign_a  = dut->do_sign_a;
		const auto & do_sign_b  = dut->do_sign_b;

		const auto & do_exp_a  = dut->do_exp_a;
		const auto & do_exp_b  = dut->do_exp_b;

		const auto & do_mnts_a = dut->do_mnts_a;
		const auto & do_mnts_b = dut->do_mnts_b;

		// Part 2 debug outputs
		const auto & do_mnts_res = dut->do_mnts_adder_out;

		const auto & do_aligned_large_mnts = dut->do_aligned_large_mnts;
		const auto & do_shifted_small_mnts = dut->do_shifted_small_mnts;

		const auto & do_cond_mnts_complement = dut->do_cond_mnts_complement;
		const auto & do_mnts_res_cout = dut->do_mnts_res_cout;

		// out
		const auto & out = dut->o_y; // rename to y for consistency??
		
		if(verbose && binary) {
			printf("\nInputs:\n");
			std::cout << "\ta[sign]: " << std::bitset<1>(fp16_sign(dut->i_a)) << " a[exp]: " << std::bitset<EXP_WIDTH>(fp16_exp(dut->i_a)) << " a[mnts]: " << std::bitset<MNTS_WIDTH>(fp16_mnts(dut->i_a)) << std::endl;
			std::cout << "\tb[sign]: " << std::bitset<1>(fp16_sign(dut->i_b)) << " b[exp]: " << std::bitset<EXP_WIDTH>(fp16_exp(dut->i_b)) << " b[mnts]: " << std::bitset<MNTS_WIDTH>(fp16_mnts(dut->i_b)) << std::endl;
			std::printf("\tADD/SUB: %d\n", (uint8_t) (dut->i_op_add_sub));

			printf("Outputs:\n");
			std::cout << "\tdut->o_y = " << std::bitset<1+EXP_WIDTH+MNTS_WIDTH>(dut->o_y) << std::endl;
			std::cout << "Split: \n";
			printf("\tout[sign]: 0x%x, out[exp]: 0x%x, out[mnts]: 0x%x\n", fp16_sign(out), fp16_exp(out), fp16_mnts(out));
			std::cout << "\tout[sign]: " << std::bitset<1>(fp16_sign(dut->o_y)) << ", out[exp]: " << std::bitset<EXP_WIDTH>(fp16_exp(dut->o_y)) << ", out[mnts]: " << std::bitset<MNTS_WIDTH>(fp16_mnts(dut->o_y)) << std::endl;
			// std::cout << "\tmnts_res: " << std::bitset<(MNTS_WIDTH + GRS_WIDTH + 1 + 1)>(do_mnts_res) << " dec: " << do_mnts_res << std::endl;
			// std::cout << "\tcond complement: " << std::bitset<1>(do_cond_mnts_complement) << std::endl;
			// std::cout << "\taligned_large_mnts: " << std::bitset<(MNTS_WIDTH + GRS_WIDTH + 1)>(do_aligned_large_mnts) << " dec: " << do_aligned_large_mnts << std::endl;
			// std::cout << "\tshifted_small_mnts: " << std::bitset<(MNTS_WIDTH + GRS_WIDTH + 1)>(do_shifted_small_mnts) << " dec: " << do_shifted_small_mnts << std::endl;

			if (do_cond_mnts_complement) {
				assert(do_aligned_large_mnts == (do_mnts_res + do_shifted_small_mnts));
			} else {
				assert(do_mnts_res == (do_shifted_small_mnts + do_aligned_large_mnts));
			}

			if (do_cond_mnts_complement) { // COUT CANNOT BE 1 WHEN WE'RE SUBTRACTING (because we always subtract the smaller mnts from the larger mnts)
				assert(do_mnts_res_cout == 0);
			}

		} else if (verbose) {
			printf("\nInputs:\n");
			printf("\ta[sign]: 0x%x, a[exp]: 0x%x, a[mnts]: 0x%x\n", fp16_sign(dut->i_a), fp16_exp(dut->i_a), fp16_mnts(dut->i_a));
			printf("\tb[sign]: 0x%x, b[exp]: 0x%x, b[mnts]: 0x%x\n", fp16_sign(dut->i_b), fp16_exp(dut->i_b), fp16_mnts(dut->i_b));
			std::printf("\tADD/SUB: %d\n", (uint8_t) (dut->i_op_add_sub));

			printf("Outputs:\n");
			printf("\tout[sign]: 0x%x, out[exp]: 0x%x, out[mnts]: 0x%x\n", fp16_sign(out), fp16_exp(out), fp16_mnts(out));
			std::cout << "\tout[sign]: " << std::bitset<1>(fp16_sign(dut->o_y)) << ", out[exp]: " << std::bitset<EXP_WIDTH>(fp16_exp(dut->o_y)) << ", out[mnts]: " << std::bitset<MNTS_WIDTH>(fp16_mnts(dut->o_y)) << std::endl;
			// printf("\ta[sign]: 0x%x, a[exp]: 0x%x, a[mnts]: 0x%x\n", do_sign_a, do_exp_a, do_mnts_a);
			// printf("\tb[sign]: 0x%x, b[exp]: 0x%x, b[mnts]: 0x%x\n", do_sign_b, do_exp_b, do_mnts_b);

		} else {
			printf("Time: %d, out: 0x%x, in_a: 0x%x, in_b: 0x%x\n", i, dut->o_y, dut->i_a, dut->i_b);
		}
		printf("=============================================================\n");
	}

	trace->close();

	delete dut;

	exit(EXIT_SUCCESS);
}
