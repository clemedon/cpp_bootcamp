#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target )
  : AForm( "Shrubbery Creation", false, 145, 137 ),
    _target( target ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& src )
  : AForm( src ),
    _target( src._target ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << " FROM ";
  std::cerr << src;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " DESTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
  ShrubberyCreationForm const& rhs ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY ASSIGNMENT OPERATOR DISABLED";
  std::cerr << std::endl;
#endif
  (void)rhs;
  return *this;
}

/* ---------------------------------------------- */

void ShrubberyCreationForm::execute( Bureaucrat const& executor ) const {
  (void)executor;
  std::string const filename = _target + "_shrubbery";
  std::cout << std::endl;
  std::stringstream ss;
  ss << "                                       \n";
  ss << "                 ┏━━━┓                 \n";
  ss << "           ╭─────┨o  ┠─────╮           \n";
  ss << "           │     ┗━━━┛     │           \n";
  ss << "         ┏━┷━┓           ┏━┷━┓         \n";
  ss << "       ╭─┨ O ┠─╮       ╭─┨ o ┠─╮       \n";
  ss << "       │ ┗━━━┛ │       │ ┗━━━┛ │       \n";
  ss << "     ┏━┷━┓   ┏━┷━┓   ┏━┷━┓   ┏━┷━┓     \n";
  ss << "     ┃o  ┃   ┃  O┃   ┃o  ┃   ┃  O┃     \n";
  ss << "     ┗━━━┛   ┗━━━┛   ┗━━━┛   ┗━━━┛     \n";
  ss << "                                       \n";
  std::ofstream ofs( filename, std::ofstream::trunc | std::ofstream::out );
  ofs << ss.str();
  ofs.close();
  std::cout << filename << " has been created";
  std::cout << std::endl;
  return;
}
