#!/usr/bin/make -f
default: all

SUBDIRS := bytearray curl expat glob \
	jspdo readline shell-skel socket \
	sprintf time whio 

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean-%:
		$(MAKE) -C $* clean

all: $(SUBDIRS)

clean: $(patsubst %,clean-%,$(SUBDIRS))
