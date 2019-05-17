#include "output_containers.hpp"
using namespace std;

template<typename T> 
	std::_List_iterator<T> operator+ (
	std::_List_iterator<T> it, int inc) {
		if (inc<0)
			for (int i=0; i<-inc; ++i)
				--it;
		else
			for (int i=0; i<inc; ++i)
				++it;
		return it;
}


int main() {
	{
		vector<int> v {1,2,4,7,11,16,22};
		list<int> l {99,66,11,44,88,55,33};
		cout << v << endl;
		cout << l << endl;

		l.insert(l.begin(), v.begin()+2, v.begin()+5);
		cout << l << endl;
	}
	{
		vector<int> v {1,2,4,7,11,16,22};
		list<int> l {99,66,11,44,88,55,33};
		cout << v << endl;
		cout << l << endl;

		v.insert(v.begin(), l.begin()+2, l.begin()+5);
		cout << v << endl;
	}
}
