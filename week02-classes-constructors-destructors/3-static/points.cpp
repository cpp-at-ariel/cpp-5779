/**
 * Demonstrates static members
 */

#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

  public:

    // A static const can be initialized inline:
    static const int MAXX=1366;
    // A non-static const must be initialized out-of-line:
    static int MAXY;

    void setX(int newX) { 
        if (newX>MAXX)
            throw "New x is too large! The maximum is "+std::to_string(MAXX);
        x = newX; 
    }

    void setY(int newY) { 
        if (newY>MAXY)
            throw "New y is too large! The maximum is "+std::to_string(MAXY);
        y = newY; 
    }

    string to_string() {
        return "("+std::to_string(x)+","+std::to_string(y)+")";
    }

    static void showMax() {
        cout << MAXX << "," << MAXY << endl;
    }
};



int Point::MAXY = 768;


int main() {
    Point p1;
    cout << "p1 = " << p1.to_string() << endl;

    Point p2;
    p2.setX(10);
    p2.setY(20);
    cout << "p2 = " << p2.to_string() << endl;
    
    cout << "Maximum values: " << endl;
    cout << Point::MAXX << "," << Point::MAXY << endl;
    Point::showMax();

    //p2.setX(2000);  // exception

    return 0;
}
