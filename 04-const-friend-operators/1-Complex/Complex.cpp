/**
 * Implementation of the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#include "Complex.hpp"
using namespace std;

static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}

istream& operator>> (istream& input, Complex& c) {

    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch;
    // return (input >> c._re >> ch >> c._im >> ch);
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> c._re))                 ||
         (!getAndCheckNextCharIs(input,'+')) ||
         (!(input >> c._im))                 ||
         (!(getAndCheckNextCharIs(input,'i'))) ) {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    }

    return input;
    //---------------------------------------------
}
