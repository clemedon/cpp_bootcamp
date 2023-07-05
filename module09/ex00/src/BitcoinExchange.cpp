/* src/BitcoinExchange */
/* Created: 230501 10:50:50 by clem@spectre */
/* Updated: 230705 14:45:00 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <cstdlib>
#include <fstream>
#include <iomanip>  // setprecision
#include <iostream>
#include <limits>  // numeric_limits
#include <sstream>
#include <string>

#include "BitcoinExchange.hpp"

/*  CANON
------------------------------------------------- */

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const std::string& csvFile ) {
  std::ifstream inputFile( csvFile.c_str() );
  if( !inputFile ) {
    throw std::runtime_error( "Error: Cannot open input file." );
  }

  std::string line;
  std::getline( inputFile, line );  // Skip the first line

  while( std::getline( inputFile, line ) ) {
    std::istringstream inputString( line );
    std::string        date;
    std::string        exchangeRate;

    if( std::getline( inputString, date, ',' )
        && std::getline( inputString, exchangeRate ) ) {
      double stringToDouble;

      std::istringstream exchangeRateStream( exchangeRate );
      if( !( exchangeRateStream >> stringToDouble ) ) {
        std::cout << "Error: invalid exchange rate format => " << exchangeRate;
        std::cout << "\n";
        continue;
      }

      _database.insert( std::make_pair( date, stringToDouble ) );
    }
  }

  inputFile.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const& src ) {
  _database = src._database;  // TODO copy or alias?
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange& BitcoinExchange::operator=( BitcoinExchange const& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  _database = rhs._database;  // TODO copy or alias?
  return *this;
}

/*  HELPER
------------------------------------------------- */

bool BitcoinExchange::isNum( const std::string str ) {
  for( unsigned long i = 0; i < str.length(); ++i ) {
    if( !std::isdigit( str[i] ) )
      return false;
  }
  return true;
}

bool BitcoinExchange::isValidNumber( const std::string& num ) {
  int  dotCount = 0;
  bool atLeastOneDigit = false;

  if( num.empty() )
    return false;
  for( unsigned long i = 0; i < num.length(); ++i ) {
    if( num[i] == '+' || num[i] == '-' ) {
      if( i != 0 )
        return false;
    } else if( num[i] == '.' ) {
      if( dotCount > 0 )
        return false;
      dotCount++;
    } else if( std::isdigit( num[i] ) ) {
      atLeastOneDigit = true;
    } else {
      std::cout << "Error: invalid value format => " << num << "\n";
      return false;
    }
  }
  if( !atLeastOneDigit )
    return false;
  return true;
}

bool BitcoinExchange::isLeap( long year ) {
  if( year % 400 == 0 )
    return true;
  else if( year % 100 == 0 )
    return false;
  else if( year % 4 == 0 )
    return true;
  else
    return false;
}

bool BitcoinExchange::isValidDate( const std::string& sub ) {
  std::string strYear, strMonth, strDay;
  long        year, month, day;
  char*       endptr;

  if( sub.length() != 10 || sub[4] != '-' || sub[7] != '-' ) {
    return false;
  }
  strYear = sub.substr( 0, 4 );
  strMonth = sub.substr( 5, 2 );
  strDay = sub.substr( 8, 2 );
  if( !isNum( strYear ) || !isNum( strMonth ) || !isNum( strDay ) ) {
    return false;
  }
  year = std::strtol( strYear.c_str(), &endptr, 10 );
  if( *endptr != '\0' ) {
    return false;
  }
  month = std::strtol( strMonth.c_str(), &endptr, 10 );
  if( *endptr != '\0' ) {
    return false;
  }
  day = std::strtol( strDay.c_str(), &endptr, 10 );
  if( *endptr != '\0' ) {
    return false;
  }
  if( month < 1 || month > 12 || day < 1 || day > 31 ) {
    return false;
  }
  if( month == 2 ) {
    if( isLeap( year ) ) {
      return ( day <= 29 );
    } else {
      return ( day <= 28 );
    }
  }
  if( month == 4 || month == 6 || month == 9 || month == 11 ) {
    return ( day > 30 );
  }
  return true;
}

/* ---------------------------------------------- */

void BitcoinExchange::exchange( const std::string& line ) {
  std::string::size_type                  delimiterPosition;
  std::string                             strValue;
  std::string                             date;
  double                                  value;
  std::map<std::string, double>::iterator previousElement;

  try {
    delimiterPosition = line.find( " | " );
    if( delimiterPosition == std::string::npos ) {
      throw std::runtime_error( "Error: bad input => " + line );
    }

    date = line.substr( 0, delimiterPosition );
    if( !isValidDate( date ) ) {
      throw std::runtime_error( "Error: invalid date format => " + date );
    }

    strValue = line.substr( delimiterPosition + 3 );
    if( !isValidNumber( strValue ) ) {
      throw std::runtime_error( "Error: invalid value format => " + strValue );
    }

    value = std::strtod( strValue.c_str(), NULL );
    if( value > 1000.0 ) {
      throw std::runtime_error( "Error: too large a number." );
    } else if( value < 0.0 ) {
      throw std::runtime_error( "Error: not a positive number." );
    }
    previousElement = _database.upper_bound( date );
    if( previousElement == _database.begin() ) {
      throw std::runtime_error( "Error: no data available before " + date );
    }
    --previousElement;

    double exchangeRate = previousElement->second;
    double exchangedValue = exchangeRate * value;
    exchangeRate = previousElement->second;
    exchangedValue = exchangeRate * value;
    std::cout << std::setprecision( std::numeric_limits<double>::digits10 );
    std::cout << date << " => " << value << " = " << exchangedValue << "\n";
  } catch( const std::runtime_error& e ) {
    std::cout << e.what() << std::endl;
  }
}

void BitcoinExchange::processInput( char* input ) {
  std::ifstream inputFile( input );  // Open input file
  try {
    if( inputFile.fail() ) {
      throw std::runtime_error( "Error: could not open file." );
    }
  } catch( const std::runtime_error& e ) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::string inputLine;
    std::getline( inputFile, inputLine );
    if( inputLine != "date | value" ) {
      std::cout << "Error: invalid file.\n";
      inputFile.close();
      exit( 1 );
    }
    while( std::getline( inputFile, inputLine ) ) {
      if( !inputLine.empty() ) {
        exchange( inputLine );
      }
    }
  } catch( const std::runtime_error& e ) {
    std::cout << e.what() << std::endl;
  }
  inputFile.close();
}
