#pragma once

#include <iostream>
#include "Point.hpp"

// #ifndef __POINT_HPP
// #define __POINT_HPP

class Line
{
	private:
		Point p1, p2;
	public:
		Line() { }
		Line(int xy1, int xy2): 
			p1{xy1}, p2{xy2}
			{ }
		Line(int x1,int y1,int x2,int y2);
		
		void set(int x1,int y1,int x2,int y2);
		void set(const Point& p1,const Point& p2);
		string to_string();
};

// #endif