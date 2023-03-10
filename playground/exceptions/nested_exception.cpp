/**
 * @author    Clément Vidon
 * @brief     Example of exceptions that inherits from a common message prefix.
 * @date      230310
 * @file      nested_exception.cpp
 */

#include <exception>
#include <iostream>
#include <string>

/**
 *
 *    Player.hpp
 *
 */

class Player {
 public:
  explicit Player( std::string const& name );
  virtual ~Player( void );

  void die( void );

 private:
  std::string const _name;

 public:  // EXCEPTIONS
  class EDeath : public std::exception {
   public:
    explicit EDeath( std::string const& name );
    virtual ~EDeath( void ) throw();
    virtual char const* what( void ) const throw();

   private:
    std::string _message;
  };
};

typedef Player::EDeath EDeath;

/**
 *
 *    Player.cpp
 *
 */

/*  PLAYER
------------------------------------------------- */

Player::Player( std::string const& name ) : _name( name ) {
  return;
}

Player::~Player( void ) {
  return;
}

void Player::die( void ) {
  throw EDeath( _name );
  return;
}

/*  EXCEPTION
------------------------------------------------- */

EDeath::EDeath( std::string const& name ) : _message( name + " died" ) {
}

EDeath::~EDeath( void ) throw() {
  return;
}

char const* EDeath::what( void ) const throw() {
  return _message.c_str();
}

/**
 *
 *    main.cpp
 *
 */

int main() {
  try {
    Player p = Player( "Hammurabi" );
    p.die();
  } catch( EDeath const& e ) {
    std::cerr << e.what();
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  return 0;
}
