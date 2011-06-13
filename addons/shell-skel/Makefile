#!/usr/bin/make -f
########################################################################
########################################################################
include ../../config.make # see that file for certain configuration options.

########################################################################
# Binaries...
BINS_LDFLAGS += $(LDFLAGS_V8)
shell.BIN.OBJECTS := shell.o
shell.BIN.LDFLAGS += $(BINS_LDFLAGS)
shell.o: CPPFLAGS+=-DCPDO_ENABLE_SQLITE3=$(CPDO_ENABLE_SQLITE3)
shell.o: CPPFLAGS+=-DCPDO_ENABLE_MYSQL5=$(CPDO_ENABLE_MYSQL5)
$(eval $(call ShakeNMake.CALL.RULES.BINS,shell))
all: $(shell.BIN)
