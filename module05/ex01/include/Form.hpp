#ifndef FORM_HPP_
#define FORM_HPP_

#include <exception>
#include <iosfwd>
#include <string>

class Bureaucrat;

/**
 * Form
 */

class Form {
 public:
  Form( std::string const& name = "basic form",
        bool const         s = false,
        size_t const       signGrade = Form::_topGrade,
        size_t const       execGrade = Form::_topGrade );
  Form( Form const& src );
  virtual ~Form( void );
  Form&        operator=( Form const& rhs );
  virtual void print( std::ostream& o ) const;

  void checkGradeLimits( size_t const grade ) const;
  void beSigned( Bureaucrat const& b );
  bool isSigned( void ) const;

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

std::ostream& operator<<( std::ostream& o, Form const& i );

typedef Form::GradeTooHighException EFormGradeTooHigh;
typedef Form::GradeTooLowException  EFormGradeTooLow;

#endif  // FORM_HPP_
