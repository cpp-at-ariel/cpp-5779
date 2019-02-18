//#pragma once

#ifndef __POINT_HPP
#define __POINT_HPP

#include <string>
using namespace std;

class Point {
  private:
    int x;
    int y;
  public:
    void setX(int);
    void setY(int);
    string to_string();

    Point(): x(9), y(9) { }
    //Point() { x=y=9; }
    Point(int z): x(z), y(z) { }
    //Point(int z) { x=y=z; }
    Point(int xx, int yy): x(xx), y(yy)  { }
    //Point(int xx, int yy)  {this->x=xx; this->y=yy;}
};

#endif
