/**
 * Writes a PPM image file.
 * 
 * Author: Erel Segal-Halevi.
 * Based on C code in RosettaCode: 
 * http://rosettacode.org/wiki/Category:C
 * 
 * Since: 2018-04
 */

#include <iostream>
#include <fstream>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};



int main() {
  const int dimx = 800, dimy = 800;
  ofstream imageFile("cpp.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  RGB image[dimx*dimy];
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      image[dimx*j+i].red = (i % 256);
      image[dimx*j+i].green = (j % 256);
      image[dimx*j+i].blue = ( (i*i+j*j) % 256);
    }
  }
  image[0].red = 255;
  image[0].blue = 0;
  image[0].green = 0;
  ///
  ///image processing
  ///
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
  return 0;
}
