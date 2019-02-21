/**
 * @author Ofir Pele
 * @since 2017
 */

#include "IntBuffer.hpp"

void IntBuffer::copyVals(const IntBuffer& other) {
	for (size_t i= 0; i<other.size(); ++i) {
		//(*this)[i]= other[i]; // equivalent to:
		this->operator[](i) = other.operator[](i);
	}
}

void IntBuffer::freeMemory() {
	delete[] _buf;
}
	
int* IntBuffer::getMemory(size_t size) {
	return new int[size];
}
