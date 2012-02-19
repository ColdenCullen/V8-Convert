#!/usr/bin/make -f
########################################################################
# Main makefile for v8::convert ByteArray code.
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

BA.DIR := ../bytearray
$(BA.DIR)/bytearray.hpp $(BA.DIR)/bytearray.cpp:
bytearray.hpp: $(BA.DIR)/bytearray.hpp 
	cp $(BA.DIR)/$@ .
bytearray.cpp: $(BA.DIR)/bytearray.cpp bytearray.hpp
	cp $(BA.DIR)/$@ .
bytearray.o: bytearray.cpp
CLEAN_FILES += bytearray.cpp bytearray.hpp


THE_OBJS := CurlJS.o bytearray.o
libv8curl.LIB.OBJECTS := $(THE_OBJS)
libv8curl.DLL.OBJECTS := $(libv8curl.LIB.OBJECTS)
libv8curl.DLL: $(libv8curl.LIB.OBJECTS)
libv8curl.DLL.LDFLAGS += -lcurl
$(eval $(call ShakeNMake.CALL.RULES.LIBS,libv8curl))
all: $(libv8curl.LIB)
$(eval $(call ShakeNMake.CALL.RULES.DLLS,libv8curl))
all: $(libv8curl.DLL)



########################################################################
# shell app...
shell: $(THE_OBJS)
SHELL_LDFLAGS := $(LDFLAGS_V8) $(THE_OBJS) -lcurl
SHELL_BINDINGS_HEADER := CurlJS.h
SHELL_BINDINGS_FUNC := cvv8::curl::CurlJS::SetupBindings
include ../shell-common.make
