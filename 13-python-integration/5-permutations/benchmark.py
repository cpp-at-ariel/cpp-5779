#!python3

import itertools
import time

def benchmark(N:int)->int:
	count=0
	print ("Permutations of 1..{}:".format(N), flush=True)
	start = time.clock()
	for p in itertools.permutations(range(1,N)):
		count += 1
	end = time.clock()
	duration_in_seconds = end-start
	print("  {} permutations calculated in {} seconds".format(count, duration_in_seconds), flush=True)


for N in range(5,13+1):
	benchmark(N)
