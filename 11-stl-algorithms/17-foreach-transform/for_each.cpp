/**
 * Demonstrates STL for_each algorithms.
 * From here:  https://en.cppreference.com/w/cpp/algorithm/for_each
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Sum
{
    Sum(): sum{0} { }
    void operator()(int n) { sum += n; }
    int sum;
};
 
int main()
{
    vector<int> nums{3, 4, 2, 8, 15, 267};
 
    auto print = [](const int& n) { cout << " " << n; };
 
    cout << "before:";
    for_each(nums.begin(), nums.end(), print);
    cout << '\n';
 
    for_each(nums.begin(), nums.end(), [](int &n){ n++; });
 
    cout << "after: ";
    for_each(nums.begin(), nums.end(), print);

    // calls Sum::operator() for each number
    Sum s = for_each(nums.begin(), nums.end(), Sum());
 

    cout << '\n';
    cout << "sum: " << s.sum << '\n';
}