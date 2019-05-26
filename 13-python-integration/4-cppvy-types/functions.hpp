#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int sum(const vector<int>& v) {
    cout << "sum vector" << endl;
    return accumulate(begin(v), end(v), 0);
}

int sum(const set<int>& v) {
    cout << "sum set" << endl;
    return accumulate(begin(v), end(v), 0);
}

int sum(const unordered_set<int>& v) {
    cout << "sum unordered_set" << endl;
    return accumulate(begin(v), end(v), 0);
}

int sum(const map<int,int>& v) {
    cout << "sum unordered_set" << endl;
    return 56;
}
