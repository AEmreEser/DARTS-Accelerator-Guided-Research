// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpmac.h for the primary calling header

#include "Vfpmac__pch.h"
#include "Vfpmac___024root.h"

void Vfpmac___024root___ico_sequent__TOP__0(Vfpmac___024root* vlSelf);

void Vfpmac___024root___eval_ico(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vfpmac___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vfpmac___024root___ico_sequent__TOP__0(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aQnan = (IData)(
                                                           (0x7e00U 
                                                            == 
                                                            (0x7e00U 
                                                             & (IData)(vlSelfRef.i_a))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aInfinity 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.i_a))) 
                   & (~ (IData)((0U != (0x3ffU & (IData)(vlSelfRef.i_a)))))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aZero = 
        (1U & ((~ (IData)((0U != (0x1fU & ((IData)(vlSelfRef.i_a) 
                                           >> 0xaU))))) 
               & (~ (IData)((0U != (0x3ffU & (IData)(vlSelfRef.i_a)))))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bQnan = (IData)(
                                                           (0x7e00U 
                                                            == 
                                                            (0x7e00U 
                                                             & (IData)(vlSelfRef.i_b))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bInfinity 
        = (IData)(((0x7c00U == (0x7c00U & (IData)(vlSelfRef.i_b))) 
                   & (~ (IData)((0U != (0x3ffU & (IData)(vlSelfRef.i_b)))))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bZero = 
        (1U & ((~ (IData)((0U != (0x1fU & ((IData)(vlSelfRef.i_b) 
                                           >> 0xaU))))) 
               & (~ (IData)((0U != (0x3ffU & (IData)(vlSelfRef.i_b)))))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSnan = (IData)(
                                                           ((0x7c00U 
                                                             == 
                                                             (0x7e00U 
                                                              & (IData)(vlSelfRef.i_a))) 
                                                            & (0U 
                                                               != 
                                                               (0x3ffU 
                                                                & (IData)(vlSelfRef.i_a)))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSnan = (IData)(
                                                           ((0x7c00U 
                                                             == 
                                                             (0x7e00U 
                                                              & (IData)(vlSelfRef.i_b))) 
                                                            & (0U 
                                                               != 
                                                               (0x3ffU 
                                                                & (IData)(vlSelfRef.i_b)))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aNormal 
        = (1U & (~ ((~ (IData)((0U != (0x1fU & ((IData)(vlSelfRef.i_a) 
                                                >> 0xaU))))) 
                    | (0x1fU == (0x1fU & ((IData)(vlSelfRef.i_a) 
                                          >> 0xaU))))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bNormal 
        = (1U & (~ ((~ (IData)((0U != (0x1fU & ((IData)(vlSelfRef.i_b) 
                                                >> 0xaU))))) 
                    | (0x1fU == (0x1fU & ((IData)(vlSelfRef.i_b) 
                                          >> 0xaU))))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSubnormal 
        = ((~ (IData)((0U != (0x1fU & ((IData)(vlSelfRef.i_a) 
                                       >> 0xaU))))) 
           & (0U != (0x3ffU & (IData)(vlSelfRef.i_a))));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSubnormal 
        = ((~ (IData)((0U != (0x1fU & ((IData)(vlSelfRef.i_b) 
                                       >> 0xaU))))) 
           & (0U != (0x3ffU & (IData)(vlSelfRef.i_b))));
    vlSelfRef.FPMAC__DOT__w_mult_snan = 0U;
    vlSelfRef.FPMAC__DOT__w_mult_qnan = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSnan) 
                  | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSnan))))) {
        if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aQnan) 
             | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bQnan))) {
            vlSelfRef.FPMAC__DOT__w_mult_qnan = 1U;
        } else if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aInfinity) 
                    | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bInfinity))) {
            if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aZero) 
                 | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bZero))) {
                vlSelfRef.FPMAC__DOT__w_mult_qnan = 1U;
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aNormal)))) {
        if (vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSubnormal) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__i = 0U;
        }
    }
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aExp = (0x1fU 
                                                   & ((IData)(vlSelfRef.i_a) 
                                                      >> 0xaU));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig = (0x3ffU 
                                                   & (IData)(vlSelfRef.i_a));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa = 0U;
    if (vlSelfRef.FPMAC__DOT__stage_mult__DOT__aNormal) {
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__aExp 
            = (0x7fU & ((0x1fU & ((IData)(vlSelfRef.i_a) 
                                  >> 0xaU)) - (IData)(0xfU)));
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig 
            = (0x400U | (0x3ffU & (IData)(vlSelfRef.i_a)));
    } else if (vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSubnormal) {
        if ((0U == (0x3ff8U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig), 8U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa 
                = (8U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa));
        }
        if ((0U == (0x3ff80U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig), 4U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa 
                = (4U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa));
        }
        if ((0U == (0xffe00U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig), 2U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa 
                = (2U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa));
        }
        if ((0U == (0x1ffc00U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig), 1U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa 
                = (1U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa));
        }
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__aExp 
            = (0x7fU & ((IData)(0x72U) - (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa)));
    }
    if ((1U & (~ (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bNormal)))) {
        if (vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSubnormal) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__i = 0U;
        }
    }
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bExp = (0x1fU 
                                                   & ((IData)(vlSelfRef.i_b) 
                                                      >> 0xaU));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig = (0x3ffU 
                                                   & (IData)(vlSelfRef.i_b));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa = 0U;
    if (vlSelfRef.FPMAC__DOT__stage_mult__DOT__bNormal) {
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__bExp 
            = (0x7fU & ((0x1fU & ((IData)(vlSelfRef.i_b) 
                                  >> 0xaU)) - (IData)(0xfU)));
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig 
            = (0x400U | (0x3ffU & (IData)(vlSelfRef.i_b)));
    } else if (vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSubnormal) {
        if ((0U == (0x3ff8U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig), 8U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa 
                = (8U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa));
        }
        if ((0U == (0x3ff80U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig), 4U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa 
                = (4U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa));
        }
        if ((0U == (0xffe00U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig), 2U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa 
                = (2U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa));
        }
        if ((0U == (0x1ffc00U & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig 
                = (0x7ffU & VL_SHIFTL_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig), 1U));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa 
                = (1U | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa));
        }
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__bExp 
            = (0x7fU & ((IData)(0x72U) - (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa)));
    }
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__rawSignificand 
        = (0x3fffffU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig) 
                        * (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig)));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign = 
        (1U & (((IData)(vlSelfRef.i_a) ^ (IData)(vlSelfRef.i_b)) 
               >> 0xfU));
    vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp = (0x7dffU 
                                                   | ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                                                      << 0xfU));
    vlSelfRef.FPMAC__DOT__w_mult_infinity = 0U;
    vlSelfRef.FPMAC__DOT__w_mult_zero = 0U;
    vlSelfRef.FPMAC__DOT__w_mult_subnormal = 0U;
    vlSelfRef.FPMAC__DOT__w_mult_normal = 0U;
    if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSnan) 
         | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSnan))) {
        vlSelfRef.FPMAC__DOT__w_mult_snan = 1U;
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
            = ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSnan)
                ? (IData)(vlSelfRef.i_a) : (IData)(vlSelfRef.i_b));
    } else if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aQnan) 
                | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bQnan))) {
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
            = ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aQnan)
                ? (IData)(vlSelfRef.i_a) : (IData)(vlSelfRef.i_b));
    } else if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aInfinity) 
                | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bInfinity))) {
        if (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aZero) 
             | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bZero))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
                = (0x7e2aU | ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                              << 0xfU));
        } else {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
                = (0x7c00U | ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                              << 0xfU));
            vlSelfRef.FPMAC__DOT__w_mult_infinity = 1U;
        }
    } else if ((((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aZero) 
                 | (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bZero)) 
                | ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSubnormal) 
                   & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSubnormal)))) {
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
            = ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
               << 0xfU);
        vlSelfRef.FPMAC__DOT__w_mult_zero = 1U;
    } else {
        vlSelfRef.FPMAC__DOT__stage_mult__DOT__t1Exp 
            = (0x7fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aExp) 
                        + (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bExp)));
        if ((0x200000U & vlSelfRef.FPMAC__DOT__stage_mult__DOT__rawSignificand)) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__tSig 
                = (0x7ffU & (vlSelfRef.FPMAC__DOT__stage_mult__DOT__rawSignificand 
                             >> 0xbU));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp 
                = (0x7fU & ((IData)(1U) + VL_EXTENDS_II(7,7, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t1Exp))));
        } else {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__tSig 
                = (0x7ffU & (vlSelfRef.FPMAC__DOT__stage_mult__DOT__rawSignificand 
                             >> 0xaU));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp 
                = vlSelfRef.FPMAC__DOT__stage_mult__DOT__t1Exp;
        }
        if (VL_GTS_III(32, 0xffffffe8U, VL_EXTENDS_II(32,7, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
                = ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                   << 0xfU);
            vlSelfRef.FPMAC__DOT__w_mult_zero = 1U;
        } else if (VL_GTS_III(32, 0xfffffff2U, VL_EXTENDS_II(32,7, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSig 
                = (0x7ffU & VL_SHIFTR_III(11,11,32, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__tSig), 
                                          ((IData)(0xfffffff2U) 
                                           - VL_EXTENDS_II(32,7, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp)))));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
                = (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                    << 0xfU) | (0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSig)));
            vlSelfRef.FPMAC__DOT__w_mult_subnormal = 1U;
        } else if (VL_LTS_III(32, 0xfU, VL_EXTENDS_II(32,7, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp)))) {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
                = (0x7c00U | ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                              << 0xfU));
            vlSelfRef.FPMAC__DOT__w_mult_infinity = 1U;
        } else {
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pExp 
                = (0x7fU & ((IData)(0xfU) + VL_EXTENDS_II(7,7, (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp))));
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSig 
                = vlSelfRef.FPMAC__DOT__stage_mult__DOT__tSig;
            vlSelfRef.FPMAC__DOT__w_mult_normal = 1U;
            vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp 
                = (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign) 
                    << 0xfU) | ((0x7c00U & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pExp) 
                                            << 0xaU)) 
                                | (0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSig))));
        }
    }
    vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_mnts_complement 
        = (1U & (((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                  ^ (IData)(vlSelfRef.i_c)) >> 0xfU));
    vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0 
        = ((0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                     >> 0xaU)) > (0x1fU & ((IData)(vlSelfRef.i_c) 
                                           >> 0xaU)));
    vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0 
        = ((0x1fU & ((IData)(vlSelfRef.i_c) >> 0xaU)) 
           > (0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                       >> 0xaU)));
    vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0 
        = ((0x3ffU & (IData)(vlSelfRef.i_c)) > (0x3ffU 
                                                & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp)));
    if (vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0) {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts 
            = (0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts 
            = (0x3ffU & (IData)(vlSelfRef.i_c));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp 
            = (0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                        >> 0xaU));
    } else if (vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0) {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts 
            = (0x3ffU & (IData)(vlSelfRef.i_c));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts 
            = (0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp 
            = (0x1fU & ((IData)(vlSelfRef.i_c) >> 0xaU));
    } else if (vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0) {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts 
            = (0x3ffU & (IData)(vlSelfRef.i_c));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts 
            = (0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp 
            = (0x1fU & ((IData)(vlSelfRef.i_c) >> 0xaU));
    } else {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts 
            = (0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts 
            = (0x3ffU & (IData)(vlSelfRef.i_c));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp 
            = (0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                        >> 0xaU));
    }
    vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff 
        = (0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp) 
                    - ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
                        ? ((IData)(vlSelfRef.i_c) >> 0xaU)
                        : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0)
                            ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                               >> 0xaU) : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0)
                                            ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                               >> 0xaU)
                                            : ((IData)(vlSelfRef.i_c) 
                                               >> 0xaU))))));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__sticky = 
        ((0xcU < (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff)) 
         || ((1U & (~ ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff) 
                       >> 4U))) && ((8U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                     ? ((4U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                         ? ((1U & (~ 
                                                   ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff) 
                                                    >> 1U))) 
                                            && ((1U 
                                                 & (~ (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))) 
                                                && (0U 
                                                    != (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))))
                                         : ((2U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                                 ? 
                                                (0U 
                                                 != 
                                                 (0x1ffU 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts)))
                                                 : 
                                                (0U 
                                                 != 
                                                 (0xffU 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                                 ? 
                                                (0U 
                                                 != 
                                                 (0x7fU 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts)))
                                                 : 
                                                (0U 
                                                 != 
                                                 (0x3fU 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))))))
                                     : ((4U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                         ? ((2U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                                 ? 
                                                (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts)))
                                                 : 
                                                (0U 
                                                 != 
                                                 (7U 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff))
                                                 ? 
                                                (0U 
                                                 != 
                                                 (7U 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts)))
                                                 : 
                                                (0U 
                                                 != 
                                                 (3U 
                                                  & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts)))))
                                         : ((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff) 
                                                   >> 1U)) 
                                            && ((1U 
                                                 & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff)) 
                                                && (1U 
                                                    & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))))))));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts 
        = ((0x3ffeU & (((0x1000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts) 
                                    << 2U)) >> (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff)) 
                       << 1U)) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__sticky));
    if (vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_mnts_complement) {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base 
            = (0x3fffU & ((0x2000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts) 
                                      << 3U)) - (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout 
            = (1U & (1U & (((0x2000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts) 
                                        << 3U)) - (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts)) 
                           >> 0xeU)));
    } else {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base 
            = (0x3fffU & ((0x2000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts) 
                                      << 3U)) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout 
            = (1U & (1U & (((0x2000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts) 
                                        << 3U)) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts)) 
                           >> 0xeU)));
    }
    vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_cout_norm_1 
        = ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
           && (1U & (((IData)(1U) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp)) 
                     >> 5U)));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out 
        = (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
            << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt 
        = (((((((((0x4000U == (0x4000U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                           << 0xeU) 
                                          | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base)))) 
                  | (0x2000U == (0x6000U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                             << 0xeU) 
                                            | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))) 
                 | (0x1000U == (0x7000U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                            << 0xeU) 
                                           | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))) 
                | (0x800U == (0x7800U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                          << 0xeU) 
                                         | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))) 
               | (0x400U == (0x7c00U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                         << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))) 
              | (0x200U == (0x7e00U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                        << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))) 
             | (0x100U == (0x7f00U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                       << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))) 
            | (0x80U == (0x7f80U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                     << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base)))))
            ? ((0x4000U == (0x4000U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                        << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                ? 0xeU : ((0x2000U == (0x6000U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                   << 0xeU) 
                                                  | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                           ? 0U : ((0x1000U == (0x7000U 
                                                & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                    << 0xeU) 
                                                   | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                    ? 1U : ((0x800U 
                                             == (0x7800U 
                                                 & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                     << 0xeU) 
                                                    | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                             ? 2U : 
                                            ((0x400U 
                                              == (0x7c00U 
                                                  & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                      << 0xeU) 
                                                     | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                              ? 3U : 
                                             ((0x200U 
                                               == (0x7e00U 
                                                   & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                       << 0xeU) 
                                                      | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                               ? 4U
                                               : ((0x100U 
                                                   == 
                                                   (0x7f00U 
                                                    & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                        << 0xeU) 
                                                       | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                                   ? 5U
                                                   : 6U)))))))
            : ((0x40U == (0x7fc0U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                      << 0xeU) | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                ? 7U : ((0x20U == (0x7fe0U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                               << 0xeU) 
                                              | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                         ? 8U : ((0x10U == (0x7ff0U 
                                            & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                << 0xeU) 
                                               | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                  ? 9U : ((8U == (0x7ff8U 
                                                  & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                      << 0xeU) 
                                                     | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                           ? 0xaU : 
                                          ((4U == (0x7ffcU 
                                                   & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                       << 0xeU) 
                                                      | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                            ? 0xbU : 
                                           ((2U == 
                                             (0x7ffeU 
                                              & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                  << 0xeU) 
                                                 | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base))))
                                             ? 0xcU
                                             : ((1U 
                                                 == 
                                                 (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) 
                                                   << 0xeU) 
                                                  | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base)))
                                                 ? 0xdU
                                                 : 0xfU))))))));
    vlSelfRef.FPMAC__DOT__w_add_udf = ((1U & (~ (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout))) 
                                       && ((0xfU != (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt)) 
                                           && ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt) 
                                               > (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp))));
    if (vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout) {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res 
            = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp)));
        vlSelfRef.FPMAC__DOT__w_add_ovf = (0x1fU == (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky 
            = (0x7fffU & VL_SHIFTR_III(15,15,32, (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out), 1U));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__r_shift_new_sticky 
            = (1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky) 
                     | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp 
            = ((0x1ffeU & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky)) 
               | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__r_shift_new_sticky));
    } else if ((0xfU == (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt))) {
        vlSelfRef.FPMAC__DOT__w_add_ovf = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__r_shift_new_sticky = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout = 0U;
    } else {
        vlSelfRef.FPMAC__DOT__w_add_ovf = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res 
            = (0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp) 
                        - (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout 
            = ((0x7ffeU & ((((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out) 
                             >> 1U) << (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt)) 
                           << 1U)) | (1U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp 
            = (0x1fffU & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__r_shift_new_sticky = 0U;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky = 0U;
    }
    vlSelfRef.FPMAC__DOT__stage_add__DOT__round_a = (IData)(
                                                            (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                                              >> 2U) 
                                                             & (0U 
                                                                != 
                                                                (0xbU 
                                                                 & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp)))));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_rnd_res 
        = (0x3ffU & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                      >> 3U) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__round_a)));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1 
        = (1U & (((0x3ffU & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                             >> 3U)) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__round_a)) 
                 >> 0xaU));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm 
        = ((~ (IData)(vlSelfRef.FPMAC__DOT__w_add_ovf)) 
           & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1));
    vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_cout_norm_2 
        = ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm) 
           && (1U & (((IData)(1U) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res)) 
                     >> 5U)));
    if (vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm) {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res 
            = (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1) 
                << 9U) | (0x1ffU & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_rnd_res) 
                                    >> 1U)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res 
            = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res)));
        vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag 
            = (0x1fU == (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res));
    } else {
        vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res 
            = vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_rnd_res;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res 
            = vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res;
        vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag = 0U;
    }
    vlSelfRef.o_result = ((0x8000U & (((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
                                        ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                           >> 0xfU)
                                        : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0)
                                            ? ((IData)(vlSelfRef.i_c) 
                                               >> 0xfU)
                                            : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0)
                                                ? ((IData)(vlSelfRef.i_c) 
                                                   >> 0xfU)
                                                : ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                                   >> 0xfU)))) 
                                      << 0xfU)) | (
                                                   ((((~ (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag)) 
                                                      & (0U 
                                                         == (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res)))
                                                      ? 0U
                                                      : (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res)) 
                                                    << 0xaU) 
                                                   | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag)
                                                       ? 0U
                                                       : (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res))));
}

void Vfpmac___024root___eval_triggers__ico(Vfpmac___024root* vlSelf);

bool Vfpmac___024root___eval_phase__ico(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfpmac___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vfpmac___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfpmac___024root___eval_act(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vfpmac___024root___eval_nba(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vfpmac___024root___eval_triggers__act(Vfpmac___024root* vlSelf);

bool Vfpmac___024root___eval_phase__act(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfpmac___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vfpmac___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfpmac___024root___eval_phase__nba(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfpmac___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__ico(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__nba(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__act(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpmac___024root___eval(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vfpmac___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("fpmac.sv", 4, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfpmac___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfpmac___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fpmac.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vfpmac___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fpmac.sv", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vfpmac___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vfpmac___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfpmac___024root___eval_debug_assertions(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
