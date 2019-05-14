/**
 * Demonstrates the difference between push_back and emplace
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<string> v1;
	vector<int> v2(v1.begin(), v1.end());
}
