#include <iostream>

// https://www.tutorialspoint.com/accessing-protected-members-in-a-cplusplus-derived-class

class Base {
 public:
  Base( int num ) : _num( num ) {
    std::cout << "Base constructor called, _num =  " << _num;
    std::cout << std::endl;
    return;
  }
  ~Base( void ) {
    std::cout << "Base destructor call";
    std::cout << std::endl;
    return;
  }
  virtual void print( void ) {
    std::cout << "Base _num = " << _num << std::endl;
  }

 protected:
  int _num;
};

class Derived : public Base {
 public:
  Derived( void ) : Base( 1 ) {
    std::cout << "Derived constructor called, _num =  " << _num;
    std::cout << std::endl;
    return;
  }
  ~Derived( void ) {
    std::cout << "Derived destructor call";
    std::cout << std::endl;
    return;
  }
  void print( void ) { std::cout << "Derived _num = " << _num << std::endl; }
};

int main() {
  // basePtr is not an instance thus it does not trigger any constructors
  Base* basePtr;

  // derivedInstance is an instance thus it triggers its base-class constructor
  // as well as its own constructor
  Derived derivedInstance;

  basePtr = &derivedInstance;

  // without virtual: Base _num = 1
  // with virtual:    Derived _num = 1
  basePtr->print();

  Base b( 0 );
  b.print();

  return 0;
}
