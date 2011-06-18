#!/do/not/make -f
########################################################################
# To be included by add-on app which want to build a basic shell
# from shell-skel/shell.cpp which includes the addon's bindings.
########################################################################
ifeq (,$(SHELL_BINDINGS_FUNC))
$(error Define SHELL_BINDINGS_FUNC to a function _name_ before including this file.)
endif

ifeq (,$(SHELL_BINDINGS_HEADER))
$(error Define SHELL_BINDINGS_HEADER to a header file containing the function defined in SHELL_BINDINGS_FUNC.)
endif

ifeq (1,1)
  SHELL.DIR := ../shell-skel
  shell.cpp: $(SHELL.DIR)/shell.cpp
	cp $< $@
  CLEAN_FILES += shell.cpp
  shell.BIN.OBJECTS := shell.o
  shell.BIN.LDFLAGS += $(BINS_LDFLAGS)
  $(eval $(call ShakeNMake.CALL.RULES.BINS,shell))
  shell.o: shell.cpp $(ALL_MAKEFILES)
  shell.o: CPPFLAGS+=-DSETUP_SHELL_BINDINGS=$(SHELL_BINDINGS_FUNC)
  shell.o: CPPFLAGS+=-DINCLUDE_SHELL_BINDINGS='"$(SHELL_BINDINGS_HEADER)"'
  $(shell.BIN): $(libv8bytearray.DLL)
  all: $(shell.BIN)
endif
