#!python3

import cppyy
cppyy.include("hello.hpp")
cppyy.gbl.say_hello()
print("Hello C++!")

