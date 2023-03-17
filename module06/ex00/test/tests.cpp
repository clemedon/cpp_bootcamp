#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

#include "convert.hpp"

#define FLOAT_MIN       -std::numeric_limits<float>::max()
#define FLOAT_UNDERFLOW std::numeric_limits<float>::min()
#define FLOAT_MAX       std::numeric_limits<float>::max()

#define DOUBLE_MIN       -std::numeric_limits<double>::max()
#define DOUBLE_UNDERFLOW std::numeric_limits<double>::min()
#define DOUBLE_MAX       std::numeric_limits<double>::max()

std::string floatToString( float num ) {
  std::stringstream ss;
  std::string       str;

  ss << num;
  ss >> str;
  return str + "f";
}

std::string doubleToString( double num ) {
  std::stringstream ss;
  std::string       str;

  ss << num;
  ss >> str;
  return str;
}

void detect( void ) {
  assert( detectChar( "'!'" ) );
  assert( detectChar( "'1'" ) );
  assert( detectChar( "'\\'" ) );
  assert( detectChar( "1" ) );
  assert( !detectChar( " " ) );
  assert( !detectChar( "\\" ) );
  assert( !detectChar( "a" ) );
  assert( !detectChar( "Z" ) );
  assert( !detectChar( "" ) );
  assert( !detectChar( "''" ) );
  assert( !detectChar( "'ab'" ) );
  assert( !detectChar( "''''" ) );

  assert( detectInt( "123" ) );
  assert( detectInt( "-123" ) );
  assert( detectInt( "0" ) );
  assert( detectInt( "2147483647" ) );
  assert( detectInt( "-2147483648" ) );
  assert( detectInt( "2147483648" ) );
  assert( detectInt( "-2147483649" ) );
  assert( !detectInt( "" ) );
  assert( !detectInt( "hi" ) );
  assert( !detectInt( "-1.23" ) );
  assert( !detectInt( "0.f" ) );
  assert( !detectInt( "0.0" ) );
  assert( !detectInt( "--0" ) );
  assert( !detectInt( "nan" ) );

  assert( detectFloat( "0F" ) );
  assert( detectFloat( "1.23f" ) );
  assert( detectFloat( "nanf" ) );
  assert( detectFloat( "inff" ) );
  assert( detectFloat( "+inff" ) );
  assert( detectFloat( "-inff" ) );
  assert( detectFloat( "0.0f" ) );
  assert( detectFloat( "-.5f" ) );
  assert( detectFloat( "1.0e-4f" ) );
  assert( detectFloat( floatToString( FLOAT_MAX / 1.0001f ) ) );
  assert( detectFloat( floatToString( FLOAT_MIN / 1.0001f ) ) );
  assert( detectFloat( floatToString( FLOAT_UNDERFLOW * 1.0001f ) ) );
  assert( detectFloat( floatToString( FLOAT_MAX * 1.0001f ) ) );
  assert( detectFloat( floatToString( FLOAT_MIN * 1.0001f ) ) );
  assert( detectFloat( floatToString( FLOAT_UNDERFLOW / 1.0001f ) ) );
  assert( !detectFloat( "-1-f" ) );
  assert( !detectFloat( "10e5ef" ) );
  assert( !detectFloat( "e1f" ) );
  assert( !detectFloat( "nan" ) );
  assert( !detectFloat( "1.2.3f" ) );
  assert( !detectFloat( "1.23ff" ) );
  assert( !detectFloat( "abcf" ) );
  assert( !detectFloat( "" ) );
  assert( !detectFloat( "f" ) );

  assert( detectDouble( "0" ) );
  assert( detectDouble( "1.23" ) );
  assert( detectDouble( "nan" ) );
  assert( detectDouble( "inf" ) );
  assert( detectDouble( "+inf" ) );
  assert( detectDouble( "-inf" ) );
  assert( detectDouble( "0.0" ) );
  assert( detectDouble( "-.5" ) );
  assert( detectDouble( "1.0e-4" ) );
  assert( detectDouble( "3.14" ) );
  assert( detectDouble( "+0.0" ) );
  assert( detectDouble( "12345.6789" ) );
  assert( detectDouble( "1.0e-6" ) );
  assert( detectDouble( "-1.23" ) );
  assert( detectDouble( "1e10" ) );
  assert( detectDouble( "1" ) );
  assert( detectDouble( "-inf" ) );
  assert( detectDouble( doubleToString( DOUBLE_MAX / 1.0001 ) ) );
  assert( detectDouble( doubleToString( DOUBLE_MIN / 1.0001 ) ) );
  assert( detectDouble( doubleToString( DOUBLE_UNDERFLOW * 1.0001 ) ) );
  assert( detectDouble( doubleToString( DOUBLE_MAX * 1.0001 ) ) );
  assert( detectDouble( doubleToString( DOUBLE_MIN * 1.0001 ) ) );
  assert( detectDouble( doubleToString( DOUBLE_UNDERFLOW / 1.0001 ) ) );
  assert( !detectDouble( "3.14f" ) );
  assert( !detectDouble( "1ff" ) );
  assert( !detectDouble( "1.23.4f" ) );
  assert( !detectDouble( "-inff" ) );
  assert( !detectDouble( "nanf" ) );
  assert( !detectDouble( "" ) );
  assert( !detectDouble( "1a2.34f" ) );
  assert( !detectDouble( "1.23.4f" ) );
  assert( !detectDouble( "4.3f5" ) );

  std::cout << "All tests passed!" << std::endl;
}

void tests( void ) {
  detect();
}
