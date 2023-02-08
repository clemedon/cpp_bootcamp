#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>
#include <string>

/**
 * TODO
 */

class Bureaucrat {
  public:
    Bureaucrat( std::string const& name = "bottom bureaucrat",
        size_t             grade = Bureaucrat::_botLevel );
    Bureaucrat( Bureaucrat const& src );
    virtual ~Bureaucrat( void );
    Bureaucrat&  operator=( Bureaucrat const& rhs );
    virtual void print( std::ostream& o ) const;

    void upGrade( void );
    void downGrade( void );

    // TODO
    // TODO typedef struct Bureaucrat::GradeTooHighException TooHighException;
    class GradeTooHighException : public std::exception {
      public:
        GradeTooHighException( size_t grade );
        virtual char const* what( void ) const throw();

      private:
        size_t _grade;
    };

    // TODO
    class GradeTooLowException : public std::exception {
      public:
        GradeTooLowException( size_t grade );
        virtual char const* what( void ) const throw();

      private:
        size_t _grade;
    };

    std::string getName( void ) const;
    std::size_t getGrade( void ) const;

  private:
    static size_t     _topLevel;
    static size_t     _botLevel;
    std::string const _name;
    size_t            _grade;
};

std::ostream& operator<<( std::ostream& o, Bureaucrat const& i );

#endif  // BUREAUCRAT_HPP_
