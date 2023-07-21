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

int threshold( int size ) {
  int threshold = 0;

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

/**
 * @brief       Sort the smaller subarrays
 *
 *  The insertion sort algorithm sort the subarrays within the [left, right]
 *  range.
 */

template <typename T>
void insertionSort( T& container, int left, int right ) {
  for( int i = left + 1; i <= right; ++i ) {
    typename T::value_type tempVal = container[i];
    int                    j = i - 1;

    while( j >= left && container[j] > tempVal ) {
      container[j + 1] = container[j];
      --j;
    }

    container[j + 1] = tempVal;
  }
}

template <typename T>
void merge( T& container, int left, int mid, int right ) {
  std::inplace_merge( container.begin() + left, container.begin() + mid + 1,
                      container.begin() + right + 1 );
}

/**
 * @brief       Groups the container's elements by pair.
 *
 *  Iterate over each elements and push adjacent elements into newContainer as
 *  pairs of [smallerValue, biggerValue].  If container's size is odd, the last
 *  element is added as unpaired.
 */

template <typename T>
void makePairs( T& container ) {
  size_t size = container.size();
  size_t pairs = size / 2;
  T      newContainer;

  for( size_t i = 0; i < pairs; ++i ) {
    if( container[2 * i + 1] < container[2 * i] ) {
      newContainer.push_back( container[2 * i + 1] );
      newContainer.push_back( container[2 * i] );
    } else {
      newContainer.push_back( container[2 * i] );
      newContainer.push_back( container[2 * i + 1] );
    }
  }
  if( size % 2 != 0 ) {
    newContainer.push_back( container[size - 1] );
  }
  container.swap( newContainer );
}

/**
 * @brief       Recursive sorting steps.
 *
 *  If the range [left, right] is smaller or equal to the threshold size calls
 *  the insertionSort function to sort the subrange using the insertion sort
 *  algorithm.
 *
 *  Otherwise, finds the middle of the range and recursively applies the
 *  mergeInsertSort function to the left and right subranges.
 *
 *  Finally, it performs the merge step by calling the merge function on the
 *  entire range.
 */

template <typename T>
void mergeInsertSort( T& container, int left = 0, int right = -1 ) {
  int mid;
  if( right == -1 ) {
    right = container.size() - 1;
  }

  if( right - left + 1 <= threshold( right - left + 1 ) ) {
    insertionSort( container, left, right );
  } else {
    mid = left + ( right - left ) / 2;
    mergeInsertSort( container, left, mid );
    mergeInsertSort( container, mid + 1, right );
    merge( container, left, mid, right );
  }
}

#endif  // PMERGEME_HPP
