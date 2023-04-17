// @author    Clément Vidon
// @created   230324 11:59:31  by  clem@spectre
// @modified  230324 11:59:32  by  clem@spectre
// @filename  Harl.cpp

#include <iostream>
#include <string>

#include "Harl.hpp"

Harl::Harl( void ) {
  return;
}

Harl::~Harl( void ) {
  return;
}

void Harl::debug( void ) {
  std::cout
    << "I love having extra bacon for my "
       "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
    << std::endl;
  return;
}

void Harl::info( void ) {
  std::cout
    << "I cannot believe adding extra bacon costs more money.  You didn’t put "
       "enough bacon in my burger!  If you did, I wouldn’t be asking for more!"
    << std::endl;
  return;
}

void Harl::warning( void ) {
  std::cout
    << "I think I deserve to have some extra bacon for free. I’ve been coming "
       "for years whereas you started working here since last month."
    << std::endl;
  return;
}

void Harl::error( void ) {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
  return;
}

void Harl::complain( std::string level ) {
  int         i;
  std::string level_ids[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
  void ( Harl::*level_functions[4] )( void )
    = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

  for( i = 0; i < 4; i++ ) {
    if( level.compare( level_ids[i] ) == 0 ) {
      ( this->*level_functions[i] )();
      return;
    }
  }
  std::cout << "*Harl is quiet*";
  return;
}
