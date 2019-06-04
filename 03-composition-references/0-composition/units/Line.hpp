#pragma once

#include <iostream>
#include "Point.hpp"


class Line
{
	private:
		Point p1, p2;
	public:
		Line()
		//: p1{}, p2{}  // automatic
		{ 
	
		}
		Line(int xy1, int xy2): 
			p1{xy1}, p2{xy2}
			{ 

				
			}
		Line(int x1,int y1,int x2,int y2);

		Line(Point new_p1): p1(new_p1) {}
		
		void set(int,int,int,int);
		void set(Point,Point);
		string to_string();
};
