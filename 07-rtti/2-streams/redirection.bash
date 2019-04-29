#!bash

clang++-5.0 --std=c++17 redirection.cpp -o redirection.exe

echo ---
./redirection.exe  
echo ---
./redirection.exe > out.txt
echo ---
./redirection.exe 2> err.txt
echo ---
./redirection.exe > out.txt 2> err.txt
echo ---
