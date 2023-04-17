// @author    Clément Vidon
// @created   230417 15:41:21  by  clem@spectre
// @modified  230417 15:41:21  by  clem@spectre
// @filename  whatever.hpp

#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

template <typename T>
const T& min( const T& a, const T& b ) {
  if( a < b ) {
    return ( a );
  }
  return ( b );
}

template <typename T>
const T& max( const T& a, const T& b ) {
  if( a > b ) {
    return ( a );
  }
  return ( b );
}

template <typename T>
void swap( T& a, T& b ) {
  T temp;

  temp = a;
  a = b;
  b = temp;
  return;
}

#endif  // WHATEVER_HPP_
