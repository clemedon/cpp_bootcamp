/**
 * @author    Clément Vidon
 * @brief     Example of exception with base name implementation.
 * @date      230310
 * @file      basename_exception.cpp
 */

#include <exception>
#include <iostream>
#include <string>

/**
 *
 *    EUser.hpp
 *
 */

/*  BASE EXCEPTION
------------------------------------------------- */

#define THROW( EXCEPTION, message )                                            \
  {                                                                            \
    EXCEPTION e( message );                                                    \
    e.where( __func__, __FILE__, __LINE__ );                                   \
    throw e;                                                                   \
  }

class EUser : public std::exception {
 public:
  explicit EUser( const std::string& message );
  virtual ~EUser( void ) throw();

  virtual char const* what() const throw();
  void where( char const* func, char const* file, int const line );

 private:
  std::string _message;
};

/*  DERIVED EXCEPTIONS
------------------------------------------------- */

class EDeaf : public EUser {
 public:
  explicit EDeaf( std::string const& message );
};

class EMute : public EUser {
 public:
  explicit EMute( std::string const& message );
};

/**
 *
 *    EUser.cpp
 *
 */

/*  BASE EXCEPTION
------------------------------------------------- */

EUser::EUser( std::string const& message ) : _message( "User: " + message ) {
  return;
}

EUser::~EUser( void ) throw() {
  return;
}

char const* EUser::what() const throw() {
  return _message.c_str();
}

void EUser::where( char const* func, char const* file, int const line ) {
  _message += " (in " + std::string( file );
  _message += ": " + std::string( func );
  _message += ": " + std::to_string( line ) + ")";
  return;
}

/*  DERIVED EXCEPTIONS
------------------------------------------------- */

EDeaf::EDeaf( std::string const& message ) : EUser( message + " is deaf" ) {
  return;
}

EMute::EMute( std::string const& message ) : EUser( message + " is mute" ) {
  return;
}

/**
 *
 *    main.cpp
 *
 *
 * Ouput:
 * User: Motoko (in exceptions_1.cpp: main: 102)
 * User: Motoko is deaf (in exceptions_1.cpp: main: 109)
 * User: Motoko is mute (in exceptions_1.cpp: main: 116)
 */

int main() {
  try {
    THROW( EUser, "Motoko" )
  } catch( std::exception const& e ) {
    std::cout << e.what() << std::endl;
  }
  try {
    THROW( EDeaf, "Motoko" )
  } catch( std::exception const& e ) {
    std::cout << e.what() << std::endl;
  }
  try {
    THROW( EMute, "Motoko" )
  } catch( std::exception const& e ) {
    std::cout << e.what() << std::endl;
  }

  catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  return 0;
}
