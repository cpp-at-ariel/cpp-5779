#include <cassert>
#include <iostream>
using namespace std;

template <typename TNom,typename TDen> 
struct DivideProperties {
	static const bool 
		CanDivide = false,
		CanDivideByZero=false;
};

template <> struct DivideProperties<int,int> { 
	static const bool 
		CanDivide = true,
		CanDivideByZero=false;
}; 

template <> struct DivideProperties<double,double> { 
	static const bool 
		CanDivide = true,
		CanDivideByZero=true;
}; 

class divide_by_zero{};

template <typename TNom, typename TDen, typename TRes > 
void SafeDiv(const TNom& nom, const TDen& den, TRes& res) {
	// static_assert only in c++11 (supported in current compilers)
	static_assert(
		DivideProperties<TNom,TDen>::CanDivide, 
		"Not dividable!");

	if (!DivideProperties<TNom,TDen>::CanDivideByZero)  {
		if(den==0) {
			throw divide_by_zero{};
		}
	}

	res=nom/den; 
} 


int main() { 
   double res; 
   SafeDiv(10.0,3.0,res); //OK 
   cout << res << endl;
   SafeDiv(10.0,0.0,res); //OK 
   cout << res << endl;
   SafeDiv(10,3,res);     //OK
   cout << res << endl;
   //SafeDiv(10,0,res);     //exception
   cout << res << endl;
   //SafeDiv('c','d',res);  //Compilation error: "not dividable!"
   cout << res << endl;
}

