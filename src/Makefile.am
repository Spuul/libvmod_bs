AM_CPPFLAGS = -I$(VARNISHSRC)/include -I$(VARNISHSRC)
AM_LDFLAGS = -lbeanstalk
LDFLAGS = -lbeanstalk

vmoddir = $(VMODDIR)
vmod_LTLIBRARIES = libvmod_bs.la

libvmod_bs_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_bs_la_SOURCES = \
	vcc_if.c \
	vcc_if.h \
	vmod_bs.c

vcc_if.c vcc_if.h: $(VARNISHSRC)/lib/libvmod_std/vmod.py $(top_srcdir)/src/vmod_bs.vcc
	@PYTHON@ $(VARNISHSRC)/lib/libvmod_std/vmod.py $(top_srcdir)/src/vmod_bs.vcc

VMOD_TESTS = tests/*.vtc
.PHONY: $(VMOD_TESTS)

tests/*.vtc:
	$(VARNISHSRC)/bin/varnishtest/varnishtest -Dvarnishd=$(VARNISHSRC)/bin/varnishd/varnishd -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_bs.vcc \
	$(VMOD_TESTS)

CLEANFILES = $(builddir)/vcc_if.c $(builddir)/vcc_if.h
