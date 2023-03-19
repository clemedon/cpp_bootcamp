#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate( void ) {
  int random;

  srand( static_cast<unsigned int>( time( NULL ) ) );
  random = rand() % 3;
  switch( random ) {
    case 0:
      std::cout << "A generated" << std::endl;
      return ( new A() );
    case 1:
      std::cout << "B generated" << std::endl;
      return ( new B() );
    case 2:
      std::cout << "C generated" << std::endl;
      return ( new C() );
  }
  return ( NULL );
}

/**
 * @brief       Identify Base pointer type
 */

void identify( Base* p ) {
  if( dynamic_cast<A*>( p ) ) {
    std::cout << "Base is an A pointer" << std::endl;
  } else if( dynamic_cast<B*>( p ) ) {
    std::cout << "Base is a B pointer" << std::endl;
  } else if( dynamic_cast<C*>( p ) ) {
    std::cout << "Base is a C pointer" << std::endl;
  } else {
    std::cout << "Base is an unknown pointer" << std::endl;
  }
  return;
}

/**
 * @brief       Identify Base reference type
 */

void identify( Base& p ) {
  try {
    dynamic_cast<A&>( p );
    std::cout << "Base is an A reference" << std::endl;
    return;
  } catch( ... ) {
  }

  try {
    dynamic_cast<B&>( p );
    std::cout << "Base is a B reference" << std::endl;
    return;
  } catch( ... ) {
  }

  try {
    dynamic_cast<C&>( p );
    std::cout << "Base is a C reference" << std::endl;
    return;
  } catch( ... ) {
  }
  std::cout << "Base is an unknown reference" << std::endl;
  return;
}

/**
 *  Here we use a dynamic_cast because it allows to test a down cast by
 *  returning NULL where applicable.
 *
 *  The dynamic_cast only works in the case of a polymorphic instance so our
 *  class must include at least one virtual function (here the destructor).
 *
 *  The dynamic_cast only works for pointer or reference casts.
 *
 *  Downcast from pointer to base class
 */

int main( void ) {
  Base* b = generate();

  identify( b );
  identify( *b );
  delete b;

  b = NULL;

  identify( b );
  return 0;
}
