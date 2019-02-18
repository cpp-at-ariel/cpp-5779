#pragma once

#include "dice.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <random>
#include <cassert>
#include <functional>
#include <algorithm>
#include <limits>

#include "gtest/gtest.h" // for FRIEND_TEST, for testing private methods

class GrayvalueImage {
	
private:

	// A synomon for the type of the grayvalues
	typedef unsigned int grayvalue_t;
	static_assert(std::numeric_limits<grayvalue_t>::max()<=
				  std::numeric_limits<size_t>::max(),
				  "grayvalue_t maximum should be smaller than size_t maximum");

    // Number of rows
    size_t _R;
	// Number of columns
    size_t _C;
	// Maximum grayvalue
	grayvalue_t _MAX_G;
	// Pixels' grayvalues
	std::vector<grayvalue_t> _pixels;

	// Reports an error that has occurred when reading
	// from the file filename and closes the stream and
	// exits the program.
	static void errorReport(const std::string& filename,
							std::fstream& fin) {
		std::cerr << "Image " << filename
				  << " has a problem in its format" << std::endl;
		fin.close();
		exit(1);
	}

	// Reads i from the stream and report if an error has occurred
	template<typename T>
	static void readi(const std::string& filename,
					  std::fstream& fin,
					  T& i) {
		size_t tmp;
		fin >> tmp;
		if (!fin) errorReport(filename, fin);
		i= tmp;
	}

	void ctorsAdditionalWork() {

		assert( _R>0 && _C>0 && _MAX_G>0 );
		for (auto p:_pixels) assert( p<=_MAX_G );
		assert( _pixels.size()==_R*_C);

	}


public:

	/// Creates an image with R rows and C columns
	/// where the grayvalues are given in pixels and are
	/// between 0 and MAX_G
	GrayvalueImage(const size_t& R, const size_t& C,
				   const grayvalue_t& MAX_G,
				   const std::vector<grayvalue_t>& pixels)
		: _R(R), _C(C),
		  _MAX_G(MAX_G),
		  _pixels(pixels) {

		ctorsAdditionalWork();

	}

	/// Like previous constructor, only pixel values are uniform random number
	/// between 0 and MAX_G
	GrayvalueImage(const size_t& R, const size_t& C,
				   const grayvalue_t& MAX_G)
		: GrayvalueImage(R,C,MAX_G,std::vector<grayvalue_t>(R*C)) {
		
		
		std::generate(std::begin(_pixels),
					  std::end(_pixels),
					  dice<grayvalue_t>(0, MAX_G));

	}

	/// Creates an image from a file
	/// Ignores mistakes in input
	GrayvalueImage(const std::string& filename) {

		std::fstream fin(filename.c_str());

		readi(filename, fin, _R);
		readi(filename, fin, _C);
		readi(filename, fin, _MAX_G);

		_pixels.resize(R()*C());
		for (size_t i=0; i<R()*C(); ++i) {
			readi(filename, fin, _pixels[i]);
		}
		
		ctorsAdditionalWork();
		
	}

	/// Writes an image to a file
	void writeToFile(const std::string& filename) const {

		std::fstream fout(filename.c_str(), std::fstream::out|std::fstream::trunc);
		 
		fout << _R << " " << _C << " " << static_cast<size_t>(_MAX_G) << std::endl;
		
		for (size_t r=0; r<R(); ++r) {
			for (size_t c=0; c<C()-1; ++c) {
				fout << static_cast<size_t>(getPixel(r,c)) << " ";
			}
			fout << static_cast<size_t>(getPixel(r,C()-1)) << std::endl;
		}
		
	}

	/// Returns the number of rows
	const size_t R() const {
		return _R;
	}
	
	/// Returns the number of columns
	const size_t C() const {
		return _C;
	}
	
	/// Retruns the maximum grayvalue
	const grayvalue_t MAX_G() const {
		return _MAX_G;
	}
	
	/// Returns the grayvalue of a pixel in row r and column c
	const grayvalue_t getPixel(const size_t& r, const size_t& c) const {
		assert( r<R() && c<C() );
		return _pixels[r*C() + c];
	}

	/// Adds "pepper" noise.
	/// Each pixel has (percentage/100) probability to change to 0
	void addPepper(const size_t& percentage) {
		assert(percentage>=0 && percentage<=100);

		dice<size_t> d(1,100);

		for (auto& p:_pixels) {
			if (d()<percentage) p= 0;
		}
	}

	/// Does median filtering on the image.
	///
	/// Each pixel grayvalue is replaced with the median of its neighborhood pixels
	/// where the neighborhood pixels are the pixels that are in the image
	/// and are in the (2*radius+1)x(2*radius+1) square surrounding it.
	///
	/// The median is defined as the pixel at position
	/// (num_of_neighborhood_pixels-1)/2 at the sorted neighborhood pixels vector.
	/// Remember that array indcies starts from 0.
	/// For example if there are 3 neighborhood pixels, the median will be the
	/// pixel at the middle, at index (3-1)/2==1
	/// If there are 4 neighborhood pixels, the median will be the pixel at
	/// index (4-1)/2=1 
	///
	/// Note that near the border of the image some of the pixels in the
	/// (2*radius+1)x(2*radius+1) square surrounding it won't be in the image and
	/// thus the num_of_neighborhood_pixels will be less than
	/// (2*radius+1)x(2*radius+1)
	///
	/// method can be:
	/// 0. Sorting (using std::sort) and taking the median
	///    Time complexity: O( R()*C()*radius^2*lg(radius) )
	/// 1. Using directly std::nth_element
	///    Time complexity: O( R()*C()*radius^2 )
	/// 2. Using the histograms method described in the exercise.
	///    Time complexity: O( R()*C()*MAX_G() )
	void medianFilter(const size_t& radius, const unsigned int& method) {
		
	} // medianFilter
	
	/// Return true if and only if
	/// the dimensions of the images are equal,
	/// the maximum grayvalue of the images are equal,
	/// all the pixels values are equal
	/// Time complexity: O(R()*C())
	const bool operator==(const GrayvalueImage& b) const {

	}
	
	/// Returns the opposite of operator===
	/// Time complexity: O(R()*C())
	const bool operator!=(const GrayvalueImage& b) const {

	}

	/// swaps between rows r1 and r2
	/// Time complexity: O(1)
	void swap_rows(const size_t& r1, const size_t& r2) {

	}

	/// swaps between columns c1 and c2
	/// Time complexity: O(1)
	void swap_cols(const size_t& c1, const size_t& c2) {

	}
	
private:

	// TODO: add here private helper functions

	// For giving private fields and method access for the test:
	// TEST(test_case_name, test_name) uncomment the line below
	// For other tests, change the names.
	//FRIEND_TEST(test_case_name, test_name);
	
};
