/**
 * Demonstrates maps.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string,int> m1;

	m1["abc"] = 300;
	cout << "m1[abc]=" << m1["abc"] << endl;
	cout << "m1[def]=" << m1["def"] << endl;
}
