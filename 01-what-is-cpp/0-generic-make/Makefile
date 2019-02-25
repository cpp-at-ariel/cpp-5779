# A generic makefile for running simple C++ projects.
#
# USAGE:
#    1. Put all your non-main files in subfolder "units".
#    2. Run:         make MAIN=<path-to-cpp-file-with-main-program>.cpp
# It should compile all the cpp files in "units", link them with your main program, and run it.
#
# Based on https://stackoverflow.com/a/2481326/827927
# AUTHOR: Erel Segal-Halevi

CXX=clang++-5.0
RM=rm -f
CPPFLAGS=-std=c++17 
LDFLAGS=
LDLIBS=

ifndef MAIN
  MAIN=./main.cpp
endif

MAINEXECUTABLE=$(subst .cxx,,$(MAIN)).exe

SOURCES=$(shell ls units/*.cpp) $(MAIN)
OBJECTS=$(subst .c%,.o,$(SOURCES))

all: $(MAINEXECUTABLE)
	$(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $(MAINEXECUTABLE)

depend: .depend

.depend: $(SOURCES)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJECTS)
	$(RM) *.o
	$(RM) *.exe

distclean: clean
	$(RM) *~ .depend

include .depend
