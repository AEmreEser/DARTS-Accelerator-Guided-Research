// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpmac__Syms.h"


VL_ATTR_COLD void Vfpmac___024root__trace_init_sub__TOP__0(Vfpmac___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+75,0,"i_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+76,0,"i_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+77,0,"i_c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+78,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("FPMAC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+75,0,"i_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+76,0,"i_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+77,0,"i_c",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+78,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1,0,"w_mult_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+2,0,"w_mult_snan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"w_mult_qnan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"w_mult_infinity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"w_mult_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"w_mult_subnormal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"w_mult_normal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"op_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"w_add_ovf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"w_add_udf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("stage_add", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"EXP_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"MNTS_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+91,0,"i_op_add_sub",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"i_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+77,0,"i_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+78,0,"o_y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+8,0,"o_overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"o_underflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"EXP_SPAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"MNTS_SPAN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"SIGN_IND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"EXP_BEG_IND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"EXP_END_IND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"MNTS_BEG_IND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"MNTS_END_IND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"mnts_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+79,0,"sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+81,0,"mnts_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+82,0,"large_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"large_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"large_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+83,0,"small_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+84,0,"small_exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+15,0,"small_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+16,0,"ext_larg_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+17,0,"ext_small_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+18,0,"exp_diff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+99,0,"GR_no_sticky_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"GRS_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"no_sticky_ulp_small_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+20,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"MAX_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"shifted_small_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+102,0,"OP_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+103,0,"OP_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+22,0,"mnts_adder_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+23,0,"mnts_res_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+24,0,"mnts_res_cout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"cond_mnts_complement",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"aligned_large_mnts",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+27,0,"renorm_shamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+28,0,"exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+82,0,"sign_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"shifted_mnts_ulp_cout_unadj_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+30,0,"shifted_mnts_ulp_cout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+31,0,"mnts_res_ulp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBit(c+32,0,"r_shift_new_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"exp_cout_norm_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"round_L",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"round_G",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"round_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"round_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"round_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"cond_renorm_stage_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"cond_renorm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"mnts_rnd_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+42,0,"exp_ovf_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"exp_cout_norm_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"renorm_exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+45,0,"renorm_mnts_rnd_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+46,0,"final_mnts_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+47,0,"final_exp_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("stage_mult", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+75,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+76,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1,0,"p",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+2,0,"snan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"qnan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"infinity",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"subnormal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"normal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"aSnan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"aQnan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"aInfinity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"aZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"aSubnormal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"aNormal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"bSnan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"bQnan",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"bInfinity",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"bZero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"bSubnormal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"bNormal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"aExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+61,0,"bExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+62,0,"pExp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+63,0,"t1Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+64,0,"t2Exp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+65,0,"aSig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+66,0,"bSig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+67,0,"pSig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+68,0,"tSig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+1,0,"pTmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+69,0,"rawSignificand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBit(c+70,0,"pSign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("aClass", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+75,0,"f",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+60,0,"fExp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+65,0,"fSig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+48,0,"isSnan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"isQnan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"isInfinity",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"isZero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"isSubnormal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"isNormal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"expOnes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"expZeroes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"sigZeroes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+71,0,"sa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+72,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("bClass", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+76,0,"f",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+61,0,"fExp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+66,0,"fSig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+54,0,"isSnan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"isQnan",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"isInfinity",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"isZero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"isSubnormal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"isNormal",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"expOnes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"expZeroes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"sigZeroes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBus(c+73,0,"sa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+74,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfpmac___024root__trace_init_top(Vfpmac___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfpmac___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vfpmac___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vfpmac___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfpmac___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vfpmac___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vfpmac___024root__trace_register(Vfpmac___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vfpmac___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vfpmac___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vfpmac___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vfpmac___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vfpmac___024root__trace_const_0_sub_0(Vfpmac___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfpmac___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_const_0\n"); );
    // Init
    Vfpmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpmac___024root*>(voidSelf);
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfpmac___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vfpmac___024root__trace_const_0_sub_0(Vfpmac___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+91,(0U));
    bufp->fullIData(oldp+92,(5U),32);
    bufp->fullIData(oldp+93,(0xaU),32);
    bufp->fullIData(oldp+94,(4U),32);
    bufp->fullIData(oldp+95,(9U),32);
    bufp->fullIData(oldp+96,(0xfU),32);
    bufp->fullIData(oldp+97,(0xeU),32);
    bufp->fullIData(oldp+98,(0U),32);
    bufp->fullIData(oldp+99,(2U),32);
    bufp->fullIData(oldp+100,(3U),32);
    bufp->fullIData(oldp+101,(0xdU),32);
    bufp->fullBit(oldp+102,(1U));
    bufp->fullBit(oldp+103,(0U));
    bufp->fullSData(oldp+104,(0x7ffU),11);
}

VL_ATTR_COLD void Vfpmac___024root__trace_full_0_sub_0(Vfpmac___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vfpmac___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_full_0\n"); );
    // Init
    Vfpmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpmac___024root*>(voidSelf);
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vfpmac___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vfpmac___024root__trace_full_0_sub_0(Vfpmac___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp),16);
    bufp->fullBit(oldp+2,(vlSelfRef.FPMAC__DOT__w_mult_snan));
    bufp->fullBit(oldp+3,(vlSelfRef.FPMAC__DOT__w_mult_qnan));
    bufp->fullBit(oldp+4,(vlSelfRef.FPMAC__DOT__w_mult_infinity));
    bufp->fullBit(oldp+5,(vlSelfRef.FPMAC__DOT__w_mult_zero));
    bufp->fullBit(oldp+6,(vlSelfRef.FPMAC__DOT__w_mult_subnormal));
    bufp->fullBit(oldp+7,(vlSelfRef.FPMAC__DOT__w_mult_normal));
    bufp->fullBit(oldp+8,(vlSelfRef.FPMAC__DOT__w_add_ovf));
    bufp->fullBit(oldp+9,(vlSelfRef.FPMAC__DOT__w_add_udf));
    bufp->fullBit(oldp+10,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                  >> 0xfU))));
    bufp->fullCData(oldp+11,((0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                       >> 0xaU))),5);
    bufp->fullSData(oldp+12,((0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp))),10);
    bufp->fullCData(oldp+13,(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp),5);
    bufp->fullSData(oldp+14,(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts),10);
    bufp->fullSData(oldp+15,(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts),10);
    bufp->fullSData(oldp+16,((0x400U | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts))),11);
    bufp->fullSData(oldp+17,((0x400U | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))),11);
    bufp->fullCData(oldp+18,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff),5);
    bufp->fullSData(oldp+19,((0x1000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts) 
                                         << 2U))),13);
    bufp->fullBit(oldp+20,(vlSelfRef.FPMAC__DOT__stage_add__DOT__sticky));
    bufp->fullSData(oldp+21,(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts),14);
    bufp->fullSData(oldp+22,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out),15);
    bufp->fullSData(oldp+23,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base),14);
    bufp->fullBit(oldp+24,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout));
    bufp->fullBit(oldp+25,(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_mnts_complement));
    bufp->fullSData(oldp+26,((0x2000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts) 
                                         << 3U))),14);
    bufp->fullCData(oldp+27,(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt),4);
    bufp->fullCData(oldp+28,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res),5);
    bufp->fullSData(oldp+29,(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky),15);
    bufp->fullSData(oldp+30,(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout),15);
    bufp->fullSData(oldp+31,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp),13);
    bufp->fullBit(oldp+32,(vlSelfRef.FPMAC__DOT__stage_add__DOT__r_shift_new_sticky));
    bufp->fullBit(oldp+33,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_cout_norm_1));
    bufp->fullBit(oldp+34,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                  >> 3U))));
    bufp->fullBit(oldp+35,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                  >> 2U))));
    bufp->fullBit(oldp+36,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                  >> 1U))));
    bufp->fullBit(oldp+37,((1U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp))));
    bufp->fullBit(oldp+38,(vlSelfRef.FPMAC__DOT__stage_add__DOT__round_a));
    bufp->fullBit(oldp+39,(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1));
    bufp->fullBit(oldp+40,(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm));
    bufp->fullSData(oldp+41,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_rnd_res),10);
    bufp->fullBit(oldp+42,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag));
    bufp->fullBit(oldp+43,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_cout_norm_2));
    bufp->fullCData(oldp+44,(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res),5);
    bufp->fullSData(oldp+45,(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res),10);
    bufp->fullSData(oldp+46,(((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag)
                               ? 0U : (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res))),10);
    bufp->fullCData(oldp+47,((((~ (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag)) 
                               & (0U == (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res)))
                               ? 0U : (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res))),5);
    bufp->fullBit(oldp+48,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSnan));
    bufp->fullBit(oldp+49,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aQnan));
    bufp->fullBit(oldp+50,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aInfinity));
    bufp->fullBit(oldp+51,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aZero));
    bufp->fullBit(oldp+52,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSubnormal));
    bufp->fullBit(oldp+53,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aNormal));
    bufp->fullBit(oldp+54,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSnan));
    bufp->fullBit(oldp+55,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bQnan));
    bufp->fullBit(oldp+56,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bInfinity));
    bufp->fullBit(oldp+57,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bZero));
    bufp->fullBit(oldp+58,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSubnormal));
    bufp->fullBit(oldp+59,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bNormal));
    bufp->fullCData(oldp+60,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aExp),7);
    bufp->fullCData(oldp+61,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bExp),7);
    bufp->fullCData(oldp+62,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pExp),7);
    bufp->fullCData(oldp+63,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t1Exp),7);
    bufp->fullCData(oldp+64,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp),7);
    bufp->fullSData(oldp+65,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig),11);
    bufp->fullSData(oldp+66,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig),11);
    bufp->fullSData(oldp+67,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSig),11);
    bufp->fullSData(oldp+68,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__tSig),11);
    bufp->fullIData(oldp+69,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__rawSignificand),22);
    bufp->fullBit(oldp+70,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign));
    bufp->fullCData(oldp+71,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa),4);
    bufp->fullIData(oldp+72,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__i),32);
    bufp->fullCData(oldp+73,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa),4);
    bufp->fullIData(oldp+74,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__i),32);
    bufp->fullSData(oldp+75,(vlSelfRef.i_a),16);
    bufp->fullSData(oldp+76,(vlSelfRef.i_b),16);
    bufp->fullSData(oldp+77,(vlSelfRef.i_c),16);
    bufp->fullSData(oldp+78,(vlSelfRef.o_result),16);
    bufp->fullBit(oldp+79,((1U & ((IData)(vlSelfRef.i_c) 
                                  >> 0xfU))));
    bufp->fullCData(oldp+80,((0x1fU & ((IData)(vlSelfRef.i_c) 
                                       >> 0xaU))),5);
    bufp->fullSData(oldp+81,((0x3ffU & (IData)(vlSelfRef.i_c))),10);
    bufp->fullBit(oldp+82,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
                                   ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                      >> 0xfU) : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0)
                                                   ? 
                                                  ((IData)(vlSelfRef.i_c) 
                                                   >> 0xfU)
                                                   : 
                                                  ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0)
                                                    ? 
                                                   ((IData)(vlSelfRef.i_c) 
                                                    >> 0xfU)
                                                    : 
                                                   ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                                    >> 0xfU)))))));
    bufp->fullBit(oldp+83,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
                                   ? ((IData)(vlSelfRef.i_c) 
                                      >> 0xfU) : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0)
                                                   ? 
                                                  ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                                   >> 0xfU)
                                                   : 
                                                  ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0)
                                                    ? 
                                                   ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                                    >> 0xfU)
                                                    : 
                                                   ((IData)(vlSelfRef.i_c) 
                                                    >> 0xfU)))))));
    bufp->fullCData(oldp+84,((0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
                                        ? ((IData)(vlSelfRef.i_c) 
                                           >> 0xaU)
                                        : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0)
                                            ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                               >> 0xaU)
                                            : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0)
                                                ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                                   >> 0xaU)
                                                : ((IData)(vlSelfRef.i_c) 
                                                   >> 0xaU)))))),5);
    bufp->fullBit(oldp+85,((0x1fU == (0x1fU & ((IData)(vlSelfRef.i_a) 
                                               >> 0xaU)))));
    bufp->fullBit(oldp+86,((1U & (~ (IData)((0U != 
                                             (0x1fU 
                                              & ((IData)(vlSelfRef.i_a) 
                                                 >> 0xaU))))))));
    bufp->fullBit(oldp+87,((1U & (~ (IData)((0U != 
                                             (0x3ffU 
                                              & (IData)(vlSelfRef.i_a))))))));
    bufp->fullBit(oldp+88,((0x1fU == (0x1fU & ((IData)(vlSelfRef.i_b) 
                                               >> 0xaU)))));
    bufp->fullBit(oldp+89,((1U & (~ (IData)((0U != 
                                             (0x1fU 
                                              & ((IData)(vlSelfRef.i_b) 
                                                 >> 0xaU))))))));
    bufp->fullBit(oldp+90,((1U & (~ (IData)((0U != 
                                             (0x3ffU 
                                              & (IData)(vlSelfRef.i_b))))))));
}
