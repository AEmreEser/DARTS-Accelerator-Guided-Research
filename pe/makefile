TOP:=pe.sv 
VERILOG_DIR:=.
INCLUDE_DIR:=../fpmac
VERILATOR_DIR:=vlmod
TB_DIR:=tb
TB_FILE:=tb_$(basename $(TOP)).cpp

TRACE_DIR:=traces
TRACE_FILE?=dump.vcd
HART?=4
s?=10
t?=20
runargs:=
# pass any argument to v to enable verbose output
# pass any argument to r to enable random input generation

ifneq ($(strip $(v)),)
runargs +=-v
endif

ifneq ($(strip $(r)),)
runargs +=-r 
endif

.PHONY: release debug all clean sbtclean vlclean run

run: all
	./$(VERILATOR_DIR)/V$(basename $(TOP)) -s$(s) -t$(t) -b $(runargs)

all:
	verilator --cc $(VERILOG_DIR)/$(TOP)  --Mdir $(VERILATOR_DIR) --MMD --trace --exe $(TB_DIR)/$(TB_FILE) --Wno-fatal -I$(INCLUDE_DIR)
	@make -C $(VERILATOR_DIR) -j$(HART) -f V$(basename $(TOP)).mk 
# MMD: creates a dependency file which prevents a rerun if the input verilog files did not change

show: run $(TRACE_DIR)/$(TRACE_FILE)
	gtkwave $(TRACE_DIR)/$(TRACE_FILE)

vlclean:
	-rm -rf $(VERILATOR_DIR)

clean: vlclean
