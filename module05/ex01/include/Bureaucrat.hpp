#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <iosfwd>
#include <string>

class Form;

/**
 * Bureaucrat
 */

class Bureaucrat {
 public:
  Bureaucrat( std::string const& name = "bottom bureaucrat",
              size_t const       grade = Bureaucrat::_botGrade );
  Bureaucrat( Bureaucrat const& src );
  virtual ~Bureaucrat( void );
  Bureaucrat&  operator=( Bureaucrat const& rhs );
  virtual void print( std::ostream& o ) const;

  void   checkGradeLimits( size_t const grade ) const;
  void   upGrade( void );
  void   downGrade( void );
  void   signForm( Form& f ) const;
  size_t giveGrade( void ) const;

  std::string getName( void ) const;
  size_t      getGrade( void ) const;

 private:
  static size_t const _topGrade;
  static size_t const _botGrade;

  std::string const _name;
  size_t            _grade;

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

std::ostream& operator<<( std::ostream& o, Bureaucrat const& i );

typedef Bureaucrat::GradeTooHighException EBureaucratGradeTooHigh;
typedef Bureaucrat::GradeTooLowException  EBureaucratGradeTooLow;

#endif  // BUREAUCRAT_HPP_
