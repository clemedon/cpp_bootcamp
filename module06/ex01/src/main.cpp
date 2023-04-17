// @author    Clément Vidon
// @created   230417 15:29:58  by  clem@spectre
// @modified  230417 15:36:12  by  clem@spectre
// @filename  main.cpp

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

/**
 *  The subject mentions that we have to use a "static class Serializer with the
 *  following methods".
 *  The concept of "static class" does not exist in c++ and it cannot mean a
 *  class comprising only static members since a "the following methods" is
 *  requested, and a method corresponding to an virtual member it cannot be
 *  static.
 *
 *  I decided to create a Serializer with static member functions so I can use
 *  them without needing to instantiate my class.
 *
 *  I choose to use the reinterpret_cast because it is the most permissive, it
 *  allows downcast and therefore it is the most suitable for retyping
 *  information that comes without its type.
 */

int main( void ) {
  Data      data( 42, 42.0f, '*' );
  uintptr_t s;
  Data*     d;

  s = Serializer::serialize( &data );
  d = Serializer::deserialize( s );

  if( d == &data ) {
    std::cout << "Success" << std::endl;
  } else {
    std::cout << "Failure" << std::endl;
  }
  std::cout << data << std::endl;
  std::cout << "data:         " << &data << std::endl;
  std::cout << "serialized:   " << std::hex << std::showbase << s << std::endl;
  std::cout << "deserialized: " << d << std::endl;
  return 0;
}
