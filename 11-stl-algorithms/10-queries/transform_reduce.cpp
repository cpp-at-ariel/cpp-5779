// Example from https://en.cppreference.com/w/cpp/algorithm/transform_reduce
#include <vector>
#include <functional>
#include <iostream>
#include <numeric>
#include <execution> // Does not work with clang++-5.0.
 
int main()
{
    std::vector<double> xvalues(10007, 1.0), yvalues(10007, 1.0);
 
    double result = std::transform_reduce(
        std::execution::par,
        xvalues.begin(), xvalues.end(),
        yvalues.begin(), 0.0
    );
    std::cout << result << '\n';
}