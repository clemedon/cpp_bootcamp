// @author    Clément Vidon
// @created   230417 15:47:05  by  clem@spectre
// @modified  230417 15:47:50  by  clem@spectre
// @filename  main.cpp

#include "Array.hpp"

#include <cstdlib>
#include <iostream>

#define MAX_VAL 750

void subjectTests( void ) {
  size_t i;

  Array<int> numbers( MAX_VAL );
  int*       mirror = new int[MAX_VAL];
  srand( static_cast<unsigned int>( time( NULL ) ) );
  for( i = 0; i < MAX_VAL; i++ ) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test( tmp );
  }

  for( i = 0; i < MAX_VAL; i++ ) {
    if( mirror[i] != numbers[i] ) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return;
    }
  }
  try {
    numbers[static_cast<unsigned int>( -2 )] = 0;
  } catch( const std::exception& e ) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch( const std::exception& e ) {
    std::cerr << e.what() << '\n';
  }

  for( i = 0; i < MAX_VAL; i++ ) {
    numbers[i] = rand();
  }
  delete[] mirror;  //
  return;
}

void myTests( void ) {
  size_t i;

  std::cout << "Creating an empty integers array..." << std::endl;
  Array<size_t> uint_empty_array( 0 );

  std::cout << "Creating an array of 5 integers..." << std::endl;
  Array<size_t> uint_array( 5 );

  std::cout << "Setting values of the array..." << std::endl;
  for( i = 0; i < uint_array.size(); i++ ) {
    uint_array[i] = i;
  }

  std::cout << "Printing the array..." << std::endl;
  std::cout << uint_array << std::endl;

  std::cout << "Creating an array of strings..." << std::endl;
  Array<std::string> str_array( 3 );
  Array<std::string> str_array_cpy( str_array );
  try {
    std::cout << "Setting values of the array..." << std::endl;
    str_array[0] = "Hello";
    str_array[1] = "World";
    str_array[2] = "!";

    str_array_cpy[0] = "I";
    str_array_cpy[1] = "am";
    str_array_cpy[2] = "there";

    std::cout << "Printing the arrays..." << std::endl;
    std::cout << str_array << std::endl;
    std::cout << str_array_cpy << std::endl;

  } catch( const std::exception& e ) {
    std::cerr << e.what() << '\n';
  }
  try {
    str_array[3] = "salut";
  } catch( const std::exception& e ) {
    std::cerr << e.what() << '\n';
  }
  return;
}

class CT { // Complex Type
  public:
    CT( void ) : _a( 0 ), _b( 0.0 ) {}
    CT( int a, float b ) : _a( a ), _b( b ) {
      return;
    }
    void print( std::ostream& o ) const {
      o << _a << ", ";
      o << _b << std::endl;
      return;
    }

    int   _a;
    float _b;
};

std::ostream& operator<<( std::ostream& o, CT const& i ) {
  i.print ( o );
  return o;
}

void ct( void ) {
  Array<CT> ct( 3 );

  std::cout << "Complex Type" << std::endl;

  Array<int> numbers( MAX_VAL );
  CT a( 1, 9.0 );
  CT b( 2, 8.0 );
  CT c( 3, 7.0 );
  ct[0] = a;
  ct[1] = b;
  ct[2] = c;

  std::cout << "Printing the array..." << std::endl;
  std::cout << ct << std::endl;
  std::cout << "Reading an element..." << std::endl;
  std::cout << "ct[1] = " << ct[1] << std::endl;
  std::cout << "Writing an element..." << std::endl;
  std::cout << "ct[1]._a = 42" <<  std::endl;
  ct[1]._a = 42;
  std::cout << "Reading an element..." << std::endl;
  std::cout << "ct[1] = " << ct[1] << std::endl;

  try {
    std::cout << "Accessing out of range element..." << std::endl;
    std::cout << "ct[4]" << std::endl;
    std::cout << ct[4] << std::endl;
  } catch( const std::exception& e ) {
    std::cerr << e.what() << '\n';
  }

  return;
}




int main( void ) {
  subjectTests();
  myTests();
  ct();
  return 0;
}
