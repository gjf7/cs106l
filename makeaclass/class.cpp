// Blank cpp file
#include "class.h"

DumbClass::DumbClass(int a, int b): a(a), b(b) {};

int DumbClass::getA() {
  return a;
}

void DumbClass::setA(int a) {
  (*this).a = a;
}

