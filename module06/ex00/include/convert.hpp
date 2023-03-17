#ifndef CONVERT_HPP_
#define CONVERT_HPP_

#include <limits>
#include <string>

#define FLOAT_MIN -std::numeric_limits<float>::max()
#define FLOAT_MAX std::numeric_limits<float>::max()

#define DOUBLE_MIN -std::numeric_limits<double>::max()
#define DOUBLE_MAX std::numeric_limits<double>::max()

/* print.cpp */

void printChar( double doubleVal );
void printInt( double doubleVal );
void printFloat( double doubleVal );
void printDouble( double doubleVal );

/* convert.cpp */

void convertChar( std::string const& str, double& doubleVal );
void convertInt( std::string const& str, double& doubleVal );
void convertFloat( std::string const& str, double& doubleVal );
void convertDouble( std::string const& str, double& doubleVal );

/* detect.cpp */

bool detectChar( std::string const& str );
bool detectInt( std::string const& str );
bool detectFloat( std::string const& str );
bool detectDouble( std::string const& str );

/* main.cpp */

int main( int argc, char* argv[] );

#endif  // CONVERT_HPP_
