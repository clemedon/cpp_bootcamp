#include <iostream>
#include "Canon.hpp"

int main() {
  Canon instance1;
  Canon instance2( instance1 );

  std::cout << instance1 << std::endl;
  std::cout << instance2 << std::endl;
  return 0;
}
