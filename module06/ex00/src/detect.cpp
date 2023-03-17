#include <cstdlib>
#include <string>

/**
 * Detect if a string represents a valid char, int float or double value.
 */

/**
 * @brief       Detect if a string correspond to a char value.
 */

int detectChar( std::string const& str ) {
  char* end = 0;

  if( str.length() == 3 && str[0] == '\'' && str[2] == '\'' ) {
    return true;
  }
  try {
    strtoll( str.c_str(), &end, 10 );
    if( end == str || *end != '\0' ) {
      throw std::exception();
    }
  } catch( std::exception const& ) {
    return false;
  }
  return true;
}

/**
 * @brief       Detect if a string correspond to a int value.
 */

bool detectInt( std::string const& str ) {
  char* end = 0;

  try {
    strtoll( str.c_str(), &end, 10 );
    if( end == str || *end != '\0' ) {
      throw std::exception();
    }
  } catch( std::exception const& ) {
    return false;
  }
  return true;
}

/**
 * @brief       Detect if a string correspond to a float value.
 */

bool detectFloat( std::string const& str ) {
  char* end = 0;

  try {
    strtod( str.c_str(), &end );
    if( end == str || ( *end != 'f' && *end != 'F' ) || *( end + 1 ) != '\0' ) {
      throw std::exception();
    }
  } catch( std::exception const& ) {
    return false;
  }
  return true;
}

/**
 * @brief       Detect if a string correspond to a double value.
 */

bool detectDouble( std::string const& str ) {
  char* end = 0;

  try {
    strtod( str.c_str(), &end );
    if( end == str || *end != '\0' ) {
      throw std::exception();
    }
  } catch( std::exception const& ) {
    return false;
  }
  return true;
}
