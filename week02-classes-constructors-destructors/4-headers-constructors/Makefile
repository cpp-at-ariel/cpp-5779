#!make -f

CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: a.out
	./a.out

a.out: Point.o PointTest.o
	$(CXX) $(CXXFLAGS) Point.o PointTest.o

Point.o: Point.cpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Point.cpp -o Point.o

PointTest.o: PointTest.cpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile PointTest.cpp -o PointTest.o

clean:
	rm *.o a.out
