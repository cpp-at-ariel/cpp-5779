#!python3

import time

import traveling_salesman

use_cpp = True

if use_cpp:
	print("Using C++ implementation")
	import cppyy
	cppyy.include("traveling_salesman.cpp")
	find_shortest_path = cppyy.gbl.find_shortest_path
else:
	print("Using Python implementation")
	find_shortest_path = traveling_salesman.find_shortest_path

distances = [
	[1,2,3],
	[4,5,6],
	[7,8,9]
]	
print(find_shortest_path(distances), flush=True)


distances = [
	[1,0,3,4,5,6,7,8,9,10,11],
	[1,2,3,4,5,6,7,0,9,10,11],
	[1,2,3,0,5,6,7,8,9,10,11],
	[1,2,0,4,5,6,7,8,9,10,11],
	[1,2,3,4,5,6,7,8,0,10,11],
	[1,2,3,4,5,0,7,8,9,10,11],
	[1,2,3,4,5,6,7,8,9,0,11],
	[1,2,3,4,0,6,7,8,9,10,11],
	[0,2,3,4,5,6,7,8,9,10,11],	
	[1,2,3,4,5,6,7,8,0,10,11],	
	[1,2,3,4,5,6,7,8,2,8,11],	
]
start = time.clock()
print(find_shortest_path(distances), flush=True)
end = time.clock()
duration_in_seconds = end-start
print("Shortest path calculated in {} seconds".format(duration_in_seconds), flush=True)
