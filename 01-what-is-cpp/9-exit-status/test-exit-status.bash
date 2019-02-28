#!/bin/bash

clang++-5.0 return0.cpp; ./a.out
echo "Return value $?"

clang++-5.0 return111.cpp; ./a.out
echo "Return value $?"

./return0.bash
echo "Return value $?"

./return222.bash
echo "Return value $?"

