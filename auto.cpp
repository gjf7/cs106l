#include <iostream>

int main (int argc, char *argv[]) {
  auto something = 1;
  auto& address = something;
  std::cout << address << std::endl;  
  return 0;
}
