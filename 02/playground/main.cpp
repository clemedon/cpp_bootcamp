#include <iostream>
#include "Canon.hpp"

int main () {
  Canon instance1;
  Canon instance2 (42);  // TODO
  Canon instance3 (instance1);

  std::cout << instance1 << std::endl;
  std::cout << instance2 << std::endl;
  std::cout << instance3 << std::endl;
  instance3 = instance2;
  std::cout << instance3 << std::endl;
  std::string canon_str = instance3.to_string();
  std::cout << "tostring: " << canon_str << std::endl;
  std::string test;

  return 0;
}
