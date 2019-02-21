#include <iostream>
#include <sstream>
#include <iterator>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

/*
template<typename Iterator> Iterator& operator+=(Iterator& it, int howmuch) {
	for (int i=0; i<howmuch; ++i)
		++it;
	return it;
}
*/

int main()
{

	set<int> s1 = {1,7,3,5};
	vector<int> v11(4);
	auto it_v11 = v11.begin();
	it_v11+=2;

	copy(s1.begin(), s1.end(), v11.begin());
	auto it_s1 = s1.begin();
	it_s1++;
	//it_s1+=2;
	copy(it_s1, s1.end(), ostream_iterator<int>(cout,";"));
	cout << endl;

	auto it=s1.begin();

	//copy(s1.begin(), ++++++it, v1.begin());

	vector<int> v1(4);
	copy(istream_iterator<int>(cin), istream_iterator<int>{} , v1.begin());

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout,","));
	cout << endl;
	
	
    // istringstream str("0.12 0.2 0.3 0.4");
	// istream_iterator<float> b(str);
	// istream_iterator<float> e;
	// for (; b!=e; ++b)
	// 	cout << (*b) << endl;

	// ostream_iterator<double> o(cout,"---");
	// for (double i=0; i<10; ++i)
	// 	(*o) = i;

	int a[4] = {1,2,3,4};
	int b[4];
    //partial_sum(a, a+4,  ostream_iterator<int>(cout, ","));
	// for (int i: b) 
	// 	cout << i << endl;

    //partial_sum(istream_iterator<double>(cin),
    //       	istream_iterator<double>(),
    //            ostream_iterator<double>(cout, " "));
}