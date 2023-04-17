// @author    Clément Vidon
// @created   230324 12:03:29  by  clem@spectre
// @modified  230324 12:03:29  by  clem@spectre
// @filename  Fixed.cpp

#include <iostream>

#include "Fixed.hpp"

/*  STANDARD
------------------------------------------------- */

int const Fixed::_point = 8;

/**
 * @brief       Default Constructor
 */

Fixed::Fixed( void ) : _number( 0 ) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
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
 */

Fixed& Fixed::operator=( Fixed const& rhs ) {
  std::cout << "Copy assignment operator called" << std::endl;
  if( this != &rhs ) {
    std::cout << "getRawBits member function called" << std::endl;  // XXX
    _number = rhs._number;
  }
  return *this;
}

/* ---------------------------------------------- */

/**
 * @brief       Get the raw value of the fixed point number
 */

int Fixed::getRawBits( void ) const {
  std::cout << __func__ << " member function called" << std::endl;
  return _number;
}

/**
 * @brief       Set the raw value of the fixed point number
 */

void Fixed::setRawBits( int const raw ) {
  std::cout << __func__ << "member function called" << std::endl;
  _number = raw;
  return;
}
