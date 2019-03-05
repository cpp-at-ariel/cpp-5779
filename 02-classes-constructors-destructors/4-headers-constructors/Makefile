#!make -f

# CXX=clang++-5.0
# CXXFLAGS=-std=c++17

all: a.out
	./a.out

a.out: Point.o PointArrayTest.o Rectangle.o Triangle.o Circle.o
	clang++-5.0 -std=c++17 Point.o PointArrayTest.o Rectangle.o Triangle.o Circle.o

Point.o: Point.cpp Point.hpp
	clang++-5.0 -std=c++17 --compile Point.cpp -o Point.o

Rectangle.o: Rectangle.cpp Rectangle.hpp Point.hpp
	clang++-5.0 -std=c++17 --compile Rectangle.cpp -o Rectangle.o

Circle.o: Circle.cpp Circle.hpp Point.hpp
	clang++-5.0 -std=c++17 --compile Circle.cpp -o Circle.o

Triangle.o: Triangle.cpp Triangle.hpp Point.hpp
	clang++-5.0 -std=c++17 --compile Triangle.cpp -o Triangle.o

PointTest.o: PointTest.cpp Point.hpp
	clang++-5.0 -std=c++17 --compile PointTest.cpp -o PointTest.o

PointArrayTest.o: PointArrayTest.cpp Point.hpp
	clang++-5.0 -std=c++17 --compile PointArrayTest.cpp -o PointArrayTest.o

clean:
	rm -f *.o a.out
