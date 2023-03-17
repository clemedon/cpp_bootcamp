#include <cstdlib>
#include <string>

/**
 * Convert a string into its corresponding type's value.
 */

/**
 * @brief       Convert a string into a char.
 */

void convertChar( std::string const& str, double& doubleVal ) {
  int64_t val = 0;

  if( str.length() == 3 && str[0] == '\'' && str[2] == '\'' ) {
    doubleVal = static_cast<double>( str[1] );
  } else {
    val = strtoll( str.c_str(), NULL, 10 );
    doubleVal = static_cast<double>( val );
  }
  return;
}

/**
 * @brief       Convert a string into a int.
 */

void convertInt( std::string const& str, double& doubleVal ) {
  int64_t val = 0;

  val = strtoll( str.c_str(), NULL, 10 );
  doubleVal = static_cast<double>( val );
  return;
}

/**
 * @brief       Convert a string into a float.
 */

void convertFloat( std::string const& str, double& doubleVal ) {
  double val = 0.0;

  val = strtod( str.c_str(), NULL );
  doubleVal = static_cast<double>( val );
  return;
}

/**
 * @brief       Convert a string into a double.
 */

void convertDouble( std::string const& str, double& doubleVal ) {
  double val = 0.0;

  val = strtod( str.c_str(), NULL );
  doubleVal = static_cast<double>( val );
  return;
}
