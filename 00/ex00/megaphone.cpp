#include <cstring>
#include <iostream>

int main( int ac, char** av ) {
  int    i;
  size_t j;

  if( ac == 1 ) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for( i = 1; i < ac; i++ ) {
      for( j = 0; j < ( (std::string)av[i] ).length(); j++ ) {
        std::cout << (char)std::toupper( av[i][j] ) << std::flush;
      }
    }
  }
  std::cout << std::endl;
  return 0;
}
