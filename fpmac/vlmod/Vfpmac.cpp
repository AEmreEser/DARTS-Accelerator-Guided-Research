// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfpmac__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vfpmac::Vfpmac(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfpmac__Syms(contextp(), _vcname__, this)}
    , i_a{vlSymsp->TOP.i_a}
    , i_b{vlSymsp->TOP.i_b}
    , i_c{vlSymsp->TOP.i_c}
    , o_result{vlSymsp->TOP.o_result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vfpmac::Vfpmac(const char* _vcname__)
    : Vfpmac(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfpmac::~Vfpmac() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfpmac___024root___eval_debug_assertions(Vfpmac___024root* vlSelf);
#endif  // VL_DEBUG
void Vfpmac___024root___eval_static(Vfpmac___024root* vlSelf);
void Vfpmac___024root___eval_initial(Vfpmac___024root* vlSelf);
void Vfpmac___024root___eval_settle(Vfpmac___024root* vlSelf);
void Vfpmac___024root___eval(Vfpmac___024root* vlSelf);

void Vfpmac::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfpmac::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfpmac___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfpmac___024root___eval_static(&(vlSymsp->TOP));
        Vfpmac___024root___eval_initial(&(vlSymsp->TOP));
        Vfpmac___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfpmac___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfpmac::eventsPending() { return false; }

uint64_t Vfpmac::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfpmac::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfpmac___024root___eval_final(Vfpmac___024root* vlSelf);

VL_ATTR_COLD void Vfpmac::final() {
    Vfpmac___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfpmac::hierName() const { return vlSymsp->name(); }
const char* Vfpmac::modelName() const { return "Vfpmac"; }
unsigned Vfpmac::threads() const { return 1; }
void Vfpmac::prepareClone() const { contextp()->prepareClone(); }
void Vfpmac::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vfpmac::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vfpmac___024root__trace_decl_types(VerilatedVcd* tracep);

void Vfpmac___024root__trace_init_top(Vfpmac___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfpmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vfpmac___024root*>(voidSelf);
    Vfpmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vfpmac___024root__trace_decl_types(tracep);
    Vfpmac___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vfpmac___024root__trace_register(Vfpmac___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vfpmac::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfpmac::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vfpmac___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
