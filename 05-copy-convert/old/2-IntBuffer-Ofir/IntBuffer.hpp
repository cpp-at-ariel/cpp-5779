/**
 * @author Ofir Pele
 * @since 2017
 */

#pragma once

#include <cassert>
#include <cstdlib> // for size_t
#include <iostream> 


class IntBuffer {

private:
	int* _buf;
	size_t _size;

	//---------------------------------------------------------
	// private helpers
	//---------------------------------------------------------
	void copyVals(const IntBuffer& other);
	void freeMemory();
	static int* getMemory(size_t size);
	//---------------------------------------------------------
	
public:

	size_t size() const {
		return _size;
	}
	
	explicit IntBuffer(size_t size): 
	_buf(getMemory(size)), 
	_size(size) 
		{}
	
	//---------------------------------------------------------
	// Rule of three (in C++11 it will be rule of 5)
	//---------------------------------------------------------
	IntBuffer(const IntBuffer& other) :
		_buf(getMemory(other.size())),
		_size(other.size())	{
		
		copyVals(other);

	}

	~IntBuffer() {
		freeMemory();
	}
	
	IntBuffer& operator=(const IntBuffer& other) {
		if (this!=&other) {
			freeMemory(); // why not call destructor or delete this?
			              // ANSWER: undefined behavior as we use destructor twice.
			              // Destructor is not only its body!
			_buf= getMemory(other.size());
			_size= other.size();
			copyVals(other);
		}
		return *this;
	}
	//---------------------------------------------------------

	//---------------------------------------------------------
	// Accessors
	//---------------------------------------------------------
	int& operator[](size_t i) {
		assert(i<size());
		std::cout << "int& operator[]" << std::endl;
		return _buf[i];
	}
	
	const int& operator[](size_t i) const {
		assert(i<size());
		std::cout << "const int& operator[] const" << std::endl;
		return _buf[i];
	}
	//---------------------------------------------------------
	
};

class DoubleBuffer {
	IntBuffer b1;
	IntBuffer b2;
	//...
}

// Q: If we'll have a class with a field IntBuffer, will it also need the rule of 3?
// A: No, as the default dtor, copy ctor, op= will call IntBuffer dtor, copy ctor, op= respectively

// Q: What about CharBuffer?
// A: We'll learn templates

// Q: Using define for memory policy is ugly, error prone and we cannot use two IntBuffers with different memory policies. Isn't there something better?
// A: We'll learn templates

// Q: List and IntBuffer and many other collections all share the need to iterate over all elements. Is there a unifying concept for this?
// A: We'll learn iterators and C++11 "foreach"

// Q: Isn't there a standard dynamic array in C++ standard library?
// A: Yes, vector and we'll learn about it. In C++11 there is also static array called array.
