/**
 * Simple example of class specialization
 * 
 * @author  Geeks for Geeks
 * @url     https://www.geeksforgeeks.org/template-specialization-c/
 */

#include <iostream>
using namespace std;

template <class T> class Test {  
public:
	Test()   {     cout << "General template object \n";  }  
}; 

template <> 
class Test <int> {   
public:
	Test()    {     cout << "Specialized template object \n";    }  
}; 

int main()  { 
    Test<int> a; 
    Test<char> b; 
    Test<float> c; 
} 
