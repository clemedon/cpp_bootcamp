#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>

#include "castor.hpp"

bool isChar( const std::string& str ) {
  if( str.length() == 3 && str[0] == '\'' && str[2] == '\'' ) {
    return true;
  } else if( str.length() == 1 && isdigit( str[0] ) == 0 ) {
    return true;
  }
  return false;
}

bool isInt( const std::string& str ) {
  char*    end;
  long int val;

  if( str[0] == '\0' ) {
    return false;
  }
  std::cout << str << std::endl;
  val = strtol( str.c_str(), &end, 10 );
  if( *end != '\0' || std::isnan( val ) ) {
    return false;
  }
  if( val < INT_MIN || val > INT_MAX ) {
    return false;
  }
  return true;
}

/* double box = 0.0; */
/* if( str[0] == '\0' ) { */
/*   return false; */
/* } */
/* try { */
/*   box = std::stod( str, &end ); */
/* } catch( const std::exception& ) { */
/*   std::cout << str << " Input is not a valid float. (1)" << std::endl; */
/*   return false; */
/* } */
/* if( box > std::numeric_limits<float>::max() ) { */
/*   std::cout << "Input is an overflow float." << std::endl; */
/*   return true; */
/* } else if( box < std::numeric_limits<float>::min() ) { */
/*   std::cout << "Input is an underflow float." << std::endl; */
/*   return true; */
/* } */
// Check for zero
//

bool isFloat( const std::string& str ) {
  size_t end = 0;
  float  val = 0.0f;

  try {
    val = std::stof( str, &end );

    if( ( str[end] != 'f' && str[end] != 'F' ) || str[end + 1] != '\0' ) {
      std::cout << str << " is not valid (1)" << std::endl;
      return false;
    }

    switch( fpclassify( val ) ) {
      case FP_INFINITE:
#ifdef DEBUG
        std::cout << str << " is overflow" << std::endl;
#endif
        return true;
      case FP_NAN:
#ifdef DEBUG
        std::cout << str << " is nanf" << std::endl;
#endif
        return true;
      case FP_SUBNORMAL:
#ifdef DEBUG
        std::cout << str << " is underflow" << std::endl;
#endif
        return true;
      case FP_ZERO:
#ifdef DEBUG
        std::cout << str << " is zero" << std::endl;
#endif
        return true;
      case FP_NORMAL: break;
    }

    /* if( str == "nanf" || str == "inff" || str == "-inff" || str == "inff" ) {
     */
    /*   std::cout << str << " is " << str << std::endl; */
    /*   return true; */
    /* } */

    if( std::isnan( val ) ) {
      std::cout << str << " is NaN" << std::endl;
      return true;
    } else if( val == 0.0f ) {
      std::cout << str << " is zero" << std::endl;
      return true;
    } else if( val > std::numeric_limits<float>::max() ) {
      std::cout << str << " is overflow" << std::endl;
      return true;
    } else if( val < std::numeric_limits<float>::lowest() ) {
      std::cout << str << " is underflow" << std::endl;
      return true;
    }

  } catch( const std::out_of_range& ) {
    if( val < FLOAT_UNDERFLOW && val > 0.0f ) {
      std::cout << str << " UNDERFLOW" << std::endl;
    } else {
      std::cout << str << " is out of range" << std::endl;
    }
    return false;
  } catch( const std::exception& ) {
    std::cout << str << " is not valid (2)" << std::endl;
    return false;
  }
  std::cout << str << " is valid" << std::endl;
  return true;
}

bool isDouble( const std::string& str ) {
  char*  end;
  double val;

  if( str == "inf" || str == "-inf" || str == "+inf" || str == "nan" ) {
    return true;
  }
  if( str[0] == '\0' ) {
    return false;
  }
  val = strtod( str.c_str(), &end );
  if( *end != '\0' || std::isnan( val ) ) {
    return false;
  }
  if( val < std::numeric_limits<double>::min()
      || val > std::numeric_limits<double>::max() ) {
    return false;
  }
  return true;
}
