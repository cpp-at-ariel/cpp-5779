/**
 * Shapley value
 * Demonstrates "next_permutation" and "iota".
 */

#include "output_containers.hpp"
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>

using namespace std;


template<class Func>
map<int,double> shapley_values_f(int num_of_players, Func map_subset_to_cost)  {
	vector<int> players(num_of_players);
	iota(players.begin(), players.end(), 1); // fill the vector with 1,...,n
	cout << "players: " << players << endl;
	map<int, double> map_player_to_sum_of_marginal_costs;
	cout << "permutations: "  << endl;
	int num_permutations = 0;
	do { 
		cout << " * " << players << endl;
		// calculate marginal costs for a specific permutation:
		double current_cost = 0;
		set<int> current_subset;
		for (int player: players) { // loop over the players in the order given by the current permutation
			current_subset.insert(player);
			double new_cost = map_subset_to_cost(current_subset);
			double marginal_cost = new_cost - current_cost;
			map_player_to_sum_of_marginal_costs[player] += marginal_cost;
			current_cost = new_cost;
		}
		++num_permutations;
	} while ( next_permutation(players.begin(), players.end()) );

	for (auto& [player,cost]: map_player_to_sum_of_marginal_costs)
		cost /= num_permutations;

	return map_player_to_sum_of_marginal_costs;
}



map<int,double> shapley_values(int num_of_players, map<set<int>,double> map_subset_to_cost)  {
	vector<int> players(num_of_players);
	iota(players.begin(), players.end(), 1); // fill the vector with 1,...,n
	cout << "players: " << players << endl;
	cout << "costs: " << endl << map_subset_to_cost << endl;
	map<int, double> map_player_to_sum_of_marginal_costs;
	cout << "permutations: "  << endl;
	int num_permutations = 0;
	do { 
		cout << " * " << players << endl;
		// calculate marginal costs for a specific permutation:
		double current_cost = 0;
		set<int> current_subset;
		for (int player: players) { // loop over the players in the order given by the current permutation
			current_subset.insert(player);
			double new_cost = map_subset_to_cost[current_subset];
			double marginal_cost = new_cost - current_cost;
			map_player_to_sum_of_marginal_costs[player] += marginal_cost;
			current_cost = new_cost;
		}
		++num_permutations;
	} while ( next_permutation(players.begin(), players.end()) );

	for (auto& [player,cost]: map_player_to_sum_of_marginal_costs)
		cost /= num_permutations;

	return map_player_to_sum_of_marginal_costs;
}

double map_subset_to_cost_f(const set<int>& subset) {
	return 1000 * (*(max_element(subset.begin(), subset.end())));
}

int main() {
	map<set<int>,double> map_subset_to_cost = {
		{ {}, 0 },
		{ {1}, 1000 },
		{ {2}, 2000 },
		{ {1,2}, 2000 },
		{ {3}, 3000 },
		{ {1,3}, 3000 },
		{ {2,3}, 3000 },
		{ {1,2,3}, 3000 },
	};
	// auto sv = shapley_values(3, map_subset_to_cost);
	auto sv = shapley_values_f(3, map_subset_to_cost_f);
	cout << endl << "Shapley values: " << sv << endl;
	return 0;
}
