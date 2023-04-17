// @author    Clément Vidon
// @created   230417 15:30:02  by  clem@spectre
// @modified  230417 15:30:02  by  clem@spectre
// @filename  Serializer.hpp

#ifndef SERIALIZE_HPP_
#define SERIALIZE_HPP_

#include <stdint.h>

class Data;

/**
 * Serialize and deserialize data.
 */

class Serializer {
 private:
  Serializer( void );
  Serializer( Serializer const& src );
  virtual ~Serializer( void );

 public:
  static uintptr_t serialize( Data* ptr );
  static Data*     deserialize( uintptr_t raw );
};

#endif  // SERIALIZE_HPP_
