#include <iostream>

// https://www.tutorialspoint.com/accessing-protected-members-in-a-cplusplus-derived-class

class Base {
 public:
  Base( int num = 0 ) : _num( num ) {
    std::cout << "Base constructor called, _num =  " << _num;
    std::cout << std::endl;
    return;
  }
  ~Base( void ) {
    std::cout << "Base destructor called";
    std::cout << std::endl;
    return;
  }
  virtual void print( void ) {
    std::cout << __func__ << "> Base _num = " << _num << std::endl;
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
    std::cout << "Derived destructor called";
    std::cout << std::endl;
    return;
  }
  void print( void ) {
    std::cout << __func__ << "> Derived _num = " << _num << std::endl;
  }
};

int main() {
  // We have a base-class with a num member that default to 0 and a
  // derived-class that inherit base-class num member and set it to 1

  // basePtr is not an instance, it does not trigger any constructors
  Base* basePtr;

  // derivedInstance is an instance, it triggers its base-class constructor and
  // its own constructor
  Derived derivedInstance;

  basePtr = &derivedInstance;

  // access the derived-class member (without virtual keyword we would access
  // the base-class member)
  basePtr->print();

  Base b;
  b.print();
  return 0;
}
