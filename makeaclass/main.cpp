#include "class.h"
#include <iostream>

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main() {
  // initialize class and run this file
  DumbClass dumb(1, 2);
  std::cout << dumb.getA() << std::endl;
  dumb.setA(7);
  std::cout << dumb.getA() << std::endl;
  return 0;
}
