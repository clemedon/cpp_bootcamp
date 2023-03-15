#ifndef CASTOR_HPP_
#define CASTOR_HPP_

#include <string>

/* limits */

#define FLOAT_MIN       std::numeric_limits<float>::lowest()
#define FLOAT_UNDERFLOW std::numeric_limits<float>::min()
#define FLOAT_MAX       std::numeric_limits<float>::max()

#define DOUBLE_MIN       std::numeric_limits<double>::lowest()
#define DOUBLE_UNDERFLOW std::numeric_limits<double>::min()
#define DOUBLE_MAX       std::numeric_limits<double>::max()

/* print.cpp */

/* convert.cpp */

bool isChar( const std::string& str );
bool isInt( const std::string& str );
bool isFloat( const std::string& str );
bool isDouble( const std::string& str );

/* tests.cpp */

void detect( void );
void tests( void );

#endif  // CASTOR_HPP_
