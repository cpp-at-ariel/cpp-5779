/**
 * Simple example of class specialization.
 * 
 * @author Ophir Pele (?)
 * @since 2017 (?)
 */


#include <iostream>

template <typename Type> 
class Wrapper { 
public: 
	Type _data; 
	Wrapper(const Type& data) 
      : _data(data) { } 
	bool isBigger
      (const Type& data) const; 
};

template <typename Type> 
bool Wrapper<Type>::isBigger
   (const Type& data) const { 
	return data > _data; 
} 

int main() 
{ 
	Wrapper<const char*> a("hi"); 
	std::cout << std::boolalpha << a.isBigger("bye"); 
}
