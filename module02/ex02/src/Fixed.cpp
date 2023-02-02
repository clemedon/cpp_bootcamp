#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

/**
 * @brief       Default Constructor
 */

Fixed::Fixed( void ) : _rawBits( 0 ) {
  return;
}

/**
 * @brief       Parametric Constructor
 *
 * Converts an int to the corresponding fixed-point value
 */

Fixed::Fixed( int const& number )
  : _rawBits( number << Fixed::_fractionalBits ) {
  return;
}

/**
 * @brief       Parametric Constructor
 *
 * Converts a float to the corresponding fixed-point value
 * "number * ( 1 << _fractionalBits )" since bitshift doesnt work with float
 */

Fixed::Fixed( float const& number )
  : _rawBits( roundf( number * ( 1 << Fixed::_fractionalBits ) ) ) {
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
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Fixed::~Fixed( void ) {
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
  if( this != &rhs ) {
    this->_rawBits = rhs._rawBits;
  }
  return *this;
}

/**
 * @brief       Comparison operators
 */

bool Fixed::operator>( const Fixed& rhs ) const {
  return this->_rawBits > rhs._rawBits;
}

bool Fixed::operator<( const Fixed& rhs ) const {
  return this->_rawBits < rhs._rawBits;
}

bool Fixed::operator>=( const Fixed& rhs ) const {
  return this->_rawBits >= rhs._rawBits;
}

bool Fixed::operator<=( const Fixed& rhs ) const {
  return this->_rawBits <= rhs._rawBits;
}

bool Fixed::operator==( const Fixed& rhs ) const {
  return this->_rawBits == rhs._rawBits;
}

bool Fixed::operator!=( const Fixed& rhs ) const {
  return this->_rawBits != rhs._rawBits;
}

/**
 * @brief       Arithmetic operators
 */

Fixed Fixed::operator+( Fixed const& rhs ) const {
  return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed Fixed::operator-( Fixed const& rhs ) const {
  return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed Fixed::operator*( Fixed const& rhs ) const {
  return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/( Fixed const& rhs ) const {
  return Fixed( this->toFloat() / rhs.toFloat() );
}

/**
 * @brief       Pre/Post Increment/Decrement operators
 */

Fixed& Fixed::operator++( void ) {
  this->_rawBits += 1;
  return ( *this );
}

Fixed Fixed::operator++( int ) {
  Fixed temp( *this );

  ++( *this );
  return ( temp );
}

Fixed& Fixed::operator--( void ) {
  this->_rawBits -= 1;
  return ( *this );
}

Fixed Fixed::operator--( int ) {
  Fixed temp( *this );

  --( *this );
  return ( temp );
}

/**
 * @brief       Get/Set the raw value on the fixed point number
 */

int Fixed::getRawBits( void ) const {
  return this->_rawBits;
}

void Fixed::setRawBits( int const rawBits ) {
  this->_rawBits = rawBits;
  return;
}

/**
 * @brief       Converts fixed-point value to floating-point/int value
 *
 * @return      a floating-point value
 */

float Fixed::toFloat( void ) const {
  return static_cast<float>( this->_rawBits )
         / static_cast<float>( 1 << Fixed::_fractionalBits );
}

/**
 * @brief       Converts fixed-point value to int value
 *
 * @return      an int value
 */

float Fixed::toInt( void ) const {
  return this->_rawBits >> Fixed::_fractionalBits;
}

/**
 * @brief       Smallest/Greatest fixed-point number
 *
 * @param[in]   a a fixed-point number
 * @param[in]   b a fixed-point number
 * @return      smallest/greatest fixed-point number
 *
 * @see operator>() and operator<()
 */

Fixed Fixed::min( Fixed& a, Fixed& b ) {
  if( a < b ) {
    return a;
  }
  return b;
}

Fixed Fixed::min( Fixed const& a, Fixed const& b ) {
  if( a < b ) {
    return a;
  }
  return b;
}

Fixed Fixed::max( Fixed& a, Fixed& b ) {
  if( a > b ) {
    return a;
  }
  return b;
}

Fixed Fixed::max( Fixed const& a, Fixed const& b ) {
  if( a > b ) {
    return a;
  }
  return b;
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
