#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#include "rgb.hpp"

struct Sine {
	double coefficient;
	Sine(double coefficient=1): coefficient(coefficient) {}
	double operator() (double x) { 
		return std::sin(coefficient*x);
	}
};

template<int y>
struct Constant {
	double operator() (double x) { 
		return y; 
	}
};

double twox(double x) { 
	return 2*x; 
}

int main() {
	Picture pic(300,300);
	pic.setBackground({255,255,0});

	pic.plot(twox, -4.0,4.0,1200,  -1.1,1.1, {0,0,0});

	//pic.plot(Sine{1}, -4.0,4.0,1200,  -1.1,1.1, {0,0,255});
	//pic.plot(Sine{3}, -4.0,4.0,1200,  -1.1,1.1, {0,128,0});
	pic.plot(Constant<0>{}, -4.0,4.0,1200,  -1.1,1.1, {0,0,0});

	pic.plot( [](double x){return std::abs(x);}, -4.0,4.0,1200,  -1.1,1.1, {255,0,0}) ;

	pic.toFile("func.ppm");
	return 0;
}
