/**
 * @author    Clément Vidon
 * @brief     Array custom template.
 * @date      230319
 * @file      Array.hpp
 */

#ifndef ARRAY_HPP_
#  define ARRAY_HPP_

#  include <cstddef>
#  include <iostream>
#  include <string>

/**
 *  Generic Array
 */

template <class T>
class Array {
 public:
  Array( void );
  explicit Array( size_t size );
  Array( Array<T> const& src );
  virtual ~Array( void );
  Array<T>&    operator=( Array<T> const& rhs );
  virtual void print( std::ostream& o ) const;

  T&       operator[]( size_t index );
  const T& operator[]( size_t index ) const;
  size_t   size( void ) const;

 private:
  T*     _data;
  size_t _size;
};

/**
 * @brief       Output Operator Handling
 */

template <class T>
std::ostream& operator<<( std::ostream& o, Array<T> const& i ) {
  i.print( o );
  return o;
}

#endif  // ARRAY_HPP_

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

template <class T>
Array<T>::Array( void ) : _data( new T[0] ),
                          _size( 0 ) {
#if defined( DEBUG )
  std::cerr << "ARRAY CONSTRUCTOR" << std::endl;
#endif
  return;
}

/**
 * @brief       Parametric Constructor
 */

template <class T>
Array<T>::Array( size_t size ) : _data( new T[size] ),
                                 _size( size ) {
  size_t i;

#if defined( DEBUG )
  std::cerr << "ARRAY CONSTRUCTOR" << std::endl;
#endif
  for( i = 0; i < _size; ++i ) {
    _data[i] = T();
  }
  return;
}

/**
 * @brief       Copy Constructor
 */

template <class T>
Array<T>::Array( Array<T> const& src )
  : _data( new T[src._size] ),
    _size( src._size ) {
  size_t i;

#if defined( DEBUG )
  std::cerr << "ARRAY COPY CONSTRUCTOR" << std::endl;
#endif
  for( i = 0; i < _size; ++i ) {
    _data[i] = src._data[i];
  }
  return;
}

/**
 * @brief       Destructor
 */

template <class T>
Array<T>::~Array( void ) {
#if defined( DEBUG )
  std::cerr << "ARRAY DESTRUCTOR" << std::endl;
#endif
  delete[] _data;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

template <class T>
Array<T>& Array<T>::operator=( Array<T> const& rhs ) {
  size_t i;

  if( this == &rhs ) {
    return *this;
  }
  T* newData = new T[rhs._size];
  for( i = 0; i < rhs._size; ++i ) {
    newData[i] = rhs._data[i];
  }
  delete[] _data;
  _data = newData;
  _size = rhs._size;
  return *this;
}

/**
 * @brief       Print State
 */

template <class T>
void Array<T>::print( std::ostream& o ) const {
  size_t i;

  o << "Array " << this;
  std::cout << std::endl;
  for( i = 0; i < _size; ++i ) {
    o << "item_" << i;
    o << " → " << _data[i];
    std::cout << std::endl;
  }
  return;
}

/**
 * @brief       Output Operator Handling
 */

template <class T>
std::ostream& operator<<( std::ostream& o, Array<T> const& i );

/* ---------------------------------------------- */

/**
 * @brief       Access an element of the array using subscript operator
 */

template <class T>
T& Array<T>::operator[]( size_t index ) {
  if( index >= _size ) {
    throw std::exception();
  }
  return _data[index];
}

template <class T>
const T& Array<T>::operator[]( size_t index ) const {
  if( index >= _size ) {
    throw std::exception();
  }
  return _data[index];
}

/**
 * @brief       Return the size of the array.
 */

template <class T>
size_t Array<T>::size( void ) const {
  return _size;
}
