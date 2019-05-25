#!python3

import cppyy

cppyy.cppdef("""
void say_hello() {
     std::cout << "Hello Python!" << std::endl;
}
""")

cppyy.gbl.say_hello()

print("Hello C++!")
