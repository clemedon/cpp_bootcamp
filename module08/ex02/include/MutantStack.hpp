#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <iostream>
#include <stack>
#include <vector>

/**
 *  Generic Stack
 */

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

  MutantStack( void );
  explicit MutantStack( std::stack<T> const& s );
  MutantStack( MutantStack<T> const& src );
  virtual ~MutantStack( void );
  MutantStack<T>& operator=( MutantStack<T> const& rhs );
  virtual void    print( std::ostream& o ) const;

  iterator               begin();
  const_iterator         begin() const;
  iterator               end();
  const_iterator         end() const;
  reverse_iterator       rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator       rend();
  const_reverse_iterator rend() const;
};

/**
 * @brief       Output Operator Handling
 */

template <typename T>
std::ostream& operator<<( std::ostream& o, MutantStack<T> const& i );

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

template <typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {
#if defined( DEV )
  std::cerr << "MUTANTSTACK CONSTRUCTOR" << std::endl;
#endif
  return;
}

/**
 * @brief       Parametric Constructor
 */

template <typename T>
MutantStack<T>::MutantStack( std::stack<T> const& s ) : std::stack<T>( s ) {
#if defined( DEV )
  std::cerr << "MUTANTSTACK CONSTRUCTOR" << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

template <typename T>
MutantStack<T>::MutantStack( MutantStack<T> const& src )
  : std::stack<T>( src ) {
#if defined( DEV )
  std::cerr << "MUTANTSTACK COPY CONSTRUCTOR" << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

template <typename T>
MutantStack<T>::~MutantStack( void ) {
#if defined( DEV )
  std::cerr << "MUTANTSTACK DESTRUCTOR" << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( MutantStack<T> const& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  std::stack<T>::operator=( rhs );
  return *this;
}

/**
 * @brief       Print State
 */

template <typename T>
void MutantStack<T>::print( std::ostream& o ) const {
  typename MutantStack<T>::const_iterator it;

  std::cout << "MutantStack" << std::endl;
  for( it = this->c.begin(); it != this->c.end(); ++it ) {
    o << *it << "; ";
  }
  o << std::endl;
  return;
}

/**
 * @brief       Output Operator Handling
 */

template <typename T>
std::ostream& operator<<( std::ostream& o, MutantStack<T> const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void ) {
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin( void ) const {
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void ) {
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end( void ) const {
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin( void ) {
  return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(
  void ) const {
  return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend( void ) {
  return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(
  void ) const {
  return this->c.rend();
}

#endif  // MUTANTSTACK_HPP_
