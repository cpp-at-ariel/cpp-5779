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
	MyClass(): myField(555) {}
	void print1(ostream& out) const;                      // member method
	friend void print2(ostream& out, const MyClass& obj); // friend function
};

void MyClass::print1(ostream& out) const {
	out << myField << endl;
}

void print2(ostream& out, const MyClass& obj) {
	out << obj.myField << endl;
}

/* Does not compile
void print3(ostream& out, const MyClass& obj) {
	out << obj.myField << endl;
}
*/

int main() {
	MyClass obj;
	obj.print1(cout);
	print2(cerr, obj);
	return 0;
}
