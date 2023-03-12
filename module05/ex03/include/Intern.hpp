#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <exception>
#include <iosfwd>
#include <string>

class AForm;

/**
 * Intern
 */

class Intern {
 public:
  Intern( void );
  Intern( Intern const& src );
  virtual ~Intern( void );
  Intern&      operator=( Intern const& rhs );
  virtual void print( std::ostream& o ) const;

  AForm* makeForm( std::string const& formName, std::string const& formTarget );

 public:  // EXCEPTIONS
  class FormNotFoundException : public std::exception {
   public:
    explicit FormNotFoundException( std::string const& formName );
    virtual ~FormNotFoundException( void ) throw();
    virtual char const* what( void ) const throw();

   private:
    std::string _message;
  };
};

std::ostream& operator<<( std::ostream& o, Intern const& i );

typedef Intern::FormNotFoundException EInternFormNotFound;

#endif  // INTERN_HPP_
