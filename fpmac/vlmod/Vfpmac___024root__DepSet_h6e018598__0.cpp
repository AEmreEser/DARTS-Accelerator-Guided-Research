// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpmac.h for the primary calling header

#include "Vfpmac__pch.h"
#include "Vfpmac__Syms.h"
#include "Vfpmac___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__ico(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpmac___024root___eval_triggers__ico(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpmac___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpmac___024root___dump_triggers__act(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpmac___024root___eval_triggers__act(Vfpmac___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpmac___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpmac___024root___dump_triggers__act(vlSelf);
    }
#endif
}
