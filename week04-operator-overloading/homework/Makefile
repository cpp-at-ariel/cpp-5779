CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: main.o CircularInt.o
	$(CXX) $(CXXFLAGS) CircularInt.o main.o
	./a.out

CircularInt.o: CircularInt.cpp CircularInt.hpp
	$(CXX) $(CXXFLAGS) -c CircularInt.cpp -o CircularInt.o

main.o: main.cpp CircularInt.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out
