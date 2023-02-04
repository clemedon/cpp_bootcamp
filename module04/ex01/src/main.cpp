#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {
  size_t        i;
  const Animal* animals[4];

  std::cout << std::endl;
  std::cout << "          [BIRTH]" << std::endl;
  std::cout << std::endl;

  for( i = 0; i < 4; i++ ) {
    if( i < 2 ) {
      animals[i] = new Cat();
    } else {
      animals[i] = new Dog();
    }
    std::cout << std::endl;
  }

  std::cout << "          [FIRST WORDS]" << std::endl;
  std::cout << std::endl;

  for( i = 0; i < 4; i++ ) {
    std::cout << "Animal nᵒ" << i << ", a " << *animals[i] << " says: ";
    animals[i]->makeSound();
  }

  std::cout << std::endl;
  std::cout << "          [LITTLE LIFE]" << std::endl;
  std::cout << std::endl;

  /* const Animal* filou = new Animal(animals[2]); */

  //
  Cat* a = new Cat();
  Cat* b = new Cat();
  (void)a;
  /* const Cat *b = new Cat(*a); */
  (void)b;
  *b = *a;

  // TODO copy constructor segfault
  /* const Cat *b = new Cat(*a); */
  /* (void)b; */

  /* const Cat *c = b; */
  /* (void)c; */

  // TODO copy assignment operator segfault
  /* animals[0] = animals[1]; */

  (void)animals;

  std::cout << std::endl;
  std::cout << "          [DEATH]" << std::endl;
  std::cout << std::endl;

  for( i = 0; i < 4; i++ ) {
    delete animals[i];
    std::cout << std::endl;
  }
}
