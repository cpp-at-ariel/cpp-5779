#include "output_containers.hpp"
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;

string find_shortest_path(const vector<vector<int>>& distances) {
	int num_of_towns = distances.size();
	vector<int> path(num_of_towns);
	iota(path.begin(), path.end(), 0); // fill the vector with 0,...,N-1
	vector<int> shortest_path_so_far;
	int shortest_distance_so_far = numeric_limits<int>::max();
	do {
		int distance = 0;
		for (int i=1; i<path.size(); ++i) {
			int prev_town = path[i-1];
			int cur_town = path[i];
			int cur_distance = distances[prev_town][cur_town];
			distance += cur_distance;
		}
		if (distance < shortest_distance_so_far) {
			shortest_distance_so_far = distance;
			shortest_path_so_far = path;
		}
	} while ( next_permutation(path.begin(),path.end()) );

	path = shortest_path_so_far;
	string result=to_string(path[0]);
	for (int i=1; i<path.size(); ++i) {
		int prev_town = path[i-1];
		int cur_town = path[i];
		int cur_distance = distances[prev_town][cur_town];
		result += " --" + to_string(cur_distance) + "--> " + to_string(cur_town);
	}
	result += ": == "+to_string(shortest_distance_so_far);
	return result;
}

int main() {
	vector<vector<int>> distances = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	auto begin = time(NULL);
	auto result = find_shortest_path(distances);
	auto end = time(NULL);
	auto duration = end-begin;
	cout << "  " << result << ", " << duration << " seconds" << endl;
	return 0;
}
