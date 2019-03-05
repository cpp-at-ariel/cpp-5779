#!make -f
# A makefile for building pdf files from the text (odt files) and slides (odp files).
# Author: Erel Segal-Halevi
# Since: 2019-02

SOURCES_ODP=$(shell find . -name '*.odp')
TARGETS_ODP=$(subst .odp,.pdf,$(SOURCES_ODP))
SOURCES_ODT=$(shell find . -name '*.odt')
TARGETS_ODT=$(subst .odt,.pdf,$(SOURCES_ODT))

all: $(TARGETS_ODP) $(TARGETS_ODT)
	#
	git commit -m "update pdf files"
	git push


%.pdf: %.odt
	#
	libreoffice --headless --convert-to pdf $< --outdir $(@D)
	git add $@
	git add $<

%.pdf: %.odp
	#
	libreoffice --headless --convert-to pdf $< --outdir $(@D)
	git add $@
	git add $<

clean:
	rm -f *.pdf
