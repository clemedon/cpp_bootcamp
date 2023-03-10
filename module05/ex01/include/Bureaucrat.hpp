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
              size_t const&      grade = Bureaucrat::_botGrade );
  Bureaucrat( Bureaucrat const& src );
  virtual ~Bureaucrat( void );
  Bureaucrat&  operator=( Bureaucrat const& rhs );
  virtual void print( std::ostream& o ) const;

  void checkGradeLimits( size_t const& grade ) const;
  void upGrade( void );
  void downGrade( void );
  void signForm( Form& f );
  void isAccredited( size_t const& grade ) const;

  std::string getName( void ) const;
  std::size_t getGrade( void ) const;

 private:
  static const size_t _topGrade;
  static const size_t _botGrade;

  std::string const _name;
  size_t            _grade;

 public:  // EXCEPTIONS
  class GradeTooHighException : public std::exception {
   public:
    explicit GradeTooHighException( size_t grade );
    virtual ~GradeTooHighException( void ) throw();
    virtual char const* what( void ) const throw();

   private:
    std::string _message;
  };

  class GradeTooLowException : public std::exception {
   public:
    explicit GradeTooLowException( size_t grade );
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
