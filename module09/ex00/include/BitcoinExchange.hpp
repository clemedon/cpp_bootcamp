/* include/BitcoinExchange */
/* Created: 230501 10:50:50 by clem@spectre */
/* Updated: 230705 14:45:07 by clem@spectre */
/* Maintainer: Clément Vidon */

#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <iosfwd>
#include <map>
#include <string>

class BitcoinExchange {
 private:
  std::map<std::string, double> _database;

  bool isNum( const std::string str );
  bool isValidNumber( const std::string& num );
  bool isLeap( long year );
  bool isValidDate( const std::string& sub );
  void exchange( const std::string& line );

 public:
  void processInput( char* input );

  BitcoinExchange( void );
  BitcoinExchange( std::string const& csvFile );
  BitcoinExchange( BitcoinExchange const& src );
  virtual ~BitcoinExchange( void );
  BitcoinExchange& operator=( BitcoinExchange const& rhs );
};

#endif  // BITCOINEXCHANGE_HPP_
