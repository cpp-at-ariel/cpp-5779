#pragma once

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        char* listName;
        unsigned int numInts;

    public:
        IntList(uint numInts) {
            cout << "construct(" << numInts << ")" << endl;
            theInts = new int[numInts];
            listName = new char[5];
            this->numInts = numInts;
        }

        ~IntList() {
            cout << "destruct(" << numInts << ")" << endl;
            delete[] theInts;
            delete[] listName;
        }

        void print() {cout << "pointer=" << theInts << endl; }

        void fill(int value);
        int get(uint index);
        void put(uint index, int value);
};
