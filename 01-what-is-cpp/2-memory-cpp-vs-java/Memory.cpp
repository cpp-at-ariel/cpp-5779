/**
 * Demonstrates memory usage in C++.
 * @author erelsgl
 */

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

constexpr int SIZE=125*1000*1024; // ~ 125,000,000

class Point {
	private:
		int x;
		int y;
	public:
		Point() { x = y = 5555; }	
};

int main() {
	cout << "Before new" << endl;
	this_thread::sleep_for(chrono::seconds(3));

	Point* p = new Point[SIZE];
	for (int  i=0; i<SIZE; ++i)
		p[i] = Point();

	cout << "After new" << endl;
	// The free memory should drop by ... KB.

	this_thread::sleep_for(chrono::seconds(5));
}
