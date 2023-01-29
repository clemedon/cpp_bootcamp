#include <iostream>

int main () {
  std::string input;

  while (true) {
    std::cerr << "> ";

    if (!std::getline (std::cin, input)) {
      std::cerr << "failure" << std::endl;
      return 1;
    }
    if (input.empty ()) {
      continue;
    }
    break;
  }

  return 0;
}
