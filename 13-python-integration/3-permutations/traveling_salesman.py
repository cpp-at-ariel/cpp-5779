#!python3

import itertools
import time
import math


def find_shortest_path(distances:list)->list:
	num_of_towns = len(distances)
	shortest_distance_so_far = math.inf
	shortest_path_so_far = None
	for path in itertools.permutations(range(0,num_of_towns)):
		distance = 0
		for i in range(1,len(path)):
			prev_town = path[i-1]
			cur_town = path[i]
			cur_distance = distances[prev_town][cur_town]
			distance += cur_distance
		if distance < shortest_distance_so_far:
			shortest_distance_so_far = distance
			shortest_path_so_far = list(path)

	# show the shortest path
	path = shortest_path_so_far
	result=str(path[0])
	for i in range(1,len(path)):
		prev_town = path[i-1]
		cur_town = path[i]
		cur_distance = distances[prev_town][cur_town]
		result += " --" + str(cur_distance) + "--> " + str(cur_town)
	result += ": == "+str(shortest_distance_so_far)
	return result


if __name__=="__main__":
		
	distances = [
		[0,2,3],
		[4,0,6],
		[7,8,0]
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
	print(find_shortest_path(distances), flush=True)
