#!python3

import cppyy
cppyy.include("benchmark.cpp")

for N in range(5,14):
	cppyy.gbl.benchmark(N)
