/**
 * Demostrates friend methods.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using namespace std;

class MyClass {
private:
	int myField;
public:
	int getField1();
	friend int getField2(const MyClass& obj);
};

int MyClass::getField1() {
	return myField;
}

int getField2(const MyClass& obj) {
	return obj.myField;
}

// Does not compile!
// int getField3(const MyClass& obj) {
// 	return obj.myField;
// }

int main() {
	MyClass obj;
	cout << obj.getField1() << endl;
	cout << getField2(obj) << endl;
	// cout << getField3(obj) << endl;
	return 0;
}
