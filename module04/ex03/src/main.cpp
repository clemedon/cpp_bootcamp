#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

extern const int g_inventorySize;
extern const int g_knowledgeSize;

void t_default() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria( new Ice() );
  src->learnMateria( new Cure() );
  ICharacter* me = new Character( "me" );
  AMateria*   tmp;
  tmp = src->createMateria( "ice" );
  me->equip( tmp );
  tmp = src->createMateria( "cure" );
  me->equip( tmp );
  ICharacter* bob = new Character( "bob" );
  me->use( 0, *bob );
  me->use( 1, *bob );
  std::cout << "----------" << std::endl;
  delete bob;
  delete me;
  delete src;
}

void t_Character() {
  int i;
  (void)i;  // XXX

  std::cerr << " ---------- ( default constructor )" << std::endl;
  Character* c1 = new Character( "Xav" );
  std::cerr << " ---------- ( copy constructor )" << std::endl;
  Character* c2 = new Character( *c1 );
  std::cerr << " ---------- ( copy assignment operator )" << std::endl;
  *c1 = *c2;
  std::cerr << " ---------- ( output operator )" << std::endl;
  std::cout << *c1 << std::endl;
  std::cout << std::endl;

  IMateriaSource* src = new MateriaSource();
  src->learnMateria( new Ice() );
  src->learnMateria( new Cure() );

  AMateria* m1;
  m1 = src->createMateria( "ice" );  // TODO segfault is given unknown materia
  (void)m1;                          // XXX
  AMateria* m2;
  m2 = src->createMateria( "cure" );
  (void)m2;  // XXX

  std::cerr << " ---------- ( equip normal use )" << std::endl;
  c1->equip( NULL );
  /* for( i = 0; i < g_inventoryCapacity + 1; i++ ) */
  c2->equip( m2 );
  /* std::cout << std::endl; */

  /* c2->equip( m1 ); */

  /* std::cerr << " ---------- ( unequip normal use )" << std::endl; */
  /* c1->unequip( 0 ); */
  /* c1->unequip( 3 ); */
  /* std::cerr << " ---------- ( equip abnormal use )" << std::endl; */
  /* for( i = 0 - 1; i < g_inventoryCapacity + 1; i++ ) */
  /*   c1->unequip( i ); */

  /* std::cout << std::endl; */

  /* std::cerr << " ---------- ( use normal use )" << std::endl; */
  /* c1->use( 0, c2 ); */
  /* std::cerr << " ---------- ( use abnormal use )" << std::endl; */

  // TODO = and copy again

  // destructor
  delete c1;
  delete c2;
  delete src;
}

/*
 *  ./a.out | cat -e
 *  * shoots an ice bolt at bob *$
 *  * heals bob's wounds *$
 *
 *  After many hours playing with NULL and cout I finally implemented the
 *  AMateria checkLockStatus and lock member functions with the _lockStatus data
 *  member to prevent a segfault caused by a destructor double delete in the
 *  case that a Character equips the same material twice, or two Character share
 *  the same one. TODO any other solutions? repro: comment out the
 *  checkLockStatus in equip()
 *
 *  AMateria is an abstract class so it is not supposed to be instantiated, the
 *  only way to create a custom Materia is to define its class as a subclass of
 *  AMateria and instantiate it.
 *
 *  MateriaSource is a Materia manager that keep track of all the Materias that
 *  have been created and up to four recipes to create them.  Without this class
 *  we would not be able to programmatically delete unequiped Materias in the
 *  end of the program.
 *
 *
 */

int main( void ) {
  t_default();
  // TODO press a touch for next && clear
  /* t_Character(); */
  return 0;
}
