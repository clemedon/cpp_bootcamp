#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

void print_conversions( const std::string& str ) {
  double value = atof( str.c_str() );

  std::cout << "char: ";


  if( std::isnan( value ) ) {
    std::cout << "impossible" << std::endl;

  } else if( value == std::numeric_limits<char>::infinity()
             || value == -std::numeric_limits<char>::infinity() ) {
    std::cout << "impossible (overflow/underflow)\n";
  } else if( std::numeric_limits<double>::is_integer
             && ( value < 0 || value > 127 ) ) {
    std::cout << "impossible (overflow/underflow)\n";
  } else if( std::isprint( static_cast<int>( value ) ) ) {
    std::cout << "'" << static_cast<char>( value ) << "'\n";
  } else {
    std::cout << "Non displayable\n";
  }

  std::cout << "int: ";
  if( std::isnan( value ) ) { std::cout << "impossible" << std::endl;
  } else if( value == std::numeric_limits<int>::infinity() ) {
    std::cout << "impossible (overflow/underflow)\n";
  } else if( value == -std::numeric_limits<int>::infinity() ) {
    std::cout << "impossible (overflow/underflow)\n";
  } else if( value > std::numeric_limits<int>::max()
             || value < std::numeric_limits<int>::min() ) {
    std::cout << "impossible (overflow/underflow)\n";
  } else {
    std::cout << static_cast<int>( value ) << "\n";
  }

  std::cout << "float: ";
  if( std::isnan( value ) || std::isinf( value )
      || value > std::numeric_limits<float>::max()
      || value < std::numeric_limits<float>::lowest() ) {
    if( std::isnan( value ) ) {
      std::cout << "nanf\n";
    } else if( value == std::numeric_limits<float>::infinity() ) {
      std::cout << "+inff\n";
    } else if( value == -std::numeric_limits<float>::infinity() ) {
      std::cout << "-inff\n";
    } else {
      std::cout << "impossible (overflow/underflow)\n";
    }

  } else {
    std::cout << static_cast<float>( value ) << ".0f\n";
  }

  std::cout << "double: ";
  if( std::isnan( value ) || std::isinf( value )
      || value > std::numeric_limits<double>::max()
      || value < std::numeric_limits<double>::lowest() ) {
    if( std::isnan( value ) ) {
      std::cout << "nan\n";
    } else if( value == std::numeric_limits<double>::infinity() ) {
      std::cout << "+inf\n";
    } else if( value == -std::numeric_limits<double>::infinity() ) {
      std::cout << "-inf\n";
    } else {
      std::cout << "impossible (overflow/underflow)\n";
    }

  } else {
    std::cout << static_cast<double>( value ) << ".0\n";
  }
}

int main( int argc, char* argv[] ) {
  if( argc != 2 ) {
    std::cerr << "Usage: " << argv[0] << " <literal>\n";
    return 1;
  }

  std::string str( argv[1] );

  if( str.back() == 'f' ) {
    print_conversions( str.substr( 0, str.size() - 1 ) );
  } else {
    print_conversions( str );
  }

  return 0;
}
