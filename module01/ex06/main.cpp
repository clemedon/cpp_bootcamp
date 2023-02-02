#include <iostream>
#include <string>
#include "Karen.hpp"

int main( int ac, char** av ) {
  Karen karen;

  if( ac == 2 ) {
    karen.complain( av[1] );
  } else {
    return 1;
  }
  return 0;
}
