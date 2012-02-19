#!/usr/bin/make -f
include ../../config.make # see that file for certain configuration options.

########################################################################
# If needed, append the CPPFLAGS to point to where <v8/convert/*.hpp> can
# be found.

libv8expat.LIB.OBJECTS := ExpatJS.o
libv8expat.DLL.OBJECTS := $(libv8expat.LIB.OBJECTS)
libv8expat.DLL: $(libv8expat.LIB.OBJECTS)
libv8expat.DLL.LDFLAGS += -lexpat
$(eval $(call ShakeNMake.CALL.RULES.LIBS,libv8expat))
all: $(libv8expat.LIB)
$(eval $(call ShakeNMake.CALL.RULES.DLLS,libv8expat))
all: $(libv8expat.DLL)


########################################################################
# shell app...
SHELL_LDFLAGS := $(LDFLAGS_V8) -L. -lv8expat
SHELL_BINDINGS_HEADER := ExpatJS.h
SHELL_BINDINGS_FUNC := cvv8::expat::ExpatJS::SetupBindings
include ../shell-common.make
