#!python3

import itertools

def count_permutations(N:int)->int:
	count=0
	for p in itertools.permutations(range(1,N+1)):
		count += 1
	return count
