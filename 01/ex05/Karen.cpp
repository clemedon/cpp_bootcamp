#include <iostream>
#include <string>
#include "Karen.hpp"

Karen::Karen( void ) {
}

Karen::~Karen( void ) {
}

void Karen::debug( void ) {
  std::cout
    << "I love having extra bacon for my "
       "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
    << std::endl;
}

void Karen::info( void ) {
  std::cout
    << "I cannot believe adding extra bacon costs more money.  You didn’t put "
       "enough bacon in my burger!  If you did, I wouldn’t be asking for more!"
    << std::endl;
}

void Karen::warning( void ) {
  std::cout
    << "I think I deserve to have some extra bacon for free. I’ve been coming "
       "for years whereas you started working here since last month."
    << std::endl;
}

void Karen::error( void ) {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Karen::complain( std::string level ) {
  int         i;
  std::string level_ids[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
  void ( Karen::*level_functions[4] )( void )
    = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error };

  for( i = 0; i < 4; i++ ) {
    if( level.compare( level_ids[i] ) == 0 ) {
      ( this->*level_functions[i] )();
      return;
    }
  }
  std::cout << "*Karen is quiet*";
}
