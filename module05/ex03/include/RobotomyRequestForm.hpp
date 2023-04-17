// @author    Clément Vidon
// @created   230417 14:48:43  by  clem@spectre
// @modified  230417 14:48:43  by  clem@spectre
// @filename  RobotomyRequestForm.hpp

#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include <iosfwd>
#include <string>

class Bureaucrat;

#include "AForm.hpp"

/**
 * RobotomyRequestForm
 *
 *
 * Data members
 *
 *  _target
 *    the target of the form purpose
 */

class RobotomyRequestForm : public AForm {
 public:
  explicit RobotomyRequestForm( std::string const& target = "NC" );
  RobotomyRequestForm( RobotomyRequestForm const& src );
  virtual ~RobotomyRequestForm( void );
  RobotomyRequestForm& operator=( RobotomyRequestForm const& rhs );

  virtual void execute( Bureaucrat const& executor ) const;

 private:
  std::string const _target;
};

#endif  // ROBOTOMYREQUESTFORM_HPP_
