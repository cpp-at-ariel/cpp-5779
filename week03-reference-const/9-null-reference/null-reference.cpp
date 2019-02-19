#include <iostream>
using namespace std;

void test (const int& i) {
	if (&i)
		cout << i << endl;
	else
		cout << "NULL" << endl;
}

int main() {
	test(5);
	int i=6;
	test(i);
	int* j=nullptr;
	test(*j);
}
