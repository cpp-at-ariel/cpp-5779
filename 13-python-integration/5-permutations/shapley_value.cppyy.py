#!python3


import cppyy
cppyy.include("shapley_value.cpp")

def map_subset_to_cost_f(subset):
	return 1000*max(subset)


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
	sv = cppyy.gbl.shapley_values_f(3, map_subset_to_cost_f)
	print("Shapley values: ", sv, flush=True)

