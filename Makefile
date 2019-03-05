#!make -f
# A makefile for building pdf files from the text (odt files) and slides (odp files).
# Author: Erel Segal-Halevi
# Since: 2019-02


SOURCES=$(shell find . -name '*.od*')
TARGETS=$(subst .odp,.pdf,$(subst .odt,.pdf,$(SOURCES)))

all: $(TARGETS)
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
