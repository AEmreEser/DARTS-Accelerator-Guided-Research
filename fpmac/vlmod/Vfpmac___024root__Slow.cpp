// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpmac.h for the primary calling header

#include "Vfpmac__pch.h"
#include "Vfpmac__Syms.h"
#include "Vfpmac___024root.h"

void Vfpmac___024root___ctor_var_reset(Vfpmac___024root* vlSelf);

Vfpmac___024root::Vfpmac___024root(Vfpmac__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfpmac___024root___ctor_var_reset(this);
}

void Vfpmac___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfpmac___024root::~Vfpmac___024root() {
}
