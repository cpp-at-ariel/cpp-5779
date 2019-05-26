#!python3

import cppyy
cppyy.include("benchmark.cpp")

for N in range(5,13+1):
	cppyy.gbl.benchmark(N)
