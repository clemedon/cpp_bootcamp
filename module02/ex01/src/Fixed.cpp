// @author    Clément Vidon
// @created   230324 12:11:44  by  clem@spectre
// @modified  230324 12:11:44  by  clem@spectre
// @filename  Fixed.cpp

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

/**
 * @brief       Default Constructor
 */

Fixed::Fixed( void ) : _rawBits( 0 ) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

/**
 * @brief       Parametric Constructor
 *
 * Converts an int to the corresponding fixed-point value
 */

Fixed::Fixed( int const& number ) : _rawBits( number << _fractionalBits ) {
  std::cout << "Int constructor called" << std::endl;
  return;
}

/**
 * @brief       Parametric Constructor
 *
 * Converts a float to the corresponding fixed-point value
 */

Fixed::Fixed( float const& number )
  : _rawBits(
    static_cast<int>( roundf( number * ( 1 << _fractionalBits ) ) ) ) {
  std::cout << "Float constructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 *
 * Create a copy of the given object
 * They both use different memory location
 *
 * @param[in]   src the object to copy
 */

Fixed::Fixed( Fixed const& src ) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Fixed::~Fixed( void ) {
  std::cout << "Destructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 *
 * Assigns value of one existing object to another existing object
 * They both share the same memory location
 *
 * @param[in]   rhs the object to copy
 * @return      a reference on rhs
 */

Fixed& Fixed::operator=( Fixed const& rhs ) {
  std::cout << "Copy assignment operator called" << std::endl;
  if( this != &rhs ) {
    _rawBits = rhs._rawBits;
  }
  return *this;
}

/**
 * @brief       Get/Set the raw value on the fixed point number
 */

int Fixed::getRawBits( void ) const {
  return _rawBits;
}

void Fixed::setRawBits( int const rawBits ) {
  _rawBits = rawBits;
  return;
}

/**
 * @brief       Converts fixed-point value to floating-point value
 *
 * @return      a floating-point value
 */

float Fixed::toFloat( void ) const {
  return static_cast<float>( _rawBits )
         / static_cast<float>( 1 << _fractionalBits );
}

/**
 * @brief       Converts fixed-point value to int value
 *
 * @return      an int value
 */

int Fixed::toInt( void ) const {
  return _rawBits >> _fractionalBits;
}

/**
 * @brief       Output Operator Overloading
 *
 * Inserts a floating-point representation of the fixed-point number into the
 * output stream object passed as a parameter
 *
 * @param[out]  os where to stream
 * @param[in]   i what to stream
 * @return      the stream
 */

std::ostream& operator<<( std::ostream& os, Fixed const& i ) {
  os << i.toFloat();
  return os;
}
