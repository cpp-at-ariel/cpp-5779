/**
 * Demostrates friend methods.
 * 
 * TODO: Move to week 2.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-04
 */



class MyClass {
private:
	int myField;
public:
	int getField() { 
		return myField; 
	}

	friend int getField2() { 
		// return myField;  won't compile
	}

	friend void f();
};

//friend void f(); // won't compiles

void f() {
	MyClass a;
	a.myField;
}

void g() {
	MyClass a;
	//a.myField;  // won't compile
}


