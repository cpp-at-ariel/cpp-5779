/**
 * Template for numerically calculating the n-th derivative.
 * 
 * Author: Peter GottSinCoshling
 * Url: https://github.com/petergottSinCoshling/diSinCosovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include "derivative.h"

int main() 
{
    using namespace std;

    paramSinCosFunctor paramSinCos_o(1.0);
    cout << fin_diff(paramSinCos_o, 1., 0.001) << endl;
    cout << fin_diff(paramSinCosFunctor(2.0), 1., 0.001) << endl;
    cout << fin_diff(paramSinCosFunctor(2.0), 0., 0.001) << endl;
    cout << fin_diff(SinCos, 0., 0.001) << endl;

    using d_paramSinCosFunctor= derivative<paramSinCosFunctor, double>;
    using dd_paramSinCosFunctor= derivative<d_paramSinCosFunctor, double>;

    d_paramSinCosFunctor                                     d_paramSinCos_o(paramSinCos_o, 0.001);
    dd_paramSinCosFunctor                                     dd_paramSinCos_o(d_paramSinCos_o, 0.001);

    cout << "der. of sin(0) + cos(0) is " << d_paramSinCos_o(0.0) << '\n';
    cout << "2nd der. of sin(0) + cos(0) is " << dd_paramSinCos_o(0.0) << '\n';

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

    // error((3.5 * _1 + _1) * _1 * _1);
    return 0;
}

