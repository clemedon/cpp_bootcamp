// @author    Clément Vidon
// @created   230417 14:48:40  by  clem@spectre
// @modified  230417 14:48:40  by  clem@spectre
// @filename  AForm.hpp

#ifndef FORM_HPP_
#define FORM_HPP_

#include <exception>
#include <iosfwd>
#include <string>

class Bureaucrat;

/**
 * AForm
 *
 *
 * Data members
 *
 *  _topGrade
 *    the highest grade
 *
 *  _botGrade
 *    the lowest grade
 *
 *  _name
 *    the name of the form
 *
 *  _signed
 *    indicate if the form is signed or not
 *
 *  _signGrade
 *    the grade required for a Bureaucrat to sign the form
 *
 *  _execGrade
 *    the grade required for a Bureaucrat to execute the form
 */

class AForm {
 protected:
  AForm( std::string const& name = "AForm",
         bool const         s = false,
         size_t const       signGrade = AForm::_topGrade,
         size_t const       execGrade = AForm::_topGrade );
  AForm( AForm const& src );

 public:
  virtual ~AForm( void );
  AForm& operator=( AForm const& rhs );
  void   print( std::ostream& o ) const;

  void checkGradeLimits( size_t const grade ) const;
  void beSigned( Bureaucrat const& b );
  void beExecuted( Bureaucrat const& b );
  bool isSigned( void ) const;

  virtual void execute( Bureaucrat const& executor ) const = 0;

  std::string getName( void ) const;
  bool        getSigned( void ) const;
  size_t      getSignGrade( void ) const;
  size_t      getExecGrade( void ) const;

 private:
  static size_t const _topGrade;
  static size_t const _botGrade;

  std::string const _name;
  bool              _signed;
  size_t const      _signGrade;
  size_t const      _execGrade;

 public:  // EXCEPTIONS
  class GradeTooHighException : public std::exception {
   public:
    explicit GradeTooHighException( size_t const grade );
    virtual ~GradeTooHighException( void ) throw();
    virtual char const* what( void ) const throw();

   private:
    std::string _message;
  };

  class GradeTooLowException : public std::exception {
   public:
    explicit GradeTooLowException( size_t const grade );
    virtual ~GradeTooLowException( void ) throw();
    virtual char const* what( void ) const throw();

   private:
    std::string _message;
  };
};

std::ostream& operator<<( std::ostream& o, AForm const& i );

typedef AForm::GradeTooHighException EAFormGradeTooHigh;
typedef AForm::GradeTooLowException  EAFormGradeTooLow;

#endif  // FORM_HPP_
