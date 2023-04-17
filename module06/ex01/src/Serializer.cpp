// @author    Clément Vidon
// @created   230417 15:29:59  by  clem@spectre
// @modified  230417 15:29:59  by  clem@spectre
// @filename  Serializer.cpp

#include <iostream>

#include "Data.hpp"

#include "Serializer.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Serializer::Serializer( void ) {
#if defined( DEV )
  std::cerr << __FILE__ << " CONSTRUCTED";
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

Serializer::Serializer( Serializer const& src ) {
  *this = src;
#if defined( DEV )
  std::cerr << __FILE__ << " COPY CONSTRUCTED";
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

Serializer::~Serializer( void ) {
#if defined( DEV )
  std::cerr << __FILE__ << " DESTRUCTED";
  std::cerr << std::endl;
#endif
  return;
}

/* ---------------------------------------------- */

/**
 * @brief       Convert a Data pointer into unsigned int
 */

uintptr_t Serializer::serialize( Data* ptr ) {
  return reinterpret_cast<uintptr_t>( ptr );
}

/**
 * @brief       Convert unsigned int into Data pointer
 */

Data* Serializer::deserialize( uintptr_t raw ) {
  return reinterpret_cast<Data*>( raw );
}
