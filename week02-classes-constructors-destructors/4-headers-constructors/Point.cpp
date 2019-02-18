#include "Point.hpp"


void Point::setX(int newX) { 
	x = newX; 
}

void Point::setY(int newY) { 
	y = newY; 
}

string Point::to_string() {
	return "("+std::to_string(x)+","+std::to_string(y)+")";
}


Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
