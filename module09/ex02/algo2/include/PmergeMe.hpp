/* include/PmergeMe */
/* Created: 230705 17:29:52 by clem@spectre */
/* Updated: 230705 17:29:52 by clem@spectre */
/* Maintainer: Clément Vidon */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief     	Calculate threshold
 *
 *  Calculate the threshold value based on the size of the input array.
 *  The threshold is equal to the square root of the numbers array size.
 */

long unsigned int threshold( long unsigned int size ) {
  long unsigned int threshold = 0;

  while( ( threshold + 1 ) * ( threshold + 1 ) <= size ) {
    ++threshold;
  }
  return threshold;
}

template <typename T>
int binarySearch( const T&                      container,
                  int                           left,
                  int                           right,
                  const typename T::value_type& value ) {
  typename T::const_iterator pos = std::lower_bound(
    container.begin() + left, container.begin() + right + 1, value );
  return static_cast<int>( pos - container.begin() );
}

template <typename T>
void insertSort( T& container ) {
  typedef typename T::value_type value_type;

  for( typename T::size_type i = 1; i < container.size(); ++i ) {
    value_type           tempVal = container[i];
    typename T::iterator pos = std::upper_bound(
      container.begin(), container.begin() + i, tempVal );
    std::rotate( pos, container.begin() + i, container.begin() + i + 1 );
    *pos = tempVal;
  }
}

template <typename T>
void merge( T& first, T& last, T& dest ) {
  std::sort( first.begin(), first.end() );
  std::sort( last.begin(), last.end() );
  std::merge( first.begin(), first.end(), last.begin(), last.end(),
              dest.begin() );
}

template <typename T>
void mergeInsertSort( T& container ) {
  typename T::size_type size = container.size();

  if( size <= threshold( size ) ) {
    insertSort( container );
  } else {
    T first( container.begin(), container.begin() + size / 2 );
    T last( container.begin() + size / 2, container.end() );
    mergeInsertSort( first );
    mergeInsertSort( last );
    merge( first, last, container );
  }
}

#endif  // PMERGEME_HPP
