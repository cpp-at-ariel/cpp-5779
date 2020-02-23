/**
 * Using template-class-specialization to control return-type
 * 
 * @author M Salters
 * @url    https://stackoverflow.com/a/26876959/827927
 */

#include <iostream>
#include <iomanip>
using namespace std;



int main() {
  int a;
  decltype(a) aa;
  // auto aa; // compilation error

  int& b=a;
  decltype(b) bb=aa;
  decltype(b)& cc=aa;

  auto c = a;
  // equivalent to:
  // decltype(a) c = a;
}
