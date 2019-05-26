#!python3

from itertools import  permutations
from collections import defaultdict

def shapley_values(num_of_players:int, map_subset_to_cost:dict):
	players = range(1,num_of_players+1)
	print("players: ", players, flush=True)
	print("costs: ", map_subset_to_cost, flush=True)
	map_player_to_sum_of_marginal_costs = defaultdict(float)
	print("permutations: ", flush=True)
	num_permutations = 0;
	for players in permutations(range(1,num_of_players+1)):
		print(" * ", players)
		# calculate marginal costs for a specific permutation:
		current_cost = 0
		current_subset = set()
		for player in players:   # loop over the players in the order given by the current permutation
			current_subset.add(player)
			new_cost = map_subset_to_cost[frozenset(current_subset)]
			marginal_cost = new_cost - current_cost
			map_player_to_sum_of_marginal_costs[player] += marginal_cost
			current_cost = new_cost
		num_permutations += 1

	for player,cost in map_player_to_sum_of_marginal_costs.items():
		map_player_to_sum_of_marginal_costs[player] = cost/num_permutations

	return map_player_to_sum_of_marginal_costs

if __name__=="__main__":
	map_subset_to_cost = {
		frozenset(): 0,
		frozenset({1}): 1000,
		frozenset({2}): 2000,
		frozenset({1,2}): 2000,
		frozenset({3}): 3000,
		frozenset({1,3}): 3000,
		frozenset({2,3}): 3000,
		frozenset({1,2,3}): 3000,
	}
	sv = shapley_values(3, map_subset_to_cost)
	print("Shapley values: ", sv, flush=True)


