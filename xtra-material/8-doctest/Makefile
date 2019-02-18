# A generic makefile for running single-file C++ projects.
#
# AUTHOR: Erel Segal-Halevi

CXX=clang++-5.0
RM=rm -f
CPPFLAGS=-std=c++17 

MAIN=./factorial_test

MAINEXECUTABLE=$(subst .cpp,,$(MAIN)).exe

SOURCES=$(MAIN) $(subst _test,,$(MAIN))

all: $(MAINEXECUTABLE)
	$(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $(MAINEXECUTABLE)

clean:
	$(RM) *.exe a.out *.class
