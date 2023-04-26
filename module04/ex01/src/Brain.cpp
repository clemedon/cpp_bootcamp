// @author    Clément Vidon
// @created   230324 15:30:25  by  clem@spectre
// @modified  230417 10:05:02  by  clem@spectre
// @filename  Brain.cpp

#include <iostream>
#include <string>

#include "Brain.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Brain::Brain( void ) : _size( 100 ), _ideas( new std::string[_size] ) {
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Brain::Brain( Brain const& src )
  : _size( src._size ),
    _ideas( new std::string[src._size] ) {
  size_t i;
  for( i = 0; i < _size; ++i ) {
    _ideas[i] = src._ideas[i];
  }
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

Brain::~Brain( void ) {
  delete[] _ideas;
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Brain& Brain::operator=( Brain const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  size_t i;
  if( this == &rhs ) {
    return *this;
  }
  delete[] _ideas;
  _ideas = new std::string[_size];
  for( i = 0; i < _size; ++i ) {
    _ideas[i] = rhs._ideas[i];
  }
  return *this;
}

/**
 * @brief       Print State
 */

void Brain::print( std::ostream& o ) const {
  o << "Brain";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Brain const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void Brain::printIdea( size_t index ) const {
  if( index < _size ) {
    std::cout << "(idea nᵒ" << index << ") " << _ideas[index];
    std::cout << std::endl;
  }
  return;
}

void Brain::saveIdea( size_t index, std::string const& idea ) {
  if( index < _size ) {
    _ideas[index] = idea;
  }
  return;
}
