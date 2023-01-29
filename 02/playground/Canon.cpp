#include <iostream>
#include <sstream>
#include <string>
#include "Canon.hpp"

/**
 * @brief       Default Constructor
 */

Canon::Canon (void) : _foo (0) {
  return;
}

/**
 * @brief       Parametric Constructor
 */

Canon::Canon (int const n) : _foo (n) {
  return;
}

/**
 * @brief       Copy Constructor
 *
 * Create a copy of the given object
 *
 * @param[in]   src the object to copy
 */

Canon::Canon (Canon const& src) {
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Canon::~Canon (void) {
  return;
}

/**
 * @brief       Assignment Operator
 *
 * Assigns value of one existing object to another existing object
 * They both share the same memory location
 *
 * @param[in]   src the object to copy
 * @return      a reference on src
 */

Canon& Canon::operator= (Canon const& src) {
  if (this != &src) {
    this->_foo = src._foo;
  }
  return *this;
}

/**
 * @brief       Print
 *
 * Print this object
 *
 * @param[out]  stream the destination where to print
 */

void Canon::print (std::ostream& stream) const {
  stream << "_foo : " << this->_foo;
  return;
}

/**
 * @brief       Serialize
 *
 * Return a string representation of this object
 *
 * @return      a string representation of the object
 */

std::string Canon::to_string (void) const {
  std::stringstream ss;

  this->print (ss);
  return ss.str ();
}

/**
 * @brief       Output Operator Overloading
 *
 * How the Output Operator should handle Canon
 *
 * @param[out]  os where to stream
 * @param[in]   canon what to stream
 * @return      the stream
 */

std::ostream& operator<< (std::ostream& os, Canon const& canon) {
  canon.print (os);
  return os;
}
