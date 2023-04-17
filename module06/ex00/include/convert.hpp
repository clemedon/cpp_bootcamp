// @author    Clément Vidon
// @created   230417 15:27:51  by  clem@spectre
// @modified  230417 15:27:51  by  clem@spectre
// @filename  convert.hpp

#ifndef CONVERT_HPP_
#define CONVERT_HPP_

class string;

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
