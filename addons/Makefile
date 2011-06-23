#!/usr/bin/make -f
default: all


SUBDIRS := shell-skel bytearray socket time jspdo

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean-%:
		$(MAKE) -C $* clean

all: $(SUBDIRS)

clean: $(patsubst %,clean-%,$(SUBDIRS))
