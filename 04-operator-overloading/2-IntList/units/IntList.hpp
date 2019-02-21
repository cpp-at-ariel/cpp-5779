#pragma once

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint numInts):
          numInts(numInts),
          theInts (new int[numInts])
        {
            cout << "construct(" << numInts << ")" << endl;
        }

        ~IntList() {
            cout << "destruct" << endl;
            delete[] theInts;
        }

        void operator=(int value);
        
        int operator[](uint index) const;
        int& operator[](uint index);

        int operator[] (string s) const {
            return theInts[s.size()];
        }
};
