/**
 * Example file for the exercise on binary trees
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "TestCase.hpp"
#include "Tree.h"

void manual_tests() {
  try {
    Tree emptytree;
    cout << "emptytree: size=" << emptytree.size() << " root=" << emptytree.root() << endl;
    
    Tree threetree;
    threetree.insert(5).insert(3).insert(7);
    cout << "threetree: size=" << threetree.size() << " root=" << threetree.root() << " data=" << threetree << endl;
    // constructs an ordered binary tree where:
      // 5 is in the root;
      // 3 is the root's left child;
      // 7 is the root's right child.
      
    cout << threetree.size()      // should print 3
         << threetree.parent(3)   // should print 5
         << threetree.parent(7)   // should print 5
         << threetree.left(5)     // should print 3
         << threetree.right(5)    // should print 7
         << endl;
  } catch (...) {
    cout << "Caught exception!" << endl;
  }
}

void automatic_tests() {
    Tree emptytree;
    Tree threetree;  
    threetree.insert(5).insert(3).insert(7);
    
    TestCase("Binary tree")
    .CHECK_EQUAL(emptytree.size() ,0)
    .CHECK_OK   (emptytree.insert(5))
    .CHECK_EQUAL(emptytree.size(), 1)
    .CHECK_OK   (emptytree.remove(5))
    .CHECK_EQUAL(emptytree.size() ,0)
    
    .CHECK_EQUAL(threetree.size(), 3)
    .CHECK_EQUAL(threetree.parent(3), 5)
    .CHECK_EQUAL(threetree.parent(7), 5)
    .CHECK_EQUAL(threetree.left(5), 3)
    .CHECK_EQUAL(threetree.right(5), 7)
    .print();
}

int main() {
  cout << "manual tests: " << endl;
  manual_tests();
  cout << "automatic tests: " << endl;
  automatic_tests();
}
