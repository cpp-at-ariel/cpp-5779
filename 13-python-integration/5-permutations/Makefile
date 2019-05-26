# A generic makefile for running single-file C++ projects.
#
# AUTHOR: Erel Segal-Halevi

CXX=clang++-5.0
RM=rm -f
CPPFLAGS=-std=c++17 -O3 -ffp-contract=off -fno-expensive-optimizations

ifndef MAIN
  MAIN=./main.cpp
endif

MAINEXECUTABLE=$(subst .cpp,,$(MAIN)).exe

SOURCES=$(MAIN)

all: $(MAINEXECUTABLE)
	$(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $(MAINEXECUTABLE)

clean:
	$(RM) *.exe a.out *.class
