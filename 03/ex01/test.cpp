#include <iostream>

// https://www.tutorialspoint.com/accessing-protected-members-in-a-cplusplus-derived-class

class Base {
 protected:
  int num = 7;
};

class Derived : public Base {
 public:
  Derived( void ) {
    num = 3; // TODO solution
    // How can I initialize base class member variables in derived class constructor?
    // https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor
    // https://stackoverflow.com/questions/19918369/does-not-have-field-named
    //
    std::cout << "The value of num is: " << num;
    return;
  }
};

int main() {
  Derived obj;
  return 0;
}
