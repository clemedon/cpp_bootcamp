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
  animal->makeSound();
  dog->makeSound();
  cat->makeSound();  // will output the cat sound!
  std::cout << std::endl;

  delete animal;
  delete dog;
  delete cat;

  const WrongAnimal* wrongAnimal = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << std::endl;
  std::cout << wrongAnimal->getType() << " " << std::endl;
  std::cout << wrongCat->getType() << " " << std::endl;
  std::cout << std::endl;
  wrongAnimal->makeSound();
  wrongCat->makeSound();  // will output the wrong cat sound!
  std::cout << std::endl;

  delete wrongAnimal;
  delete wrongCat;
}
