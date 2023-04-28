// @author    Clément Vidon
// @created   230417 15:42:47  by  clem@spectre
// @modified  230417 15:42:47  by  clem@spectre
// @filename  iter.hpp

#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>
#include <iostream>

/** TODO
 * template <typename T, typename F>
 * void iter( T* arr, size_t len, F func ) {
 */

template <typename T>
void iter( T* arr, size_t len, void ( *fun )( T & ) ) {
  size_t i;

  for( i = 0; i < len; ++i ) {
    fun( arr[i] );
  }
  return;
}

template <typename T>
void print( T& val ) {
  std::cout << val << "\n";
  return;
}

#endif  // ITER_HPP_
