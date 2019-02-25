#!make -f
# A makefile for building pdf files from the text (odt files) and slides (odp files).
# Author: Erel Segal-Halevi
# Since: 2019-02

MAKEPDF=libreoffice --headless --convert-to pdf

SOURCES=$(shell find . -name '*.od*')
TARGETS=$(subst .odp,.pdf,$(subst .odt,.pdf,$(SOURCES)))

all: $(TARGETS)
	#

#
#TARGETS: $(TARGETS)
#

%.pdf: %.odt
	#
	$(MAKEPDF) $< --outdir $(@D)
	git add $@

%.pdf: %.odp
	#
	$(MAKEPDF) $< --outdir $(@D)
	git add $@

clean:
	rm -f *.pdf
