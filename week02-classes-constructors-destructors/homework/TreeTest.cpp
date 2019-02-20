/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "TestCase.hpp"
#include "Tree.h"

int main() {
  Tree emptytree;
  Tree threetree;  
  threetree.insert(5).insert(3).insert(7);
  
  TestCase("Binary tree")
  .CHECK_OK   (emptytree.insert(5))
  .CHECK_EQUAL(emptytree.size(), 1)
  .CHECK_EQUAL(emptytree.contains(5), true)
  .CHECK_OK   (emptytree.remove(5))
  .CHECK_EQUAL(emptytree.size() ,0)
  
  .CHECK_EQUAL(threetree.size(), 3)
  .CHECK_EQUAL(threetree.root(), 5)
  .CHECK_EQUAL(threetree.parent(3), 5)
  .CHECK_EQUAL(threetree.parent(7), 5)
  .CHECK_EQUAL(threetree.left(5), 3)
  .CHECK_EQUAL(threetree.right(5), 7)
  .CHECK_OK   (threetree.print())

  .print();
}
