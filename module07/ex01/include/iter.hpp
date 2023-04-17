// @author    Clément Vidon
// @created   230417 15:42:47  by  clem@spectre
// @modified  230417 15:42:47  by  clem@spectre
// @filename  iter.hpp

#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter( T* arr, size_t len, F func ) {
  size_t i;

  for( i = 0; i < len; ++i ) {
    if( arr[i] ) {
      func( arr[i] );
    }
  }
  return;
}

template <typename T>
void print( T val ) {
  std::cout << val << "; ";
  return;
}

#endif  // ITER_HPP_
