
ifndef MAIN
  MAIN=./main.cpp
endif

CXX=clang++-5.0
STANDARD=-std=c++17

# For assemble:
CXXFLAGS=--assemble -fno-asynchronous-unwind-tables -fno-dwarf2-cfi-asm 

# For preprocess:
#CXXFLAGS=--preprocess -o $(subst .cpp,.cxx,$(MAIN))

all: 
	$(CXX) $(STANDARD) $(CXXFLAGS) $(MAIN)
