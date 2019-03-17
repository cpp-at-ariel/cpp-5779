/**
 * Demo program for the exercise on binary trees
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;

#include "Tree.hpp"

int main() {
  try {
    // constructs an empty tree:
    ariel::Tree emptytree;
    cout << "emptytree: size=" << emptytree.size() << endl; // should print 0
    
    // constructs an ordered binary tree where:
      // 5 is in the root;
      // 3 is the root's left child;
      // 7 is the root's right child.
    ariel::Tree threetree;
    threetree.insert(5);
    threetree.insert(7);
    threetree.insert(3);
    cout << "threetree: size=" << threetree.size() << " root=" << threetree.root() << endl << "   ";  // size=3, root=5.
    threetree.print();
    cout << endl;
      
    cout << threetree.size()      // should print 3
         << threetree.parent(3)   // should print 5
         << threetree.parent(7)   // should print 5
         << threetree.left(5)     // should print 3
         << threetree.right(5)    // should print 7
         << endl;
    threetree.insert(5);    // should throw an exception, since 5 already exists.
  } catch (...) {
    cout << "Caught exception!" << endl;
  }
}
