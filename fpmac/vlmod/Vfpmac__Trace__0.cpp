// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfpmac__Syms.h"


void Vfpmac___024root__trace_chg_0_sub_0(Vfpmac___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vfpmac___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_chg_0\n"); );
    // Init
    Vfpmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpmac___024root*>(voidSelf);
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vfpmac___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vfpmac___024root__trace_chg_0_sub_0(Vfpmac___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp),16);
        bufp->chgBit(oldp+1,(vlSelfRef.FPMAC__DOT__w_mult_snan));
        bufp->chgBit(oldp+2,(vlSelfRef.FPMAC__DOT__w_mult_qnan));
        bufp->chgBit(oldp+3,(vlSelfRef.FPMAC__DOT__w_mult_infinity));
        bufp->chgBit(oldp+4,(vlSelfRef.FPMAC__DOT__w_mult_zero));
        bufp->chgBit(oldp+5,(vlSelfRef.FPMAC__DOT__w_mult_subnormal));
        bufp->chgBit(oldp+6,(vlSelfRef.FPMAC__DOT__w_mult_normal));
        bufp->chgBit(oldp+7,(vlSelfRef.FPMAC__DOT__w_add_ovf));
        bufp->chgBit(oldp+8,(vlSelfRef.FPMAC__DOT__w_add_udf));
        bufp->chgBit(oldp+9,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                    >> 0xfU))));
        bufp->chgCData(oldp+10,((0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                          >> 0xaU))),5);
        bufp->chgSData(oldp+11,((0x3ffU & (IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp))),10);
        bufp->chgCData(oldp+12,(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_exp),5);
        bufp->chgSData(oldp+13,(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts),10);
        bufp->chgSData(oldp+14,(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts),10);
        bufp->chgSData(oldp+15,((0x400U | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts))),11);
        bufp->chgSData(oldp+16,((0x400U | (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts))),11);
        bufp->chgCData(oldp+17,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_diff),5);
        bufp->chgSData(oldp+18,((0x1000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__small_mnts) 
                                            << 2U))),13);
        bufp->chgBit(oldp+19,(vlSelfRef.FPMAC__DOT__stage_add__DOT__sticky));
        bufp->chgSData(oldp+20,(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_small_mnts),14);
        bufp->chgSData(oldp+21,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_adder_out),15);
        bufp->chgSData(oldp+22,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_base),14);
        bufp->chgBit(oldp+23,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_cout));
        bufp->chgBit(oldp+24,(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_mnts_complement));
        bufp->chgSData(oldp+25,((0x2000U | ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__large_mnts) 
                                            << 3U))),14);
        bufp->chgCData(oldp+26,(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_shamt),4);
        bufp->chgCData(oldp+27,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_res),5);
        bufp->chgSData(oldp+28,(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky),15);
        bufp->chgSData(oldp+29,(vlSelfRef.FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout),15);
        bufp->chgSData(oldp+30,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp),13);
        bufp->chgBit(oldp+31,(vlSelfRef.FPMAC__DOT__stage_add__DOT__r_shift_new_sticky));
        bufp->chgBit(oldp+32,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_cout_norm_1));
        bufp->chgBit(oldp+33,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                     >> 3U))));
        bufp->chgBit(oldp+34,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                     >> 2U))));
        bufp->chgBit(oldp+35,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp) 
                                     >> 1U))));
        bufp->chgBit(oldp+36,((1U & (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_res_ulp))));
        bufp->chgBit(oldp+37,(vlSelfRef.FPMAC__DOT__stage_add__DOT__round_a));
        bufp->chgBit(oldp+38,(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1));
        bufp->chgBit(oldp+39,(vlSelfRef.FPMAC__DOT__stage_add__DOT__cond_renorm));
        bufp->chgSData(oldp+40,(vlSelfRef.FPMAC__DOT__stage_add__DOT__mnts_rnd_res),10);
        bufp->chgBit(oldp+41,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag));
        bufp->chgBit(oldp+42,(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_cout_norm_2));
        bufp->chgCData(oldp+43,(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res),5);
        bufp->chgSData(oldp+44,(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res),10);
        bufp->chgSData(oldp+45,(((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag)
                                  ? 0U : (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res))),10);
        bufp->chgCData(oldp+46,((((~ (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__exp_ovf_flag)) 
                                  & (0U == (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res)))
                                  ? 0U : (IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT__renorm_exp_res))),5);
        bufp->chgBit(oldp+47,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSnan));
        bufp->chgBit(oldp+48,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aQnan));
        bufp->chgBit(oldp+49,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aInfinity));
        bufp->chgBit(oldp+50,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aZero));
        bufp->chgBit(oldp+51,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSubnormal));
        bufp->chgBit(oldp+52,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aNormal));
        bufp->chgBit(oldp+53,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSnan));
        bufp->chgBit(oldp+54,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bQnan));
        bufp->chgBit(oldp+55,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bInfinity));
        bufp->chgBit(oldp+56,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bZero));
        bufp->chgBit(oldp+57,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSubnormal));
        bufp->chgBit(oldp+58,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bNormal));
        bufp->chgCData(oldp+59,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aExp),7);
        bufp->chgCData(oldp+60,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bExp),7);
        bufp->chgCData(oldp+61,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pExp),7);
        bufp->chgCData(oldp+62,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t1Exp),7);
        bufp->chgCData(oldp+63,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__t2Exp),7);
        bufp->chgSData(oldp+64,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aSig),11);
        bufp->chgSData(oldp+65,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bSig),11);
        bufp->chgSData(oldp+66,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSig),11);
        bufp->chgSData(oldp+67,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__tSig),11);
        bufp->chgIData(oldp+68,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__rawSignificand),22);
        bufp->chgBit(oldp+69,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pSign));
        bufp->chgCData(oldp+70,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa),4);
        bufp->chgIData(oldp+71,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__aClass__DOT__i),32);
        bufp->chgCData(oldp+72,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa),4);
        bufp->chgIData(oldp+73,(vlSelfRef.FPMAC__DOT__stage_mult__DOT__bClass__DOT__i),32);
    }
    bufp->chgSData(oldp+74,(vlSelfRef.i_a),16);
    bufp->chgSData(oldp+75,(vlSelfRef.i_b),16);
    bufp->chgSData(oldp+76,(vlSelfRef.i_c),16);
    bufp->chgSData(oldp+77,(vlSelfRef.o_result),16);
    bufp->chgBit(oldp+78,((1U & ((IData)(vlSelfRef.i_c) 
                                 >> 0xfU))));
    bufp->chgCData(oldp+79,((0x1fU & ((IData)(vlSelfRef.i_c) 
                                      >> 0xaU))),5);
    bufp->chgSData(oldp+80,((0x3ffU & (IData)(vlSelfRef.i_c))),10);
    bufp->chgBit(oldp+81,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
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
    bufp->chgBit(oldp+82,((1U & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
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
    bufp->chgCData(oldp+83,((0x1fU & ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0)
                                       ? ((IData)(vlSelfRef.i_c) 
                                          >> 0xaU) : 
                                      ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0)
                                        ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                           >> 0xaU)
                                        : ((IData)(vlSelfRef.FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0)
                                            ? ((IData)(vlSelfRef.FPMAC__DOT__stage_mult__DOT__pTmp) 
                                               >> 0xaU)
                                            : ((IData)(vlSelfRef.i_c) 
                                               >> 0xaU)))))),5);
    bufp->chgBit(oldp+84,((0x1fU == (0x1fU & ((IData)(vlSelfRef.i_a) 
                                              >> 0xaU)))));
    bufp->chgBit(oldp+85,((1U & (~ (IData)((0U != (0x1fU 
                                                   & ((IData)(vlSelfRef.i_a) 
                                                      >> 0xaU))))))));
    bufp->chgBit(oldp+86,((1U & (~ (IData)((0U != (0x3ffU 
                                                   & (IData)(vlSelfRef.i_a))))))));
    bufp->chgBit(oldp+87,((0x1fU == (0x1fU & ((IData)(vlSelfRef.i_b) 
                                              >> 0xaU)))));
    bufp->chgBit(oldp+88,((1U & (~ (IData)((0U != (0x1fU 
                                                   & ((IData)(vlSelfRef.i_b) 
                                                      >> 0xaU))))))));
    bufp->chgBit(oldp+89,((1U & (~ (IData)((0U != (0x3ffU 
                                                   & (IData)(vlSelfRef.i_b))))))));
}

void Vfpmac___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root__trace_cleanup\n"); );
    // Init
    Vfpmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpmac___024root*>(voidSelf);
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
