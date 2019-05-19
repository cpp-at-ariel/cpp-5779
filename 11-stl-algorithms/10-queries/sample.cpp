// example from https://en.cppreference.com/w/cpp/algorithm/sample

#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
 
int main()
{
    std::string in = "abcdefgh", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
                5, std::mt19937{std::random_device{}()});
    std::cout << "five random letters out of " << in << " : " << out << '\n';
}