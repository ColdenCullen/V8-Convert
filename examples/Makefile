#!/usr/bin/make -f
########################################################################
# Main makefile for v8-convert test/demo code.
########################################################################
TOP_DIR := ../
include $(TOP_DIR)/config.make # see that file for certain configuration options.

ConvertDemo.o: ConvertDemo.cpp
SHELL.DIR := $(TOP_DIR)/addons/shell-skel
ifeq (1,1)
  demo.BIN.OBJECTS := demo.o ConvertDemo.o
  demo.BIN.LDFLAGS := $(LDFLAGS_V8)
  $(eval $(call ShakeNMake.EVAL.RULES.BIN,demo))
  all: $(demo.BIN)
  SHELL.OBJECTS := ConvertDemo.o
  SHELL_BINDINGS_HEADER := ConvertDemo.hpp
  SHELL_BINDINGS_FUNC := BoundNative::SetupBindings
else
  SHELL.NAME := demo2
  SHELL.OBJECTS := demo2.o
  SHELL_BINDINGS_HEADER := demo2.hpp
  SHELL_BINDINGS_FUNC := ::SetupCvv8DemoBindings
endif

########################################################################
# shell app...
include ../addons/shell-common.make

ifneq (,$(filter-out demo2,$(SHELL_LDFLAGS)))
  $(SHELL.LOCAL.O): demo2.o
endif
