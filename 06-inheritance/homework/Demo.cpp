/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
using namespace bullpgia;

int main() {
	ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
	ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};
	cout << play(c1234, g1234, 4, 100) << endl;  // prints 1 - guesser wins in one turn.
	cout << play(c1234, g9999, 4, 100) << endl;  // prints 101 - guesser loses by running out of turns 
	cout << play(c1234, g12345, 4, 100) << endl;  // prints 101 - guesser loses technically by making an illegal guess (too long).
	cout << play(c12345, g1234, 4, 100) << endl;  // prints 0 - chooser loses technically by choosing an illegal number (too long).

	RandomChooser randy;
	RandomGuesser guessy;
	for (uint i=0; i<100; ++i) {
		cout << play(randy, guessy, 2, 100) << endl;  // guesser should often win but sometimes lose.
	}

	SmartGuesser smarty;
	for (uint i=0; i<100; ++i) {
		cout << play(randy, smarty, 4, 100) << endl;  // smarty should always win in at most 10 turns!
	}
	return 0;
}

