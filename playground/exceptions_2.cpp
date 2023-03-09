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
    EXCEPTION e;                                                               \
    e.setMessage( target );                                                    \
    e.setLocation( __func__, __FILE__, __LINE__ );                             \
    throw e;                                                                   \
  }

class EDeath : public std::exception {
 public:
  explicit EDeath( const std::string& message );
  virtual ~EDeath( void ) throw();

  char const* what( void ) const throw();
  void        setMessage( const std::string& message );
  void        setLocation( const char* func, const char* file, const int line );

 private:
  std::string _message;
};

/*  DERIVED EXCEPTIONS
------------------------------------------------- */

class EDrowned : public EDeath {
 public:
  EDrowned( void );
};

class EBurned : public EDeath {
 public:
  EBurned( void );
};

/**
 *
 *    EDeath.cpp
 *
 */

/*  BASE EXCEPTION
------------------------------------------------- */

EDeath::EDeath( const std::string& message ) : _message( "Death: " + message ) {
  return;
}

EDeath::~EDeath( void ) throw() {
  return;
}

const char* EDeath::what() const throw() {
  return _message.c_str();
}

void EDeath::setMessage( const std::string& target ) {
  _message += ": " + target;
  return;
}

void EDeath::setLocation( const char* func, const char* file, const int line ) {
  _message += "  (in " + std::string( file );
  _message += ": " + std::string( func );
  _message += ": " + std::to_string( line ) + ")";
  return;
}

/*  DERIVED EXCEPTIONS
------------------------------------------------- */

EDrowned::EDrowned( void ) : EDeath( "Drowned" ) {
  return;
}

EBurned::EBurned( void ) : EDeath( "Burned" ) {
  return;
}

/**
 *
 *    main.cpp
 *
 */

int main() {
  try {
    THROW( EDrowned, "Clem" )
  } catch( std::exception const& e ) {
    /* Death: Drowned: Clem (in exceptions_2.cpp: main: 100) */
    std::cout << e.what() << std::endl;
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  try {
    THROW( EBurned, "Clem" )
  } catch( std::exception const& e ) {
    /* Death: Burned: Clem (in exceptions_2.cpp: main: 108) */
    std::cout << e.what() << std::endl;
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }
  return 0;
}
