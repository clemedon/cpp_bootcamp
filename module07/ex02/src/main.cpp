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

void myTests() {
  size_t i;

  std::cout << "Creating an array of integers..." << std::endl;
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
    str_array_cpy[2] = "different";

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

int main( void ) {
  subjectTests();
  myTests();
  return 0;
}
