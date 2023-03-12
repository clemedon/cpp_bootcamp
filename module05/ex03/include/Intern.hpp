#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <iosfwd>
#include <string>

class AForm;

/**
 * TODO
 */

class Intern {
 public:
  Intern( void );
  Intern( Intern const& src );
  virtual ~Intern( void );
  Intern&      operator=( Intern const& rhs );
  virtual void print( std::ostream& o ) const;

  AForm* makeForm( std::string const& formName, std::string const& formTarget );
};

std::ostream& operator<<( std::ostream& o, Intern const& i );

#endif  // INTERN_HPP_
