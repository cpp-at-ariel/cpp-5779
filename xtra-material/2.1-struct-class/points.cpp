/**
 * Demonstrates structs and classes
 */

#include <iostream>
using namespace std;

/**
 *  A struct in C++ can have methods:
 */
struct Point1 {
    int x;
    int y;

    // This is not possible in C
    string to_string() {
        return "("+std::to_string(x)+","+std::to_string(y)+")";
    }
};

/**
 * A class is just a struct where the default accessibility is private.
 * So Point2 is entirely equivalent to Point1.
 */
class Point2 {
  public:
    int x;
    int y;

    // This is not possible in C
    string to_string() {
        return "("+std::to_string(x)+","+std::to_string(y)+")";
    }
};

/**
 * By default, members in a class are private.
 */
class Point3 {
    int x;
    int y;

  public:
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    // This is not possible in C
    string to_string() {
        return "("+std::to_string(x)+","+std::to_string(y)+")";
    }
};


int main() {
    Point1 p1;
    p1.x = 10;
    p1.y = 20;
    cout << p1.to_string() << endl;

    Point3 p3;
    cout << p3.to_string() << endl; // undefined values
    //p3.x = 10; // does not compile
    p3.setX(10);
    p3.setY(20);
    cout << p3.to_string() << endl;
    return 0;
}
