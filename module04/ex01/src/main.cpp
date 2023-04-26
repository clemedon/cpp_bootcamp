// @author    Clément Vidon
// @created   230324 15:32:06  by  clem@spectre
// @modified  230417 10:13:01  by  clem@spectre
// @filename  main.cpp

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
  Cat* a = new Cat();
  Cat* b = new Cat();
  Cat* c = new Cat( *b );

  std::cout << "BEF" << std::endl;
  *b = *a = *c;
  std::cout << "AFT" << std::endl;

  delete a;
  delete b;
  delete c;
*/

int main( void ) {
  size_t        i;
  const Animal* animals[4];

  std::cout << std::endl;
  std::cout << "          [BIRTH]" << std::endl;
  std::cout << std::endl;

  for( i = 0; i < 4; ++i ) {
    if( i < 2 ) {
      animals[i] = new Cat();
    } else {
      animals[i] = new Dog();
    }
    std::cout << std::endl;
  }

  std::cout << "          [LIVE]" << std::endl;
  std::cout << std::endl;

  for( i = 0; i < 4; ++i ) {
    std::cout << "Animal nᵒ" << i << ", a " << *animals[i] << " says: ";
    animals[i]->makeSound();
  }

  std::cout << std::endl;
  std::cout << "          [DEATH]" << std::endl;
  std::cout << std::endl;

  for( i = 0; i < 4; ++i ) {
    delete animals[i];
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Copy assignment operator and copy constructors" << std::endl;
  std::cout << std::endl;
  Cat* a = new Cat();
  Cat* b = new Cat();
  Cat* c = new Cat( *b );
  std::cout << std::endl;
  *b = *a = *c;
  std::cout << std::endl;
  delete a;
  delete b;
  delete c;

  // turn Dog's _brain public for those tests
  /* std::cout << std::endl; */
  /* std::cout << "          [vvvvv]" << std::endl; */
  /* std::cout << std::endl; */
  /* Dog original; */
  /* std::cout << std::endl; */
  /* Dog copy1( original ); */
  /* Dog copy2 = original; */
  /* std::cout << original._brain<< std::endl; */
  /* std::cout << copy1._brain<< std::endl; */
  /* std::cout << copy2._brain<< std::endl; */

  std::cout << std::endl;
}
