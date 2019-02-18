CXX=clang++-5.0
CXXFLAGS=-std=c++17 --assemble -fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm 
OPTIMIZATION=-O2

ifndef MAIN
  MAIN=./main.cpp
endif

all: 
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION) $(MAIN)
