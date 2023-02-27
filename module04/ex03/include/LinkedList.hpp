#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iosfwd>
#include <string>

/**
 * Linked list
 */

class LinkedList {
 public:
  LinkedList( void );
  LinkedList( LinkedList const& src );
  virtual ~LinkedList( void );
  LinkedList&  operator=( LinkedList const& rhs );
  virtual void print( std::ostream& o ) const;

 private:
};

std::ostream& operator<<( std::ostream& o, LinkedList const& i );

#endif  // LINKEDLIST_HPP_
