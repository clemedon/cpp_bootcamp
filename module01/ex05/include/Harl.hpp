// @author    Clément Vidon
// @created   230324 11:59:23  by  clem@spectre
// @modified  230324 11:59:25  by  clem@spectre
// @filename  Harl.hpp

#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  Harl( void );
  ~Harl( void );

  void complain( std::string level );

 private:
  void debug( void );
  void info( void );
  void warning( void );
  void error( void );
};

#endif  // HARL_HPP_
