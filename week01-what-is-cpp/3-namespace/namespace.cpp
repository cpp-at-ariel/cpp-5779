#include <iostream>

namespace abc{
	int x = 123;
	void printx() { std::cout << x << std::endl; }
};

namespace def{
	int x = 456;
	void printx() { std::cout << x << std::endl; }
};

using namespace abc; 
// using namespace def; 
int main() {
	abc::printx();
	def::printx();
	printx();
}
