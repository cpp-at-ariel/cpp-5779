#!bash
clang++-5.0 -std=c++17 --compile Complex.cpp -o Complex.o
clang++-5.0 -std=c++17 --compile main.cpp -o main.o
clang++-5.0 -std=c++17 Complex.o main.o
./a.out

