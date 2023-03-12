#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include <iosfwd>
#include <string>

class Bureaucrat;

#include "AForm.hpp"

/**
 * PresidentialPardonForm
 *
 *
 * Data members
 *
 *  _target
 *    the target of the form purpose
 */

class PresidentialPardonForm : public AForm {
 public:
  explicit PresidentialPardonForm( std::string const& target = "NC" );
  PresidentialPardonForm( PresidentialPardonForm const& src );
  virtual ~PresidentialPardonForm( void );
  PresidentialPardonForm& operator=( PresidentialPardonForm const& rhs );

  virtual void execute( Bureaucrat const& executor ) const;

 private:
  std::string const _target;
};

#endif  // PRESIDENTIALPARDONFORM_HPP_
