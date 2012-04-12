#!/usr/bin/make -f
########################################################################
# Main makefile for v8::convert PathFinder add-on.
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

ENABLE_ZLIB ?= 1
ifeq (,$(ENABLE_ZLIB))
  ENABLE_ZLIB := 0
endif
libv8PathFinder.LIB.OBJECTS := PathFinder.o cvv8-PathFinder.o
libv8PathFinder.DLL.OBJECTS := $(libv8PathFinder.LIB.OBJECTS)
libv8PathFinder.DLL: $(libv8PathFinder.LIB.OBJECTS)
ifeq (1,$(ENABLE_ZLIB))
  libv8PathFinder.DLL.LDFLAGS += -lz
endif
$(eval $(call ShakeNMake.CALL.RULES.LIBS,libv8PathFinder))
all: $(libv8PathFinder.LIB)
$(eval $(call ShakeNMake.CALL.RULES.DLLS,libv8PathFinder))
all: $(libv8PathFinder.DLL)



########################################################################
# shell app...
SHELL_LDFLAGS := $(LDFLAGS_V8) -L. -lv8PathFinder
SHELL_BINDINGS_HEADER := cvv8-PathFinder.hpp
SHELL_BINDINGS_FUNC := cvv8::SetupPathFinderBindings
include ../shell-common.make
