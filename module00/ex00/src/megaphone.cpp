// @author    Clément Vidon
// @created   230324 11:39:10  by  clem@spectre
// @modified  230324 11:39:18  by  clem@spectre
// @filename  megaphone.cpp

#include <cctype>
#include <iostream>

int main( int argc, char* argv[] ) {
  int    i;
  size_t j;
  char   c;

  if( argc == 1 ) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for( i = 1; i < argc; ++i ) {
      for( j = 0; j < ( std::string( argv[i] ) ).length(); ++j ) {
        c = static_cast<char>( std::toupper( argv[i][j] ) );
        std::cout << c;
      }
    }
  }
  std::cout << std::endl;
  return 0;
}
