// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpmac.h for the primary calling header

#ifndef VERILATED_VFPMAC___024ROOT_H_
#define VERILATED_VFPMAC___024ROOT_H_  // guard

#include "verilated.h"


class Vfpmac__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpmac___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ FPMAC__DOT__w_mult_snan;
        CData/*0:0*/ FPMAC__DOT__w_mult_qnan;
        CData/*0:0*/ FPMAC__DOT__w_mult_infinity;
        CData/*0:0*/ FPMAC__DOT__w_mult_zero;
        CData/*0:0*/ FPMAC__DOT__w_mult_subnormal;
        CData/*0:0*/ FPMAC__DOT__w_mult_normal;
        CData/*0:0*/ FPMAC__DOT__w_add_ovf;
        CData/*0:0*/ FPMAC__DOT__w_add_udf;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__aSnan;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__aQnan;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__aInfinity;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__aZero;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__aSubnormal;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__aNormal;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__bSnan;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__bQnan;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__bInfinity;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__bZero;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__bSubnormal;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__bNormal;
        CData/*6:0*/ FPMAC__DOT__stage_mult__DOT__aExp;
        CData/*6:0*/ FPMAC__DOT__stage_mult__DOT__bExp;
        CData/*6:0*/ FPMAC__DOT__stage_mult__DOT__pExp;
        CData/*6:0*/ FPMAC__DOT__stage_mult__DOT__t1Exp;
        CData/*6:0*/ FPMAC__DOT__stage_mult__DOT__t2Exp;
        CData/*0:0*/ FPMAC__DOT__stage_mult__DOT__pSign;
        CData/*3:0*/ FPMAC__DOT__stage_mult__DOT__aClass__DOT__sa;
        CData/*3:0*/ FPMAC__DOT__stage_mult__DOT__bClass__DOT__sa;
        CData/*4:0*/ FPMAC__DOT__stage_add__DOT__large_exp;
        CData/*4:0*/ FPMAC__DOT__stage_add__DOT__exp_diff;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__sticky;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__mnts_res_cout;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__cond_mnts_complement;
        CData/*3:0*/ FPMAC__DOT__stage_add__DOT__renorm_shamt;
        CData/*4:0*/ FPMAC__DOT__stage_add__DOT__exp_res;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__r_shift_new_sticky;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__exp_cout_norm_1;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__round_a;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__cond_renorm_stage_1;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__cond_renorm;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__exp_ovf_flag;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT__exp_cout_norm_2;
        CData/*4:0*/ FPMAC__DOT__stage_add__DOT__renorm_exp_res;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT____VdfgExtracted_ha545ef13__0;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT____VdfgExtracted_haa0d58c1__0;
        CData/*0:0*/ FPMAC__DOT__stage_add__DOT____VdfgExtracted_h2ee2060d__0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VactContinue;
        VL_IN16(i_a,15,0);
        VL_IN16(i_b,15,0);
        VL_IN16(i_c,15,0);
        VL_OUT16(o_result,15,0);
        SData/*10:0*/ FPMAC__DOT__stage_mult__DOT__aSig;
        SData/*10:0*/ FPMAC__DOT__stage_mult__DOT__bSig;
        SData/*10:0*/ FPMAC__DOT__stage_mult__DOT__pSig;
        SData/*10:0*/ FPMAC__DOT__stage_mult__DOT__tSig;
        SData/*15:0*/ FPMAC__DOT__stage_mult__DOT__pTmp;
        SData/*9:0*/ FPMAC__DOT__stage_add__DOT__large_mnts;
        SData/*9:0*/ FPMAC__DOT__stage_add__DOT__small_mnts;
        SData/*13:0*/ FPMAC__DOT__stage_add__DOT__shifted_small_mnts;
        SData/*14:0*/ FPMAC__DOT__stage_add__DOT__mnts_adder_out;
        SData/*13:0*/ FPMAC__DOT__stage_add__DOT__mnts_res_base;
        SData/*14:0*/ FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout_unadj_sticky;
    };
    struct {
        SData/*14:0*/ FPMAC__DOT__stage_add__DOT__shifted_mnts_ulp_cout;
        SData/*12:0*/ FPMAC__DOT__stage_add__DOT__mnts_res_ulp;
        SData/*9:0*/ FPMAC__DOT__stage_add__DOT__mnts_rnd_res;
        SData/*9:0*/ FPMAC__DOT__stage_add__DOT__renorm_mnts_rnd_res;
        IData/*21:0*/ FPMAC__DOT__stage_mult__DOT__rawSignificand;
        IData/*31:0*/ FPMAC__DOT__stage_mult__DOT__aClass__DOT__i;
        IData/*31:0*/ FPMAC__DOT__stage_mult__DOT__bClass__DOT__i;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpmac__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpmac___024root(Vfpmac__Syms* symsp, const char* v__name);
    ~Vfpmac___024root();
    VL_UNCOPYABLE(Vfpmac___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
