/**
 * A test program for itertools.
 * 
 * @author Many students.
 * @since  2019-05
 */


#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"

using namespace itertools;

template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (decltype(*iterable.begin()) i : iterable){
		ostr << i << ",";
	}
	return ostr.str();
}

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {



		/* Tests by Yoav Gross and Elad Nevii:
		   https://github.com/IMYod/CPP_Iterators */
		
		testcase.setname("YE - Range");
		testcase.CHECK_EQUAL(iterable_to_string(range(5, 9)),string("5,6,7,8,"));
		testcase.CHECK_EQUAL(iterable_to_string(range(1.05, 5.05)),string("1.05,2.05,3.05,4.05,"));
		
		int j = -10;
		for (int i : range(-10, 10))
		{
			testcase.CHECK_EQUAL(i, j);
			j++;
		}
		
		j = 0;
		for (int i : range(0, 100))
		{
			testcase.CHECK_EQUAL(i, j);
			j++;
		}
		
		j = -20;
		for (int i : range(-20, 1))
		{
			testcase.CHECK_EQUAL(i, j);
			j++;
		}
		
		double d = 8000.66;
		for (double i : range(8000.66, 8025.66))
		{
			testcase.CHECK_EQUAL(i, d);
			d++;
		}
		
		j = -1000000;
		for (int i : range(-1000000, -999990))
		{
			testcase.CHECK_EQUAL(i, j);
			j++;
		}
		
		for (int i : range(0, 0))
			testcase.CHECK_EQUAL(1, 0);
           
     		//testcase.CHECK_EQUAL(iterable_to_string(chain(range(0.5, 2.5), string("876"))),string("0.5,1.5,8,7,"));
          

         //*Chain*/
         testcase.setname("YE - Chain"); 
        
        j = 1;
		for (int i : chain(range(1, 5), range(5, 9)))
		{
			testcase.CHECK_EQUAL(i, j);
			j++;
		}
		testcase.CHECK_EQUAL(j, 9);
		
		d = -30.5;
		for (double i : chain(range(-30.5, 0.5), range(0.5, 30.5)))
		{
			testcase.CHECK_EQUAL(i, d);
			d++;
		}
		testcase.CHECK_EQUAL(d, 30.5);
		
		string s="abcdef";
		char c='a';
		for (char i : chain(range('a', 'd'), range('d', 'g')))
		{
			testcase.CHECK_EQUAL(i, c);
			c++;
		}
		testcase.CHECK_EQUAL(c, 'a'+6);
		
		s="vwxycpp";
		j=0;
		for (char ch : chain(range('v', 'z'), string("cpp")))
		{
			testcase.CHECK_EQUAL(ch, s[j]);
			j++;
		}
		testcase.CHECK_EQUAL(j, 7);
		
		s="abcdefghijklmnopqrstuvwxyz";
		j=0;
		for (char ch : chain(range('a', 'w'), string("wxyz")))
		{
			testcase.CHECK_EQUAL(ch, s[j]);
			j++;
		}
		testcase.CHECK_EQUAL(j, 26);

         testcase.setname("YE - multi chain");
		 testcase.CHECK_EQUAL(iterable_to_string(chain(chain(range(0,4), range(1,5)), chain(range(2,4), range(3,3))))
			,string("0,1,2,3,1,2,3,4,2,3,"));

		 testcase.CHECK_EQUAL(iterable_to_string(chain(chain(range('5',':'), range('H','K')), string("%^&")))
			,string("5,6,7,8,9,H,I,J,%,^,&,"));
		
		
        
         //*zip*/
         testcase.setname("YE - Zip"); 
         
         testcase.CHECK_EQUAL(iterable_to_string(zip(range(1,6), string("hello"))),string("1,h,2,e,3,l,4,l,5,o,"));
         testcase.CHECK_EQUAL(iterable_to_string(zip(string("ILv +"), string(" oeC+"))),string("I, ,L,o,v,e, ,C,+,+,")); //It's must be mestake
	
	 std::list<int> list1 = {2,5,11,17};
	 std::list<int> list2 = {3,7,13,19};
         testcase.CHECK_EQUAL(iterable_to_string(zip(list1, list2)),string("2,3,5,7,11,13,17,19,"));


         testcase.setname("YE - multi zip"); 

         testcase.CHECK_EQUAL(iterable_to_string(zip(zip(range(1,6), string("hello")),zip(range(1,6), string("hello"))))
		,string("1,h,1,h,2,e,2,e,3,l,3,l,4,l,4,l,5,o,5,o,"));

	testcase.CHECK_EQUAL(iterable_to_string(zip(zip(range('T','W'), string("eds")),zip(range(1,4), string("3.1")))),
		string("T,e,1,3,U,d,2,.,V,s,3,1,"));

	testcase.CHECK_EQUAL(iterable_to_string(zip(chain(range(-1,1), range(50,52)),zip(range('A','E'), string("////")))),
		string("-1,A,/,0,B,/,50,C,/,51,D,/,"));

	
	//*prduct*/
         testcase.setname("YE - Product"); 

	testcase.CHECK_EQUAL(iterable_to_string(product(range(1,4), string("hello"))),
		string("1,h,1,e,1,l,1,l,1,o,2,h,2,e,2,l,2,l,2,o,3,h,3,e,3,l,3,l,3,o,"));

	testcase.CHECK_EQUAL(iterable_to_string(product(range('a','c'), range('a','c'))),
		string("a,a,a,b,b,a,b,b,"));


  testcase.setname("YE - empty product"); 

	for (auto i : product(range(1,3), range(5,5)))
        	testcase.CHECK_EQUAL(0,1);

	for (auto i : product(range(3,3), range(1,5)))
        	testcase.CHECK_EQUAL(0,1);


        testcase.setname("YE - multy product"); 
	
	testcase.CHECK_EQUAL(iterable_to_string(product(chain(range('1','3'), range('2','4')), range(3,5))),
		string("1,3,1,4,2,3,2,4,2,3,2,4,3,3,3,4,"));

	testcase.CHECK_EQUAL(iterable_to_string(product(zip(range('1','3'), range('2','4')), range(3,5))),
		string("1,2,3,1,2,4,2,3,3,2,3,4,"));

	testcase.CHECK_EQUAL(iterable_to_string(product(range(1,3), product(range('o','q'), string("ab")))),
		string("1,o,a,1,o,b,1,p,a,1,p,b,2,o,a,2,o,b,2,p,a,2,p,b,"));


	//*powerset*/
  testcase.setname("YE - PowerSet");

	testcase.CHECK_EQUAL(string("xxx"), string("xxx"));

	//this test failed even when I return right answer
	testcase.CHECK_EQUAL(iterable_to_string(powerset(range(1,1))),
		string("{},"));

	//this test failed even when I return right answer
	testcase.CHECK_EQUAL(iterable_to_string(powerset(range(1,4))),
		string("{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3},"));

	//this test is not compiled yet
	testcase.CHECK_EQUAL(iterable_to_string(powerset(zip(range('m','o'),range(15,17)))),
		string("{},{m,15},{n,16},{m,15,n,16},"));
	

	testcase.setname("YE - multy powerset");

	int sum = 0;
	for (auto i : powerset(range(1,5)))
		for (auto j : i)
			sum += j;
	testcase.CHECK_EQUAL(sum,80);
	
	//this test is not compiled yet	
	testcase.CHECK_EQUAL(iterable_to_string(powerset(product(range(2,4), range(10,12)))),
		string("{},{2,10},{2,11},{2,10,2,11},{3,10},{2,10,3,10},{2,11,3,10},{2,10,2,11,3,10},{3,11},{2,10,3,11},{2,11,3,11},{2,10,2,11,3,11},{3,10,3,11},{2,10,3,10,3,11},{2,11,3,10,3,11},{2,10,2,11,3,10,3,11},"));



		/* Tests by Omer Paz and Shimon Mimoun:
		   https://github.com/ShimonMimoun/Cpp_5_Itertools */


//		Constant Range,Chain,Zip,Product,Powerset

		range a11{1, 1};	range a044{0, 44};range Saz{'a', 'z'};range Saa{'a', 'a'};range Smq{'m' , 'q'};
		
		chain CR14R03{range{1, 4}, range{0, 3}}; chain CRACRDG{range{'a', 'c'}, range{'d', 'g'}};chain CACSTEST{range{'a', 'c'}, string{"test"}};
		
		zip ZCR14RAD{range{1, 4}, range{'a', 'd'}}; 	zip ZCACSAB{range{'a', 'c'}, string{"ab"}};

		product PR14RAD{range{1, 4}, range{'a', 'd'}}; product PCACSAB{range{'a', 'c'}, string{"hello"}};
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////// TEST RANGE 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //	Simple tests or we only advance the figure is we check if it is equal.
			testcase.setname("OS - TEST RANGE ");
	
		int number = 0;
			for (int i : range(0, 9))
			{
				testcase.CHECK_EQUAL(i, number);
				number++;
			}
		number =10;
			for (int i : range(10, 44))
			{
				testcase.CHECK_EQUAL(i, number);
				number++;
			}
		 number = -8;
			for (int i : range(-8, 10))
			{
				testcase.CHECK_EQUAL(i,number);
				number++;
			}

	char chartemp='a';
			for (char i : range('a', 'd'))
			{
				testcase.CHECK_EQUAL(i, chartemp);
			chartemp++;
			}


			chartemp='e';
			for (char i : range('e', 'z'))
			{
				testcase.CHECK_EQUAL(i, chartemp);
			chartemp++;
			}
			for (int i : range(0, 0))
				testcase.CHECK_EQUAL(i, 0);


			for (int i : a11)
				testcase.CHECK_OUTPUT(i,"1");









/*From there we will find tests that we walk in the following way.
We find a table that is in fact the data that must be received each time.
And simply, it remains more than check the outgoing data with what we expect to return
*/


	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST CHAIN 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	


testcase.setname("OS - TEST CHAIN ");

number=0;
int tab[]={1,2,3,5,6,7};
for (int i: chain(range(1,4), range(5,8)))
	{
		testcase.CHECK_EQUAL(i, tab[number]);
		number++;
	}


number=0;
int tab2[]={0,1,2,3,9,10};
for (int i: chain(range(0,4), range(9,11)))
	{
		testcase.CHECK_EQUAL(i, tab2[number]);
		number++;
	}

number=0;
int temp=0;
char tab3[]={'h','e','l','l','o'};
char tab4[]={'a','b','c'}	;

for (auto i: chain(range('a','d'), string("hello")))
	{
		if(number<3)
		{
		testcase.CHECK_EQUAL(i, tab4[number]);
		number++;
		}
	else{
		testcase.CHECK_EQUAL(i, tab3[temp]);
		temp++;
	}
	}


	
number=0;
temp=0;
char tab5[]={'d','e','f'};
char tab6[]={'a','b','c'}	;

for (auto i: chain(range('a','d'), range('d','g')))
	{
		if(number<3)
		{
		testcase.CHECK_EQUAL(i, tab6[number]);
		number++;
		}
	else{
		testcase.CHECK_EQUAL(i, tab5[temp]);
		temp++;
	}
	}




	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST ZIP 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
		testcase.setname("OS - TEST ZIP ");
number=0;

string tab9[]={"1,h","2,e","3,l","4,l","5,o"};
for (auto pair: zip(range(1,6), string("hello")))
{
		testcase.CHECK_OUTPUT(pair,tab9[number]);
		number++;

}

number=0;
		string tab10[]={"6,q","7,w","8,e","9,r","10,t"};
for (auto pair: zip(range(6,11), string("qwert")))
{
		testcase.CHECK_OUTPUT(pair,tab10[number]);
		number++;

}

number=0;
		string tab11[]={"6,0","7,1","8,2","9,3","10,4"};
for (auto pair: zip(range(6,11), range(0,5)))
{
		testcase.CHECK_OUTPUT(pair,tab11[number]);
		number++;

}

number=0;
		string tab16[]={"6,a","7,b","8,c","9,d","10,e"};
for (auto pair: zip(range(6,11), range('a','f')))
{
		testcase.CHECK_OUTPUT(pair,tab16[number]);
		number++;

}

number=0;
		string tab12[]={"0,a","1,b","2,c","3,d","4,e","5,f"};
for (auto pair: zip(range(0,6), range('a','g')))
{
		testcase.CHECK_OUTPUT(pair,tab12[number]);
		number++;

}




	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST PRODUCT 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	testcase.setname("OS - TEST PRODUCT");
	number=0;
		string tab13[]={"0,a","0,b","1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
for (auto pair: product(range(0,5), string("ab")))
{
		testcase.CHECK_OUTPUT(pair,tab13[number]);
		number++;

}

	number=0;
		string tab14[]={"0,5","0,6","1,5","1,6","2,5","2,6","3,5","3,6","4,5","4,6"};
for (auto pair: product(range(0,5), range(5,7)))
{
		testcase.CHECK_OUTPUT(pair,tab14[number]);
		number++;

}


	number=0;
		string tab17[]={"0,a","0,b","1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
for (auto pair: product(range(0,5), range('a','c')))
{
		testcase.CHECK_OUTPUT(pair,tab17[number]);
		number++;

}

	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST PowerSet 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	testcase.setname("OS - TEST PowerSet");
	number=0;
		string tab18[]={"{}","{1}","{2}","{1,2}","{3}","{1,3}","{2,3}","{1,2,3}"};
for (auto pair: powerset(range(1,4))){
		testcase.CHECK_OUTPUT(pair,tab18[number]);
		number++;

}

	number=0;
		string tab20[]={"{}","{a}","{b}","{a,b}","{x}","{a,x}","{b,x}","{a,b,x}","{y}","{a,y}","{b,y}","{a,b,y}","{x,y}","{a,x,y}","{b,x,y}","{a,b,x,y}"};
for (auto subset: powerset(chain(range('a','c'),range('x','z'))))
{		testcase.CHECK_OUTPUT(subset,tab20[number]);
		number++;

}




		/* Tests by Gil Matshliah and Amit Rash and Qusai Trabeh :
		   https://github.com/gilma0/CPP-5.1 */
		
//===========================================================================//Test - RANGE//=====================================================================================
	
		testcase.setname("GAQ -  **Range > Test** ");
	
		int n = 0;
			for (int i : range(0,1))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		 n = 1;
			for (int i : range(1,2))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		 n = 1;
			for (int i : range(1,3))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		 n = 1;
			for (int i : range(1,4))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
	         n = 1;
			for (int i : range(1,5))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		 n = 1;
			for (int i : range(1,6))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		 n = 0;
			for (int i : range(0,9))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		 n = 13;
			for (int i : range(13,55))
			{
				testcase.CHECK_EQUAL(i, n);
				n++;
			}
		

	char CCounter='a';
			for (char i : range('a', 'd'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}
		CCounter='f';
			for (char i : range('f', 'x'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}
			CCounter='e';
			for (char i : range('e', 'q'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}
			CCounter='b';
			for (char i : range('b', 'z'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}
			CCounter='b';
			for (char i : range('b', 'q'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}
			CCounter='a';
			for (char i : range('a', 'f'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}
			CCounter='a';
			for (char i : range('a', 'n'))
			{
				testcase.CHECK_EQUAL(i, CCounter);
			CCounter++;
			}


	
	
//===========================================================================//Test - CHAIN//=====================================================================================


	testcase.setname("GAQ -   **Chain->Test**  ");

		int n0 = 0;

int arr1[]={1,2,3,5,6,7};
for (int i: chain(range(1,4), range(5,8)))
	{
		testcase.CHECK_EQUAL(i, arr1[n0]);
		n0++;
	}


n0=0;
int arr2[]={0,1,2,3,9,10};
for (int i: chain(range(0,4), range(9,11)))
	{
		testcase.CHECK_EQUAL(i, arr2[n0]);
		n0++;
	}

n0=0;
int Temp=0;
char arr3[]={'h','e','l','l','o'};
char arr4[]={'a','b','c'}	;

for (auto i: chain(range('a','d'), string("hello")))
	{
		if(n0<3)
		{
		testcase.CHECK_EQUAL(i, arr4[n0]);
		n0++;
		}
	else{
		testcase.CHECK_EQUAL(i, arr3[Temp]);
		Temp++;
	}
	}

//===========================================================================//Test - ZIP//=====================================================================================

	
	
		testcase.setname("GAQ -  **Zip->Test** ");
int n1=0;

string arr5[]={"1,h","2,e","3,l","4,l","5,o"};
for (auto pair: zip(range(1,6), string("hello")))
{
		testcase.CHECK_OUTPUT(pair,arr5[n1]);
		n1++;

}

n1=0;

		string arr6[]={"6,0","7,1","8,2","9,3","10,4"};
	for (auto pair: zip(range(6,11), range(0,5)))
{
		testcase.CHECK_OUTPUT(pair,arr6[n1]);
		n1++;

}

n1=0;
		string arr7[]={"6,q","7,w","8,e","9,r","10,t"};
for (auto pair: zip(range(6,11), string("qwert")))
{
		testcase.CHECK_OUTPUT(pair,arr7[n1]);
		n1++;

}



//===========================================================================//Test - PRODUCT//=====================================================================================

	testcase.setname("GAQ -  **Product->Test** ");


	int n2=0;
		string arr8[]={"0,5","0,6","1,5","1,6","2,5","2,6","3,5","3,6","4,5","4,6"};
for (auto pair: product(range(0,5), range(5,7)))
{
		testcase.CHECK_OUTPUT(pair,arr8[n2]);
		n2++;

}


//===========================================================================//Test - POWERSET//=====================================================================================

 		testcase.setname("GAQ -  **Powerset->Test** ");
 		 int n3=0;

 	string arr9[]={"{}","{1}","{2}","{1,2}","{3}","{1,3}","{2,3}","{1,2,3}"};
for (auto pair: powerset(range(1,4))){
		testcase.CHECK_OUTPUT(pair,arr9[n3]);
		n3++;

}

	n3=0;
		string arr10[]={"{}","{a}","{b}","{a,b}","{x}","{a,x}","{b,x}","{a,b,x}","{y}","{a,y}","{b,y}","{a,b,y}","{x,y}","{a,x,y}","{b,x,y}","{a,b,x,y}"};
for (auto subset: powerset(chain(range('a','c'),range('x','z'))))
{		testcase.CHECK_OUTPUT(subset,arr10[n3]);
		n3++;

}

     n3=0;
string arr11[]={"{}","{1}","{2}","{1,2}","{2,1}"};
for (auto pair: powerset(range(1,3))){
		testcase.CHECK_OUTPUT(pair,arr11[n3]);
		n3++;

}
    n3=0;
string arr12[]={"{}","{1}"};
for (auto pair: powerset(range(1,2))){
		testcase.CHECK_OUTPUT(pair,arr12[n3]);
		n3++;

}


 		testcase
			.setname("powerset of string")
			.CHECK_EQUAL(iterable_to_string(powerset(string("abc"))), string("{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c},"))
			.setname("zip of vector and list")
			.CHECK_EQUAL(iterable_to_string(zip(vector<int>{1,2,3},list<int>{4,5,6})), string("1,4,2,5,3,6,"))
			.setname("chain of string and set")
			.CHECK_EQUAL(iterable_to_string(chain(set<char>{'a','b','c'},string{"def"})), string("a,b,c,d,e,f,"))
		;
		testcase.print();
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
