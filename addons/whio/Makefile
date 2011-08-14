#!/usr/bin/make -f
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
bytearray.o socket.o: bytearray.cpp

whio_amalgamation.c: CFLAGS+=-std=c89
whio_amalgamation.c: CPPFLAGS+=-DWHIO_CONFIG_ENABLE_ZLIB=1
#whio_amalgamation.c: CPPFLAGS+=-DWHIO_CONFIG_USE_FCNTL=1
libwhio_v8.LIB.OBJECTS := whio_amalgamation.o whio_amalgamation_cpp.o cvv8-whio.o bytearray.o
libwhio_v8.DLL.LDFLAGS += -lz
libwhio_v8.DLL.OBJECTS := $(libwhio_v8.LIB.OBJECTS)
libwhio_v8.DLL: $(libwhio_v8.LIB.OBJECTS)
$(eval $(call ShakeNMake.CALL.RULES.LIBS,libwhio_v8))
all: $(libwhio_v8.LIB)
$(eval $(call ShakeNMake.CALL.RULES.DLLS,libwhio_v8))
all: $(libwhio_v8.DLL)


########################################################################
# shell app...
#SHELL.NAME := shell-whio
SHELL_LDFLAGS := -L. -lwhio_v8
SHELL_BINDINGS_HEADER := cvv8-whio.hpp
SHELL_BINDINGS_FUNC := cvv8::io::SetupBindings
include ../shell-common.make
