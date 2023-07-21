/* include/PmergeMe */
/* Created: 230705 17:29:52 by clem@spectre */
/* Updated: 230705 17:29:52 by clem@spectre */
/* Maintainer: Clément Vidon */

// Recursively sort the [n/2] larger elements from each pair, creating a sorted
// sequence S of [n/2] of the input elements, in ascending order.

// Insert at the start of S the element that was paired with the first and
// smallest element of S.

// Insert the remaining [n/2] − 1 elements of X ∖ S into S, one at a time, with
// a specially chosen insertion ordering described below. Use binary search in
// subsequences of S (as described below) to determine the position at which
// each element should be inserted.

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <vector>

long int straggler = -1;

/**
 * @brief       Utils. Print Pairs
 */

template <typename T>
void printUnits( const T& units ) {
  for( typename T::const_iterator it = units.begin(); it != units.end();
       it++ ) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printPairs( T& pairs ) {
  for( size_t i = 0; i < pairs.size(); ++i ) {
    std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "]\n";
  }
}

/**
 * @brief       3. Create Sequence
 */

template <typename T>
std::vector<typename T::value_type> createSequence(
  std::vector<std::pair<typename T::value_type, typename T::value_type> >&
    pairs ) {
  typedef typename T::value_type value_type;
  std::vector<long>              sequence;
  std::vector<long>              pend;

  typename std::vector<std::pair<value_type, value_type> >::iterator it;
  for( it = pairs.begin(); it != pairs.end(); ++it ) {
    if( it->first >= it->second ) {
      sequence.push_back( it->first );
      pend.push_back( it->second );
    } else {
      sequence.push_back( it->second );
      pend.push_back( it->first );
    }
  }
  // Insert the first element of pend at the first index of sequence
  if( !pend.empty() ) {
    sequence.insert( sequence.begin(), pend.front() );
  }
  // Insert the remaining elements of pend into sequence using lower_bound
  for( typename std::vector<value_type>::iterator it = pend.begin() + 1;
       it != pend.end(); ++it ) {
    typename std::vector<value_type>::iterator pos = std::lower_bound(
      sequence.begin(), sequence.end(), *it );
    sequence.insert( pos, *it );
  }
  if( straggler != -1 ) {
    typename std::vector<value_type>::iterator pos = std::lower_bound(
      sequence.begin(), sequence.end(), straggler );
    sequence.insert( pos, straggler );
  }
  pairs.clear();
  return sequence;
}

/**
 * @brief       2. Sort Pairs By Their Larger Units
 */

template <typename T>
bool sortPairBySecond(
  const std::pair<typename T::value_type, typename T::value_type>& a,
  const std::pair<typename T::value_type, typename T::value_type>& b ) {
  return a.second < b.second;
}

template <typename T>
void sortPairsBySecond(
  std::vector<std::pair<typename T::value_type, typename T::value_type> >&
    pairs ) {
  if( pairs.size() <= 1 )
    return;
  typedef typename T::value_type value_type;
  size_t                         mid = pairs.size() / 2;

  // Split the pairs into two halves
  std::vector<std::pair<value_type, value_type> > left(
    pairs.begin(), pairs.begin() + static_cast<long int>( mid ) );
  std::vector<std::pair<value_type, value_type> > right(
    pairs.begin() + static_cast<long int>( mid ), pairs.end() );

  // Sort each half recursively
  sortPairsBySecond<T>( left );
  sortPairsBySecond<T>( right );

  // Merge the two sorted halves
  std::merge( left.begin(), left.end(), right.begin(), right.end(),
              pairs.begin(), sortPairBySecond<T> );
}

/**
 * @brief       1. Create Pairs
 */

// Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving
// one element unpaired if there is an odd number of elements.
//
// Perform [n/2] comparisons, one per pair, to determine the larger of the two
// elements in each pair.

template <typename T>
std::vector<std::pair<typename T::value_type, typename T::value_type> >
  createPairs( T& units ) {
  std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
  size_t itemsCount = units.size();
  size_t pairsCount = itemsCount / 2;

  if( itemsCount % 2 != 0 ) {
    straggler = units[itemsCount - 1];
  }
  for( size_t i = 0; i < pairsCount; ++i ) {
    if( units[2 * i + 1] < units[2 * i] ) {
      pairs.push_back( std::make_pair( units[2 * i + 1], units[2 * i] ) );
    } else {
      pairs.push_back( std::make_pair( units[2 * i], units[2 * i + 1] ) );
    }
  }
  return pairs;
}

/**
 * @brief       0. START
 */

template <typename T>
std::vector<typename T::value_type> sort( T& units ) {
  typedef typename T::value_type                  value_type;
  std::vector<std::pair<value_type, value_type> > pairs;
  pairs = createPairs( units );
  sortPairsBySecond<std::vector<value_type, std::allocator<value_type> > >(
    pairs );
  return (
    createSequence<std::vector<value_type, std::allocator<value_type> > >(
      pairs ) );
}

#endif  // PMERGEME_HPP
