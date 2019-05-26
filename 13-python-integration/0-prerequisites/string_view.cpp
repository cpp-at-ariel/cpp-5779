// Test the existence of the string_view library

#include <iostream>
#include <string_view>

using namespace std;

int main(){
	string_view world("world");
	cout << "hello " << world << endl;
}
