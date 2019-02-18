/**
 * Template for numerically calculating the n-th derivative.
 * 
 * Author: Peter GottSinCoshling
 * Url: https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include "derivative.hpp"
#include "rgb.hpp"
#include <boost/lambda/lambda.hpp>

using boost::lambda::_1;

int main() 
{
    using namespace std;

	Picture pic(300,300);
	pic.setBackground({255,255,0});
	pic.plot( [](double){return 0;} , -4.0,4.0,1200,  -2.1,2.1, {0,0,0});

    paramSinCosFunctor paramSinCos_o(0.5); // sin(x/2)+cos(x)

    // auto x = 5;      // int x
    // auto y = "abc";  // char* y

    auto baseFunction = 
        //paramSinCos_o;
        //[](double x) {return x*x*x/3;};
        _1 * _1 * _1 / 3 + 1;
        //[](double x) {return std::abs(x);};

	pic.plot(baseFunction, -7.0,7.0,1200,  -2.1,2.1, {0,0,255});
    pic.plot(derive(baseFunction,0.001), -7.0,7.0,1200,  -2.1,2.1, {0,128,0});
    //pic.plot(derive(derive(baseFunction,0.001),0.001), -7.0,7.0,1200,  -2.1,2.1, {255,0,255});
    pic.plot(make_nth_derivative<2>(baseFunction,0.001), -7.0,7.0,1200,  -2.1,2.1, {255,0,0});
    pic.plot(make_nth_derivative<3>(baseFunction,0.001), -7.0,7.0,1200,  -2.1,2.1, {255,0,255});

/*
    using dd_paramSinCosFunctor= derivative<d_paramSinCosFunctor, double>;
    dd_paramSinCosFunctor dd_paramSinCos_o(d_paramSinCos_o, 0.001);


    second_derivative<paramSinCosFunctor, double> dd_paramSinCos_2_o(paramSinCosFunctor(1.0), 0.001);
    cout << "2nd der. of sin(0) + cos(0) is " << dd_paramSinCos_2_o(0.0) << '\n';

    nth_derivative<paramSinCosFunctor, double, 2> dd_paramSinCos_3_o(paramSinCosFunctor(1.0), 0.001);
    cout << "2nd der. of sin(0) + cos(0) is " << dd_paramSinCos_3_o(0.0) << '\n';

    nth_derivative<paramSinCosFunctor, double, 6> d6_paramSinCos_o(paramSinCosFunctor(1.0), 0.00001);
    cout << "6th der. of sin(0) + cos(0) is " << d6_paramSinCos_o(0.0) << '\n';

    nth_derivative<paramSinCosFunctor, double, 12> d12_paramSinCos_o(paramSinCosFunctor(1.0), 0.00001);
    cout << "12th der. of sin(0) + cos(0) is " << d12_paramSinCos_o(0.0) << '\n';

    nth_derivative<paramSinCosFunctor, double, 22> d22_paramSinCos_o(paramSinCosFunctor(1.0), 0.00001);
    cout << "22nd der. of sin(0) + cos(0) is " << d22_paramSinCos_o(0.0) << '\n';

    // auto d7_paramSinCos_o= make_nth_derivative<paramSinCosFunctor, double, 7>(paramSinCos_o, 0.00001);

    // nth_derivative<paramSinCosFunctor, double, 7> d7_paramSinCos_o(paramSinCos_o, 0.00001);
    // auto d7_paramSinCos_o= nth_derivative<paramSinCosFunctor, double, 7>(paramSinCos_o, 0.00001);
    // nth_derivative<decltype(paramSinCos_o), decltype(0.00001), 7> d7_paramSinCos_o(paramSinCos_o, 0.00001);

    make_nth_derivative<7, paramSinCosFunctor, double>(paramSinCos_o, 0.00001);
    auto d7_paramSinCos_o= make_nth_derivative<7>(paramSinCos_o, 0.00001);

    cout << "7th der. of paramSinCos_o at x=3 is " 
	 << make_nth_derivative<7>(paramSinCos_o, 0.00001)(3.0) << '\n';

    using boost::lambda::_1;
    
    (3.5 * _1 + 4.0) * _1 * _1;

    cout << "2nd der. of 3.5*x^3+4*x^2 at x=2 is "
	      << make_nth_derivative<2>((3.5 * _1 + 4.0) * _1 * _1, 0.0001)(2) << '\n';

    cout << "2nd der. of 3.5*x^3+4*x^2 at x=2 is "
	 << make_nth_derivative<2>([](double x){ return (3.5 * x + 4.0) * x * x; }, 0.0001)(2) << '\n';

    auto d7_cub_l= make_nth_derivative<7>([](double x){ return (3.5 * x + 4.0) * x * x; }, 0.0001);
    auto d7_paramSinCos_l= make_nth_derivative<7>([](double x){ return sin(2.5*x) + cos(x); }, 0.0001);
*/
	pic.toFile("func.ppm");
	return 0;
}

