#include <iostream>
#include "Bureaucrat.hpp"

int main( void ) {
  try {
    Bureaucrat clem = Bureaucrat( "Clem", 142 );
    // TODO if clem is on the heap
    // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#e6-use-raii-to-prevent-leaks
    while( 1 ) {
      std::cout << clem;
      std::cout << " downgraded to ";
      clem.downGrade();
      std::cout << clem;
      std::cout << std::endl;
    }
  } catch( Bureaucrat::GradeTooHighException const& e ) {
    std::cerr << e.what();
  } catch( Bureaucrat::GradeTooLowException const& e ) {
    std::cerr << e.what();
  }
  return 0;
}
