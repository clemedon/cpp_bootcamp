#include "Fixed.hpp"

/**
 * @brief       Default Constructor
 */

Fixed::Fixed( void ) : _number( 0 ) {
  std::cout << "Default constructor called" << std::endl;
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
 * @param[in]   src the object to copy
 * @return      a reference on src
 */

Fixed& Fixed::operator=( Fixed const& src ) {
  std::cout << "Copy assignment operator called" << std::endl;
  if( this != &src ) {
    std::cout << "getRawBits member function called" << std::endl;  // XXX
    this->_number = src._number;
  }
  return *this;
}

/**
 * @brief       Get the raw value of the fixed point number
 */

int Fixed::getRawBits( void ) const {
  std::cout << __func__ << " member function called" << std::endl;
  return this->_number;
}

/**
 * @brief       Set the raw value of the fixed point number
 */

void Fixed::setRawBits( int const raw ) {
  std::cout << __func__ << "member function called" << std::endl;
  this->_number = raw;
  return;
}
