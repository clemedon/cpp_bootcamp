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
