#include <climits>
#include <cmath>
#include <iostream>
#include <string>

#include "convert.hpp"

/**
 * Cast and print a double as another type.
 */

/**
 * @brief       Cast and print a double as a char.
 */

void printChar( double doubleVal ) {
  char val;

  val = static_cast<char>( doubleVal );
  switch( std::fpclassify( doubleVal ) ) {
    case FP_NAN:
      std::cout << "char: impossible" << std::endl;
      break;
    case FP_INFINITE:
      std::cout << "char: impossible" << std::endl;
      break;
    default:
      if( doubleVal < CHAR_MIN || doubleVal > CHAR_MAX ) {
        std::cout << "char: overflow" << std::endl;
      } else {
        if( val < 32 || val > 126 ) {
          std::cout << "char: Non displayable" << std::endl;
        } else {
          std::cout << "char: '" << val << "'" << std::endl;
        }
      }
  }
  return;
}

/**
 * @brief       Cast and print a double as an int.
 */

void printInt( double doubleVal ) {
  int val;

  val = static_cast<int>( doubleVal );
  switch( std::fpclassify( doubleVal ) ) {
    case FP_NAN:
      std::cout << "int: impossible" << std::endl;
      break;
    case FP_INFINITE:
      std::cout << "int: impossible" << std::endl;
      break;
    default:
      if( doubleVal < INT_MIN || doubleVal > INT_MAX ) {
        std::cout << "int: overflow" << std::endl;
      } else {
        std::cout << "int: " << val << std::endl;
      }
  }
  return;
}

/**
 * @brief       Cast and print a double as a float.
 */

void printFloat( double doubleVal ) {
  float val;

  val = static_cast<float>( doubleVal );
  switch( std::fpclassify( doubleVal ) ) {
    case FP_NAN:
      std::cout << "float: nanf" << std::endl;
      break;
    case FP_INFINITE:
      std::cout << "float: " << val << "f" << std::endl;
      break;
    case FP_ZERO:
      std::cout << "float: " << val << "f" << std::endl;
      break;
    case FP_SUBNORMAL:
      std::cout << "float: underflow" << std::endl;
      break;
    default:
      std::cout << "float: " << val << "f" << std::endl;
  }
  return;
}

/**
 * @brief       Print a double.
 */

void printDouble( double doubleVal ) {
  double val;

  val = doubleVal;
  switch( std::fpclassify( doubleVal ) ) {
    case FP_NAN:
      std::cout << "double: nan" << std::endl;
      break;
    case FP_INFINITE:
      std::cout << "double: " << val << std::endl;
      break;
    case FP_ZERO:
      std::cout << "double: " << val << std::endl;
      break;
    case FP_SUBNORMAL:
      std::cout << "double: underflow" << std::endl;
      break;
    default:
      std::cout << "double: " << val << std::endl;
  }
  return;
}
