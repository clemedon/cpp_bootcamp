#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include <iosfwd>
#include <string>

class Bureaucrat;

#include "AForm.hpp"

/**
 * ShrubberyCreationForm
 *
 *
 * Data members
 *
 *  _target
 *    the target of the form purpose
 */

class ShrubberyCreationForm : public AForm {
 public:
  explicit ShrubberyCreationForm( std::string const& target = "NC" );
  ShrubberyCreationForm( ShrubberyCreationForm const& src );
  virtual ~ShrubberyCreationForm( void );
  ShrubberyCreationForm& operator=( ShrubberyCreationForm const& rhs );

  virtual void execute( Bureaucrat const& executor ) const;

 private:
  std::string const _target;
};

#endif  // SHRUBBERYCREATIONFORM_HPP_
