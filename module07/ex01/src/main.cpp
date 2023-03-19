#include "iter.hpp"

int main( void ) {
  int    test1[] = { 0, 1, 2, 3, 2, 1, 0 };
  float  test2[] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.2f, 0.1f, 0.0f };
  char   test3[] = { "hello" };
  size_t len;

  std::cout << "Test 1, <int> :" << std::endl;
  len = sizeof( test1 ) / sizeof( test2[0] );
  iter( test1, len, print<int> );

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Test 2, <float> :" << std::endl;
  len = sizeof( test2 ) / sizeof( test2[0] );
  iter( test2, len, print<float> );

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Test 3, <char> :" << std::endl;
  len = sizeof( test3 ) / sizeof( test3[0] );
  iter( test3, len, print<char> );
  return 0;
}
