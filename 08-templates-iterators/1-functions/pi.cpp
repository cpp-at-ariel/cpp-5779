/**
 * Variable template example
 * 
 * @author Erel Segal-Halevi
 * @since 2018-04
 */

#include <iostream>
using namespace std;

template<typename T> const T pi = 
      T(3.1415926535897932385L);  // variable template
 
template<typename T> T circular_area(T r) {
    return pi<T> * r * r;
}

int main() {
   cout << circular_area(5) << endl;    
   cout << circular_area(5.0) << endl;
}