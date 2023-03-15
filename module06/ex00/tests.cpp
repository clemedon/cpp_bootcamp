#include <cassert>
#include <iostream>

#include "castor.hpp"

#include <cmath>
#include <iostream>
#include <limits>

#include <cfenv>
#include <iostream>

void detect( void ) {
  // valid
  assert( isFloat( "1.23f" ) );
  assert( isFloat( "nanf" ) );
  assert( isFloat( "inff" ) );
  assert( isFloat( "+inff" ) );
  assert( isFloat( "-inff" ) );
  assert( isFloat( "0.0f" ) );
  assert( isFloat( "-.5f" ) );
  assert( isFloat( "1.0e-4f" ) );

  assert( !isFloat( "-1-f" ) );
  assert( !isFloat( "10e5ef" ) );
  assert( !isFloat( "e1f" ) );
  assert( !isFloat( "1.2.3f" ) );
  assert( !isFloat( "1.23ff" ) );
  assert( !isFloat( "abcf" ) );
  assert( !isFloat( "f" ) );
  assert( !isFloat( "" ) );

  assert( isFloat( std::to_string( FLOAT_MAX ) + "f" ) );
  assert( isFloat( std::to_string( FLOAT_MIN ) + "f" ) );

  assert( !isFloat( "1.0e-45f" ) );

  assert( isFloat( std::to_string( FLOAT_MAX * 1.0001f ) + "f" ) );
  assert( isFloat( std::to_string( FLOAT_MIN * 1.0001f ) + "f" ) );
  assert( isFloat( std::to_string( FLOAT_UNDERFLOW * 1.0001f ) + "f" ) );
  return;

  //

  /* assert( isFloat( "3.40282e+38" ) );    // largest finite value for float */
  /* assert( isFloat( "-3.40282e+38" ) );   // smallest finite value for float
   */
  /* assert( !isFloat( "3.40283e+38" ) );   // overflow */
  /* assert( !isFloat( "-3.40283e+38" ) );  // underflow */

  /* assert( isDouble( "1.79769e+308" ) );   // max double value */
  /* assert( isDouble( "-1.79769e+308" ) );  // min double value */
  /* assert( !isDouble( "1.79770e+308" ) );   // overflow */
  /* assert( !isDouble( "-1.79770e+308" ) );  // underflow */

  /* std::cout << "tiptop" << std::endl; */
  /* return; */

  return;
  // CHAR
  assert( isChar( "a" ) );
  assert( isChar( "Z" ) );
  assert( isChar( "'!'" ) );
  assert( isChar( " " ) );
  assert( isChar( "'1'" ) );
  assert( !isChar( "1" ) );
  assert( !isChar( "" ) );
  assert( !isChar( "''" ) );
  assert( !isChar( "'ab'" ) );
  assert( !isChar( "''''" ) );

  // INT
  assert( isInt( "123" ) );
  assert( isInt( "-123" ) );
  assert( isInt( "0" ) );
  assert( isInt( "2147483647" ) );
  assert( isInt( "-2147483648" ) );
  assert( !isInt( "" ) );
  assert( !isInt( "hi" ) );
  assert( !isInt( "-1.23" ) );
  assert( !isInt( "2147483648" ) );
  assert( !isInt( "-2147483649" ) );

  // FLOAT
  assert( isFloat( "3.14f" ) );
  assert( isFloat( "0.0f" ) );
  assert( isFloat( "12345.6789f" ) );
  assert( isFloat( "1.0e-6f" ) );
  assert( isFloat( "-1.23f" ) );
  assert( isFloat( "1e10F" ) );
  assert( isFloat( "1.0F" ) );
  assert( isFloat( "1F" ) );
  assert( isFloat( "-inff" ) );
  assert( !isFloat( "1" ) );
  assert( !isFloat( "1ff" ) );
  assert( !isFloat( "1.23.4f" ) );
  assert( !isFloat( "-inf" ) );
  assert( !isFloat( "nan" ) );
  assert( !isFloat( "" ) );
  assert( !isFloat( "1a2.34f" ) );
  assert( !isFloat( "1.23.4f" ) );
  assert( !isFloat( "4.3f5" ) );

  // DOUBLES
  assert( isDouble( "3.14" ) );
  assert( isDouble( "+0.0" ) );
  assert( isDouble( "12345.6789" ) );
  assert( isDouble( "1.0e-6" ) );
  assert( isDouble( "-1.23" ) );
  assert( isDouble( "1e10" ) );
  assert( isDouble( "1" ) );
  assert( isDouble( "-inf" ) );
  assert( isDouble( "1" ) );
  assert( !isDouble( "3.14f" ) );
  assert( !isDouble( "1ff" ) );
  assert( !isDouble( "1.23.4f" ) );
  assert( !isDouble( "-inff" ) );
  assert( !isDouble( "nanf" ) );
  assert( !isDouble( "" ) );
  assert( !isDouble( "1a2.34f" ) );
  assert( !isDouble( "1.23.4f" ) );
  assert( !isDouble( "4.3f5" ) );

  std::cout << "All tests passed!" << std::endl;
}

void tests( void ) {
  detect();
}
