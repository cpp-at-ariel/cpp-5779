#!make -f

# CXX=clang++-5.0
# CXXFLAGS=-std=c++17

all: a.out
	./a.out

a.out: Point.o main.o Rectangle.o Triangle.o Circle.o
	clang++-5.0 -std=c++17 Point.o main.o Rectangle.o Triangle.o Circle.o

Point.o: Point.cpp Point.hpp
	clang++-5.0 -std=c++17 --compile Point.cpp -o Point.o

Rectangle.o: Rectangle.cpp Rectangle.hpp Point.hpp
	clang++-5.0 -std=c++17 --compile Rectangle.cpp -o Rectangle.o

Circle.o: Circle.cpp Circle.hpp Point.hpp
	clang++-5.0 -std=c++17 --compile Circle.cpp -o Circle.o

Triangle.o: Triangle.cpp Triangle.hpp Point.hpp
	clang++-5.0 -std=c++17 --compile Triangle.cpp -o Triangle.o

main.o: main.cpp Point.hpp
	clang++-5.0 -std=c++17 --compile main.cpp -o main.o

clean:
	rm -f *.o a.out
