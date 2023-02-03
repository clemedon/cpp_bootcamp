#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// TODO
// operator= *this? ou type?
// copy *this or type
int main( void ) {
  /* const Animal* meta = new Animal();  // Animal can't be abstract */
  /* const Animal* j = new Dog(); */
  /* const Animal* i = new Cat(); */

  Animal* cat = new Cat();
  Animal* dog = new Dog();
  *cat = *dog; // WHY

  std::cout << *cat << std::endl;
  (void)cat;
  (void)dog;

  /* std::cout << j->getType() << " " << std::endl; */
  /* std::cout << i->getType() << " " << std::endl; */

  /* i->makeSound();  // will output the cat sound! */
  /* j->makeSound(); */
  /* meta->makeSound(); */

  /* delete meta; */
  /* delete j; */
  /* delete i; */
}
