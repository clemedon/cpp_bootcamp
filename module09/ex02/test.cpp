#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

// Step 1: 'Straggler' Catching
template <typename T>
bool hasStraggler(const T& container) {
  return container.size() % 2 != 0;
}

// Step 2: Creating Pairs
template <typename T>
std::vector<std::pair<typename T::value_type, typename T::value_type> >
createPairs(const T& container) {
  std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
  for (size_t i = 0; i < container.size() - 1; i += 2) {
    pairs.push_back(std::make_pair(container[i], container[i + 1]));
  }
  return pairs;
}

// Step 3: Sorting each pair
template <typename T>
void sortEachPair(T& pairs) {
  for (typename T::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    if (it->second < it->first) {
      std::swap(it->first, it->second);
    }
  }
}

// Step 4: Sort the Pair Sequence by its greater value
template <typename T>
void sortPairsByLargerValue(T& pairs) {
  std::sort(pairs.begin(), pairs.end(), std::greater<std::pair<typename T::value_type, typename T::value_type> >());
}

// Helper function for building Jacobsthal numbers sequence
int jacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Helper function for building insertion sequence
template <typename T>
std::vector<int> buildJacobInsertionSequence(const T& container) {
  std::vector<int> sequence;
  int pendSize = container.size() - 1;
  int jacobSize = std::ceil(std::log2(pendSize));
  for (int i = 0; i < jacobSize; ++i) {
    sequence.push_back(jacobsthal(i));
  }
  int remainingSize = pendSize - (1 << (jacobSize - 1)) + 1;
  for (int i = 0; i < remainingSize; ++i) {
    sequence.push_back(sequence[i] + (1 << (jacobSize - 1)));
  }
  return sequence;
}

// Step 5-9: Creating sorted 'S' sequence
template <typename T>
std::vector<typename T::value_type> createS(const std::vector<std::pair<typename T::value_type, typename T::value_type> >& pairs, const typename T::value_type& straggler) {
  std::vector<typename T::value_type> S;
  std::deque<typename T::value_type> pend;

  for (typename std::vector<std::pair<typename T::value_type, typename T::value_type> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
    S.push_back(it->second);
    pend.push_back(it->first);
  }

  // Step 5: Insert straggler if exists
  if (straggler != 0) {
    typename std::vector<typename T::value_type>::iterator insertPos = std::lower_bound(S.begin(), S.end(), straggler);
    S.insert(insertPos, straggler);
  }

  // Step 6: Build insertion sequence using Jacobsthal numbers
  std::vector<int> insertionSequence = buildJacobInsertionSequence(pend);

  // Step 7-9: Insert remaining elements using insertion sequence
  for (typename std::deque<typename T::value_type>::iterator it = pend.begin(); it != pend.end(); ++it) {
    typename std::vector<typename T::value_type>::iterator insertPos = S.begin() + insertionSequence.front();
    S.insert(insertPos, *it);
    insertionSequence.pop_back();
  }

  return S;
}

// Ford-Johnson Merge-Insert Sort
template <typename T>
void mergeInsertSort(T& container) {
  // Step 1: 'Straggler' Catching
  bool hasStragglerValue = hasStraggler(container);

  // Step 2: Creating Pairs
  std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs = createPairs(container);

  // Step 3: Sorting each pair
  sortEachPair(pairs);

  // Step 4: Sort the Pair Sequence by its greater value
  sortPairsByLargerValue(pairs);

  // Step 5-9: Creating sorted 'S' sequence
  typename T::value_type straggler = 0;
  if (hasStragglerValue) {
    straggler = container.back();
    container.pop_back();
  }
  std::vector<typename T::value_type> S = createS<T>(pairs, straggler);

  // Update container with the sorted sequence
  container.swap(S);
}

int main() {
  std::vector<int> vec; // or std::deque<int> vec;

  // Add elements to the vector/deque

  mergeInsertSort(vec);

  // Print the sorted vector/deque

  return 0;
}

