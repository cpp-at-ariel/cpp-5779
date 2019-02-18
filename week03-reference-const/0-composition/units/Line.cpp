#include "Line.hpp"

int sqr(int x) {
	return x*x;
}

Line::Line(int x1,int y1,int x2,int y2):
 	p1{sqr(x1),sqr(y1)},
	p2{x2,y2}
{}



void Line::set(int x1,int y1,int x2,int y2) {
	p1.setX(x1);
	p1.setY(y1);
	p2.setX(x2);
	p2.setY(y2);
}

void Line::set(const Point& p1,const Point& p2) {
	this->p1 = p1;
	this->p2 = p2;
}

string Line::to_string()
{
	return "Line from " + p1.to_string() + " to " + p2.to_string();
}
