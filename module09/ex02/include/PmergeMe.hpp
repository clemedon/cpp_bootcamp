/* include/PmergeMe */
/* Created: 230705 17:29:52 by clem@spectre */
/* Updated: 230705 17:29:52 by clem@spectre */
/* Maintainer: Clément Vidon */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <vector>

/**
 *  PmergeMe
 */

template <typename T>
class PmergeMe {
 private:
  typedef typename T::iterator Iterator;
  T                            _numbers;
  double                       _executionTime;

  PmergeMe( void );

 public:
  PmergeMe( const std::vector<std::string>& numbers );
  PmergeMe( const PmergeMe& src );
  ~PmergeMe();
  PmergeMe& operator=( const PmergeMe& rhs );

  T&     getNumbers( void );
  double getExecutionTime( void );

  void calculateExecutionTime( struct timeval start, struct timeval finish );
  long int calculateThreshold( long int size );
  void     insertionSort( Iterator& first, Iterator& last );
  void     merge( Iterator& first, Iterator& middle, Iterator& last );
  void     mergeInsertionSortFordJohnson( Iterator& first,
                                          Iterator& last,
                                          long int  threshold );
};

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Parametric Constructor
 */

template <typename T>
PmergeMe<T>::PmergeMe( const std::vector<std::string>& numbers ) {
  std::vector<std::string>::const_iterator it;
  long                                     num;
  Iterator                                 first, last;
  long int                                 threshold = 0;
  struct timeval                           start, finish;
  char*                                    endptr;

  for( it = numbers.begin(); it != numbers.end(); ++it ) {
    num = std::strtol( ( *it ).c_str(), &endptr, 10 );
    if( *endptr != '\0' || num < 0 ) {
      throw std::runtime_error( "Error" );
    } else {
      _numbers.push_back( num );
    }
  }
  first = _numbers.begin();
  last = _numbers.end();
  gettimeofday( &start, NULL );
  threshold = calculateThreshold( static_cast<long int>( _numbers.size() ) );
  mergeInsertionSortFordJohnson( first, last, threshold );
  gettimeofday( &finish, NULL );
  calculateExecutionTime( start, finish );
}

/**
 * @brief       Copy Constructor
 */

template <typename T>
PmergeMe<T>::PmergeMe( const PmergeMe& src ) {
  _numbers = src._numbers;
}

/**
 * @brief       Destructor
 */

template <typename T>
PmergeMe<T>::~PmergeMe( void ) {}

/**
 * @brief       Copy Assignment Operator
 */

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=( const PmergeMe& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  _numbers = rhs._numbers;
  return *this;
}

/*  ACCESSORS
------------------------------------------------- */

template <typename T>
T& PmergeMe<T>::getNumbers( void ) {
  return _numbers;
}

template <typename T>
double PmergeMe<T>::getExecutionTime( void ) {
  return _executionTime;
}

/*  HELPERS
------------------------------------------------- */

/**
 * @brief       Calculate algo execution time
 */

template <typename T>
void PmergeMe<T>::calculateExecutionTime( struct timeval start,
                                          struct timeval finish ) {
  double startTime, finishTime;

  startTime = static_cast<double>( start.tv_sec )
              + static_cast<double>( start.tv_usec ) * 1e-6;
  finishTime = static_cast<double>( finish.tv_sec )
               + static_cast<double>( finish.tv_usec ) * 1e-6;
  _executionTime = ( finishTime - startTime ) * 1e6;
}

/*  CORE LOGIC
------------------------------------------------- */

/**
 * @brief     	Calculate threshold
 *
 *  Calculate the threshold value based on the size of the input array.
 *  The threshold is equal to the square root of the numbers array size.
 */

template <typename T>
long int PmergeMe<T>::calculateThreshold( long int size ) {
  long int threshold = 0;

  while( ( threshold + 1 ) * ( threshold + 1 ) <= size ) {
    ++threshold;
  }
  return threshold;
}

/**
 * @brief       Sort the smaller subarrays
 *
 *  The insertion sort algorithm sort the subarrays within the specified range.
 */

template <typename T>
void PmergeMe<T>::insertionSort( Iterator& first, Iterator& last ) {
  for( Iterator it = first + 1; it != last; ++it ) {
    Iterator const insertion_point = std::upper_bound( first, it, *it );
    std::rotate( insertion_point, it, it + 1 );  // Shifting the unsorted part
  }
}

/**
 * @brief       Merge the sorted subarrays
 *
 *  Compare elements from the left and right subarrays and merge them into a
 *  single sorted array.
 */

template <typename T>
void PmergeMe<T>::merge( Iterator& first, Iterator& middle, Iterator& last ) {
  int rightSize = static_cast<int>( std::distance( middle, last ) );
  int right = 0;
  int left = 0;

  while( right < rightSize ) {
    if( middle[right] > first[left] )
      ++left;
    else {
      std::rotate( first + left, middle + right, middle + right + 1 );
      ++right;
    }
  }
}

/**
 * @brief       Split the range into smaller subarrays
 *
 *  Checks the size of the range and recursively splits it into smaller
 *  subarrays until the size is <= to the threshold value.
 */

template <typename T>
void PmergeMe<T>::mergeInsertionSortFordJohnson( Iterator& first,
                                                 Iterator& last,
                                                 long int  threshold ) {
  Iterator middle;

  if( std::distance( first, last ) <= threshold ) {
    insertionSort( first, last );
  } else {
    middle = first + ( std::distance( first, last ) / 2 );
    mergeInsertionSortFordJohnson( first, middle, threshold );
    mergeInsertionSortFordJohnson( middle, last, threshold );
    merge( first, middle, last );
  }
}

#endif  // PMERGEME_HPP
