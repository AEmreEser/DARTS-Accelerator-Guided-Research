// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpmac.h for the primary calling header

#include "Vfpmac__pch.h"
#include "Vfpmac___024root.h"

VL_ATTR_COLD void Vfpmac___024root___eval_static(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfpmac___024root___eval_initial(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfpmac___024root___eval_final(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__stl(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfpmac___024root___eval_phase__stl(Vfpmac___024root* vlSelf);

VL_ATTR_COLD void Vfpmac___024root___eval_settle(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vfpmac___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fpmac.sv", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfpmac___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__stl(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vfpmac___024root___ico_sequent__TOP__0(Vfpmac___024root* vlSelf);
VL_ATTR_COLD void Vfpmac___024root____Vm_traceActivitySetAll(Vfpmac___024root* vlSelf);

VL_ATTR_COLD void Vfpmac___024root___eval_stl(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vfpmac___024root___ico_sequent__TOP__0(vlSelf);
        Vfpmac___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vfpmac___024root___eval_triggers__stl(Vfpmac___024root* vlSelf);

VL_ATTR_COLD bool Vfpmac___024root___eval_phase__stl(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfpmac___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vfpmac___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__ico(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__act(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__nba(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpmac___024root____Vm_traceActivitySetAll(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vfpmac___024root___ctor_var_reset(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->i_a = VL_RAND_RESET_I(16);
    vlSelf->i_b = VL_RAND_RESET_I(16);
    vlSelf->i_c = VL_RAND_RESET_I(16);
    vlSelf->o_result = VL_RAND_RESET_I(16);
    vlSelf->FPMAC__DOT__w_mult_snan = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_mult_qnan = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_mult_infinity = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_mult_zero = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_mult_subnormal = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_mult_normal = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_add_ovf = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__w_add_udf = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aSnan = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aQnan = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aInfinity = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aZero = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aSubnormal = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aNormal = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bSnan = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bQnan = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bInfinity = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bZero = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bSubnormal = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bNormal = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aExp = VL_RAND_RESET_I(7);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bExp = VL_RAND_RESET_I(7);
    vlSelf->FPMAC__DOT__stage_mult__DOT__pExp = VL_RAND_RESET_I(7);
    vlSelf->FPMAC__DOT__stage_mult__DOT__t1Exp = VL_RAND_RESET_I(7);
    vlSelf->FPMAC__DOT__stage_mult__DOT__t2Exp = VL_RAND_RESET_I(7);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aSig = VL_RAND_RESET_I(11);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bSig = VL_RAND_RESET_I(11);
    vlSelf->FPMAC__DOT__stage_mult__DOT__pSig = VL_RAND_RESET_I(11);
    vlSelf->FPMAC__DOT__stage_mult__DOT__tSig = VL_RAND_RESET_I(11);
    vlSelf->FPMAC__DOT__stage_mult__DOT__pTmp = VL_RAND_RESET_I(16);
    vlSelf->FPMAC__DOT__stage_mult__DOT__rawSignificand = VL_RAND_RESET_I(22);
    vlSelf->FPMAC__DOT__stage_mult__DOT__pSign = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa = VL_RAND_RESET_I(4);
    vlSelf->FPMAC__DOT__stage_mult__DOT__aClass__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa = VL_RAND_RESET_I(4);
    vlSelf->FPMAC__DOT__stage_mult__DOT__bClass__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->FPMAC__DOT__stage_add__DOT__large_exp = VL_RAND_RESET_I(5);
    vlSelf->FPMAC__DOT__stage_add__DOT__large_mnts = VL_RAND_RESET_I(10);
    vlSelf->FPMAC__DOT__stage_add__DOT__small_mnts = VL_RAND_RESET_I(10);
    vlSelf->FPMAC__DOT__stage_add__DOT__exp_diff = VL_RAND_RESET_I(5);
    vlSelf->FPMAC__DOT__stage_add__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__shifted_small_mnts = VL_RAND_RESET_I(14);
    vlSelf->FPMAC__DOT__stage_add__DOT__mnts_adder_out = VL_RAND_RESET_I(15);
    vlSelf->FPMAC__DOT__stage_add__DOT__mnts_res_base = VL_RAND_RESET_I(14);
    vlSelf->FPMAC__DOT__stage_add__DOT__mnts_res_cout = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__cond_mnts_complement = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__renorm_shamt = VL_RAND_RESET_I(4);
    vlSelf->FPMAC__DOT__stage_add__DOT__exp_res = VL_RAND_RESET_I(5);
    vlSelf->FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky = VL_RAND_RESET_I(15);
    vlSelf->FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout = VL_RAND_RESET_I(15);
    vlSelf->FPMAC__DOT__stage_add__DOT__mnts_res_ulp = VL_RAND_RESET_I(13);
    vlSelf->FPMAC__DOT__stage_add__DOT__r_shift_new_sticky = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__exp_cout_norm_1 = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__round_a = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1 = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__cond_renorm = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__mnts_rnd_res = VL_RAND_RESET_I(10);
    vlSelf->FPMAC__DOT__stage_add__DOT__exp_ovf_flag = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__exp_cout_norm_2 = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT__renorm_exp_res = VL_RAND_RESET_I(5);
    vlSelf->FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res = VL_RAND_RESET_I(10);
    vlSelf->FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0 = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0 = VL_RAND_RESET_I(1);
    vlSelf->FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
