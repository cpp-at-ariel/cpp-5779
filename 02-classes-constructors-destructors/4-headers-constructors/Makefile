#!make -f

CXX=clang++-5.0
CXXFLAGS=-std=c++17

all: a.out
	./a.out

a.out: Point.o PointTest.o Rectangle.o Triangle.o Circle.o
	$(CXX) $(CXXFLAGS) Point.o PointTest.o Rectangle.o Triangle.o Circle.o

Point.o: Point.cpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Point.cpp -o Point.o

Rectangle.o: Rectangle.cpp Rectangle.hpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Rectangle.cpp -o Rectangle.o

Circle.o: Circle.cpp Circle.hpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Circle.cpp -o Circle.o

Triangle.o: Triangle.cpp Triangle.hpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Triangle.cpp -o Triangle.o

PointTest.o: PointTest.cpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile PointTest.cpp -o PointTest.o

clean:
	rm *.o a.out
