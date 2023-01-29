#include <iostream>
#include <string>

int main() {
  std::string  string = "HI THIS IS BRAIN";
  std::string* stringPTR = &string;
  std::string& stringREF = string;

  std::cout << "Addr\t" << &string << std::endl;
  std::cout << "Addr\t" << stringPTR << std::endl;
  std::cout << "Addr\t" << &stringREF << std::endl;
  std::cout << "Valu\t" << string << std::endl;
  std::cout << "Valu\t" << *stringPTR << std::endl;
  std::cout << "Valu\t" << stringREF << std::endl;
  return 0;
}
