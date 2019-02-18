#include <iostream>
using std::cout, std::endl;
#include "TestCase.hpp"
#include "Tree.h"

void manual_tests() {
  try {
    Tree emptytree;
    cout << emptytree.size();   // should print 0
    
    Tree threetree;
    threetree.insert(5).insert(3).insert(7);
    // constructs an ordered binary tree where:
      // 5 is in the root;
      // 3 is the root's left child;
      // 7 is the root's right child.
      
    threetree.print();
    cout << threetree.size()      // should print 3
         << threetree.parent(3)   // should print 5
         << threetree.parent(7)   // should print 5
         << threetree.left(5)     // should print 3
         << threetree.right(5)    // should print 7
         << endl;
  } catch (string s) {
    cout << "Caught exception: " << s << endl;
  }
}

void automatic_tests() {
  TestCase testcase("Binary tree");
  try {
    Tree emptytree;
    Tree threetree;  
    threetree.insert(5).insert(3).insert(7);
    
    testcase
    .check_equal(emptytree.size() ,0)
    .check_ok   (emptytree.insert(5))
    .check_equal(emptytree.size(), 1)
    .check_ok   (emptytree.remove(5))
    .check_equal(emptytree.size() ,0)
    
    .check_equal(threetree.size(), 3)
    .check_equal(threetree.parent(3), 5)
    .check_equal(threetree.parent(7), 5)
    .check_equal(threetree.left(5), 3)
    .check_equal(threetree.right(5), 7);
  } catch (string s) {
    cout << "Caught exception: " << s << endl;
  }
  testcase.print();
}

int main() {
  manual_tests();
  automatic_tests();
}
