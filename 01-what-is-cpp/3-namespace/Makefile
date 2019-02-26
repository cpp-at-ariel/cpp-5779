#!make -f
CXX=clang++-5.0
CXXFLAGS=-std=c++17 

ifndef MAIN
  MAIN=./namespace.cpp
endif

all: 
	$(CXX) $(CXXFLAGS) $(MAIN)
	./a.out
