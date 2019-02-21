#include "GrayvalueImage.hpp"

int main() {
	const unsigned int method_used= 1;

	GrayvalueImage<> im("cameraman.txt");
	im.addPepper(10);

	im.writeToFile("cameraman_with_10_percent_pepper.txt");

	im.medianFilter(1,method_used);

	im.writeToFile("cameraman_with_10_percent_pepper_after_median_filtering.txt");
	
	return 0;
} // end main

