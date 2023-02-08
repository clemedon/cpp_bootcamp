#include <iostream>

// TODO
// http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/

class MyException : public std::exception {
 public:
  MyException( int age );
  virtual char const* what( void ) const throw();

 private:
  int _age;
};

MyException::MyException( int age ) : _age( age ) {
}

char const* MyException::what( void ) const throw() {
  // format your what
  std::cerr << this->_age << " ";
  return ( " is not legal" );
}

int main() {
  int age = 5;
  try {
    if( age < 18 ) {
      throw MyException( age );  // TODO instantiated
    }
    std::cout << "is legal";
    std::cout << std::endl;
  } catch( MyException const& e ) {
    std::cerr << e.what();
  } catch( ... ) {  // what fallback if formatting code throws TODO
    std::cerr << "Error occurred during what() message formatting";
  }
  return 0;
}
