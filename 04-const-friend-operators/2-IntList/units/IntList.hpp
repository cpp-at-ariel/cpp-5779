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
            cout << "constructing an IntList with " << numInts << " ints." << endl;
        }

        ~IntList() {
            cout << "destructing an intlist with " << numInts << " ints." << endl;
            delete[] theInts;
        }

        // Set all elements in this intList to value
        void operator=(int value);

        const int operator[](uint index) const;
        int& operator[](uint index);

        int operator[] (string s) const {
          if (s==string("first"))
            return theInts[0];
          else if (s==string("last"))
            return theInts[numInts-1];
          else throw string("Illegal argument: "+s);
        }
};
