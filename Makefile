#!/usr/bin/make -f
########################################################################
# Main makefile for v8-convert.
#
# Important targets for users not hacking this source tree:
#
#  all: do everything
#  amal: build the amalgamation build
#  run: run tests (it's not called 'test' because we have a binary with
#       that name)
########################################################################
include config.make # see that file for certain configuration options.

TMPL_GENERATOR_COUNT := 10# max number of arguments generated template specializations can handle
TYPELIST_LENGTH := 15# max number of args for Signature<T(...)> typelist
INCDIR_DETAIL := $(TOP_INCDIR)/cvv8/detail
sig_gen_h := $(INCDIR_DETAIL)/signature_generated.hpp
invo_gen_h := $(INCDIR_DETAIL)/invocable_generated.hpp
conv_gen_h := $(INCDIR_DETAIL)/convert_generated.hpp
TMPL_GENERATOR := $(TOP_SRCDIR_REL)/createForwarders.sh
MAKEFILE_DEPS_LIST = $(filter-out $(ShakeNMake.CISH_DEPS_FILE),$(MAKEFILE_LIST))
createSignatureTypeList.sh:
$(sig_gen_h): $(TMPL_GENERATOR) createSignatureTypeList.sh $(MAKEFILE_DEPS_LIST)
	@echo "Creating $@ for typelists taking up to $(TYPELIST_LENGTH) arguments and" \
		"function/method signatures taking 1 to $(TMPL_GENERATOR_COUNT) arguments..."; \
	{ \
		echo "/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */"; \
		echo "#if !defined(DOXYGEN)"; \
		bash ./createSignatureTypeList.sh 0 $(TYPELIST_LENGTH); \
		i=1; while [ $$i -le $(TMPL_GENERATOR_COUNT) ]; do \
		bash $(TMPL_GENERATOR) $$i FunctionSignature MethodSignature ConstMethodSignature  || exit $$?; \
		i=$$((i + 1)); \
		done; \
		echo "#endif // if !defined(DOXYGEN)"; \
	} > $@

gen: $(sig_gen_h)
all: $(sig_gen_h)
$(invo_gen_h): $(TMPL_GENERATOR) $(MAKEFILE_DEPS_LIST)
	@echo "Creating $@ for templates taking 1 to $(TMPL_GENERATOR_COUNT) arguments..."; \
	{ \
		echo "/* AUTO-GENERATED CODE! EDIT AT YOUR OWN RISK! */"; \
		echo "#if !defined(DOXYGEN)"; \
		i=1; while [ $$i -le $(TMPL_GENERATOR_COUNT) ]; do \
			bash $(TMPL_GENERATOR) $$i \
				FunctionForwarder \
				MethodForwarder \
				CallForwarder \
				CtorForwarder \
			|| exit $$?; \
			i=$$((i + 1)); \
		done; \
		echo "#endif // if !defined(DOXYGEN)"; \
	} > $@;
gen: $(invo_gen_h)
all: $(invo_gen_h)

ifeq (1,0)
ConvertDemo.o: ConvertDemo.cpp
demo.BIN.OBJECTS := demo.o ConvertDemo.o
demo.BIN.LDFLAGS := $(LDFLAGS_V8)
$(eval $(call ShakeNMake.EVAL.RULES.BIN,demo))
demo.o: $(sig_gen_h)
all: $(demo.BIN)
endif

########################################################################
# shell app...
SHELL.DIR := addons/shell-skel
SHELL_LDFLAGS := demo2.o
SHELL_BINDINGS_HEADER := demo2.hpp
SHELL_BINDINGS_FUNC := ::SetupCvv8DemoBindings
include addons/shell-common.make
$(SHELL.LOCAL.O): demo2.o
