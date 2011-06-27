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

ifeq (,$(SHELL_LDFLAGS))
$(warning You have not set SHELL_LDFLAGS, which means we are not linking the shell to the add-on code.)
endif

ifeq (1,1)
  SHELL.DIR ?= ../shell-skel
#  shell.cpp: $(SHELL.DIR)/shell.cpp
#	cp $< $@
  SHELL.LOCAL := _shell
  $(SHELL.LOCAL).cpp: $(SHELL.DIR)/shell.cpp
	cp $< $@
  $(SHELL.DIR)/shell.cpp:
  $(SHELL.LOCAL).o: $(SHELL.LOCAL).cpp
  shell.BIN.OBJECTS := $(SHELL.LOCAL).o
  shell.BIN.LDFLAGS := $(LDFLAGS_V8) $(SHELL_LDFLAGS)
  $(eval $(call ShakeNMake.CALL.RULES.BINS,shell))
  $(SHELL.LOCAL).o: CPPFLAGS+=-DSETUP_SHELL_BINDINGS=$(SHELL_BINDINGS_FUNC)
  $(SHELL.LOCAL).o: CPPFLAGS+=-DINCLUDE_SHELL_BINDINGS='"$(SHELL_BINDINGS_HEADER)"'
  $(SHELL.LOCAL).o: $(ALL_MAKEFILES)
  $(shell.BIN): $(SHELL_DEPS)
  CLEAN_FILES += $(SHELL.LOCAL).cpp $(SHELL.LOCAL).cpp $(shell.BIN)
  all: $(shell.BIN)
endif
