#include "IntList.hpp"

void IntList::operator=(int value) {
    for (uint i=0; i<this->numInts; ++i)
        theInts[i] = value;
}

int IntList::operator[](uint index) const {
    cout << "c";
    return theInts[index];
}

int& IntList::operator[](uint index) {
    cout << "r";
    return theInts[index];
}
