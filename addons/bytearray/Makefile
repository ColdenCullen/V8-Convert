#!/usr/bin/make -f
########################################################################
# Main makefile for jspdo.
#
# Requires GNU Make 3.81+
#
# This file is pre-configured for compling directly from the
# v8::convert source tree in my own personal dev environments. See the
# comments in the various sections below for what might need to be
# tweaked (not too much, at least for Linux boxes).
#
# Requirements:
#
# - Google v8 headers + libs.
#
# - v8::convert: http://code.google.com/p/v8-juice/wiki/V8Convert
#   (it's a header-only library, so required to special installation)
#
########################################################################
include ../../config.make # see that file for certain configuration options.

########################################################################
# If needed, append the CPPFLAGS to point to where <v8/convert/*.hpp> can
# be found.


########################################################################
# Try to find sqlite3... If we find the header, we assume the library
# is in some default location.
#
# FIXME: port in the whiki makefile code which allows us to drop in
# our own sqlite3.c (from the sqlite3 amalgamation build).

libv8bytearray.LIB.OBJECTS := bytearray.o
libv8bytearray.DLL.LDFLAGS += $(LDFLAGS_DRIVERS)
libv8bytearray.DLL.OBJECTS := $(libv8bytearray.LIB.OBJECTS)
libv8bytearray.DLL: $(libv8bytearray.LIB.OBJECTS)
#$(eval $(call ShakeNMake.CALL.RULES.LIBS,libv8bytearray))
#all: $(libv8bytearray.LIB)
$(eval $(call ShakeNMake.CALL.RULES.DLLS,libv8bytearray))
all: $(libv8bytearray.DLL)



########################################################################
# Binaries...
LDFLAGS_JSPDO := -L. -lv8bytearray
BINS_LDFLAGS += $(LDFLAGS_V8) $(LDFLAGS_JSPDO) #$(LDFLAGS_DRIVERS)

ifeq (1,1)
  SHELL.DIR := ../shell-skel
  shell.cpp: $(SHELL.DIR)/shell.cpp
	cp $< $@
  CLEAN_FILES += shell.cpp
  shell.BIN.OBJECTS := shell.o
  shell.BIN.LDFLAGS += $(BINS_LDFLAGS)
  $(eval $(call ShakeNMake.CALL.RULES.BINS,shell))
  shell.o: shell.cpp $(ALL_MAKEFILES)
  shell.o: CPPFLAGS+=-DSETUP_SHELL_BINDINGS=SetupJSByteArray
  shell.o: CPPFLAGS+=-DINCLUDE_SHELL_BINDINGS='"bytearray.hpp"'
  $(shell.BIN): $(libv8bytearray.DLL)
  all: $(shell.BIN)
endif

.PHONY: amal-cpp
amal-cpp: cpdo_amalgamation.o
	gcc -c -Iinclude cpdo_amalgamation.cpp \
		-Wall -Werror -pedantic -ansi \
		-DCPDO_ENABLE_SQLITE3=$(CPDO_ENABLE_SQLITE3) \
		-DCPDO_ENABLE_MYSQL5=$(CPDO_ENABLE_MYSQL5) \
		$(CFLAGS_MYSQL5)

EXT.JS := jspdo-init.js
EXT.CPP := jspdo-init.cpp
$(EXT.JS):

js2c: js2c.o
CLEAN_FILES += js2c
$(EXT.CPP): js2c $(EXT.JS) $(ALL_MAKEFILES)
	./js2c jspdoInitCode < $(EXT.JS) > $@
jspdo.o: $(EXT.CPP)
