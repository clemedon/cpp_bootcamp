#include <cstring>
#include <iostream>

int main( int argc, char* argv[] ) {
  int    i;
  size_t j;

  if( argc == 1 ) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for( i = 1; i < argc; i++ ) {
      for( j = 0; j < ( (std::string)argv[i] ).length(); j++ ) {
        std::cout << (char)std::toupper( argv[i][j] ) << std::flush;
      }
    }
  }
  std::cout << std::endl;
  return 0;
}
