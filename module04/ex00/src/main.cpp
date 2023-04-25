// @author    Clément Vidon
// @created   230324 15:21:48  by  clem@spectre
// @modified  230417 10:10:04  by  clem@spectre
// @filename  main.cpp

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * TODO should I follow the private or public data members naming convention for
 * protected data members ?
 *
 * Copy Assignment Operator:
 *
 *  Animal* cat = new Cat();
 *  Animal* dog = new Dog();
 *  *cat = *dog; // OK an animal can be a cat or a dog
 *
 *  Animal* cat;
 *  - cat          type is   Animal*
 *  - *cat         type is   Animal
 *  - *cat = *dog  type is   Animal = Animal
 *
 *  Cat* cat = new Cat();
 *  Dog* dog = new Dog();
 *  *cat = *dog;  // NOK a cat can not be a dog
 *  cat = dog;    // NOK only assign an address
 *
 * I preferred to build the classes through a parameter to the constructor
 * because if I had been satisfied to use the initialization of the parents'
 * _type data member inherited by the children then the construction of a child
 * class would always be preceded by a class with a wrongly defined type
 * (ex. constructed cat: construct animal > construct cat > ... > destroy cat >
 * destroy *cat*) which gives an asymmetric output.
 */

int main( void ) {
  const Animal* animal = new Animal();  // Animal can't be abstract
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << std::endl;
  std::cout << animal->getType() << " " << std::endl;
  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  std::cout << std::endl;
  animal->makeSound();  // output animal sound
  dog->makeSound();     // output dog sound
  cat->makeSound();     // output cat sound
  std::cout << std::endl;

  delete animal;
  delete dog;
  delete cat;

  const WrongAnimal* wrongAnimal = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();
  WrongCat wc;

  std::cout << std::endl;
  std::cout << wrongAnimal->getType() << " " << std::endl;
  std::cout << wrongCat->getType() << " " << std::endl;
  std::cout << wc.getType() << " " << std::endl;
  std::cout << std::endl;
  wrongAnimal->makeSound(); // output wrong animal sound
  wrongCat->makeSound();    // output wrong animal sound
  wc.makeSound();           // output wrong cat    sound
  std::cout << std::endl;

  delete wrongAnimal;
  delete wrongCat;
}
