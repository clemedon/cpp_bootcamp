#include <exception>
#include <iostream>
#include <string>

/**
 *
 *    EDeath.hpp
 *
 */

/*  BASE EXCEPTION
------------------------------------------------- */

#define THROW( EXCEPTION, target )                                             \
  {                                                                            \
    EXCEPTION e( target );                                                     \
    e.where( __func__, __FILE__, __LINE__ );                                   \
    throw e;                                                                   \
  }

class EDeath : public std::exception {
 public:
  explicit EDeath( const std::string& message );
  virtual ~EDeath( void ) throw();

  const char* what() const throw();
  void        where( const char* func, const char* file, const int line );

 private:
  std::string _message;
};

/*  DERIVED EXCEPTIONS
------------------------------------------------- */

class EDrowned : public EDeath {
 public:
  explicit EDrowned( const std::string& target );
};

class EBurned : public EDeath {
 public:
  explicit EBurned( const std::string& target );
};

/**
 *
 *    EDeath.cpp
 *
 */

/*  BASE EXCEPTION
------------------------------------------------- */

EDeath::EDeath( const std::string& message )
  : _message( "Game Over: " + message ) {
  return;
}

EDeath::~EDeath( void ) throw() {
  return;
}

const char* EDeath::what() const throw() {
  return _message.c_str();
}

void EDeath::where( const char* func, const char* file, const int line ) {
  _message += "  (in " + std::string( file );
  _message += ": " + std::string( func );
  _message += ": " + std::to_string( line ) + ")";
  return;
}

/*  DERIVED EXCEPTIONS
------------------------------------------------- */

EDrowned::EDrowned( const std::string& target )
  : EDeath( target + " was drowned" ) {
  return;
}

EBurned::EBurned( const std::string& target )
  : EDeath( target + " was burned" ) {
  return;
}

/**
 *
 *    main.cpp
 *
 */

int main() {
  /* Base Exception */
  try {
    THROW( EDeath, "Clem" )
  } catch( std::exception const& e ) {
    /* Game Over: Clem  (in exceptions_1.cpp: main: 97) */
    std::cout << e.what() << std::endl;
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  /* Derived Exceptions */
  try {
    THROW( EDrowned, "Clem" )
  } catch( std::exception const& e ) {
    /* Game Over: Clem was drowned  (in exceptions_1.cpp: main: 106) */
    std::cout << e.what() << std::endl;
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  try {
    THROW( EBurned, "Clem" )
  } catch( std::exception const& e ) {
    /* Game Over: Clem was burned  (in exceptions_1.cpp: main: 114) */
    std::cout << e.what() << std::endl;
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  return 0;
}
