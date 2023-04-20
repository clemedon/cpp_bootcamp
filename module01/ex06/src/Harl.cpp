// @author    Clément Vidon
// @created   230324 12:02:28  by  clem@spectre
// @modified  230420 19:10:40  by  clem@spectre
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
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
    << "I love having extra bacon for my "
       "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
    << std::endl;
  std::cout << std::endl;
  return;
}

void Harl::info( void ) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money.  You "
               "didn’t put "
               "enough bacon in my burger!  If you did, I wouldn’t be asking "
               "for more!"
            << std::endl;
  std::cout << std::endl;
  return;
}

void Harl::warning( void ) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve "
               "been coming "
               "for years whereas you started working here since last month."
            << std::endl;
  std::cout << std::endl;
  return;
}

void Harl::error( void ) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
  std::cout << std::endl;
  return;
}

void Harl::complain( std::string level ) {
  int i = 0;

  std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
  void ( Harl::*levelPtr[4] )()
    = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
  for( ; i < 4 && level != levels[i]; ++i )
    ;
  switch( i ) {
    case 0:
      ( this->*levelPtr[i++] )();
    case 1:
      ( this->*levelPtr[i++] )();
    case 2:
      ( this->*levelPtr[i++] )();
    case 3:
      ( this->*levelPtr[i] )();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
      break;
  }
}
