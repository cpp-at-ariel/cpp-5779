#include "DummyChoosers.hpp"
#include <stdlib.h>

std::string RandomChooser::choose(uint length) {
	std::string r="";
	for (uint i=0; i<length; ++i) {
		char c = '0' + (rand()%10);
		r += c;
	}
	return r;
}
