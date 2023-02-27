#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

extern const int g_inventorySize;
extern const int g_sourceSize;

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

  std::cerr << " ---------- ( equip normal use )" << std::endl;

  AMateria* m1 = new Ice();
  (void)m1;  // TODO
  AMateria* m2 = new Cure();
  (void)m2;  // TODO

  /* *c1->equip( NULL ); */

  /* for( i = 0; i < g_inventorySize + 1; i++ ) */
  /*   *c2->equip( m2 );  // TODO doubles? */

  /* std::cout << std::endl; */

  /* std::cerr << " ---------- ( unequip normal use )" << std::endl; */
  /* *c1->unequip( 0 ); */
  /* *c1->unequip( 3 ); */
  /* std::cerr << " ---------- ( equip abnormal use )" << std::endl; */
  /* for( i = 0 - 1; i < g_inventorySize + 1; i++ ) */
  /*   *c1->unequip( i ); */

  /* std::cout << std::endl; */

  /* std::cerr << " ---------- ( use normal use )" << std::endl; */
  /* *c1->use( 0, *c2 ); */
  /* std::cerr << " ---------- ( use abnormal use )" << std::endl; */

  // destructor
  delete c1;
  delete c2;
}

/*
 *  ./a.out | cat -e
 *  * shoots an ice bolt at bob *$
 *  * heals bob's wounds *$
 *
 *  TODO _name should not be a pointer?
 *
 *  To go further we could provide the checkLock, lock and unlock member
 *  functions to AMateria with a lockStatus data member to prevent two Character
 *  from sharing the same and the segfault that occurs if both are destroyed.
 *
 *  MateriaSource handles the removal of Materias that were not equipped
 */

int main( void ) {
  /* t_default(); */
  /* t_Character(); */

  IMateriaSource* src = new MateriaSource();
  src->learnMateria( new Ice() );
  src->learnMateria( new Cure() );

  Character* a = new Character( "clem" );
  Character* b = new Character( *a );

  AMateria* tmp;

  tmp = src->createMateria( "ice" );
  delete tmp;

  tmp = NULL;
  delete tmp;
  /* b->equip( tmp ); */
  /* b->equip( tmp ); */

  /* tmp = src->createMateria( "cure" ); */
  /* b->equip( tmp ); */

  *a = *b;  // TODO segfault

  delete src;
  delete a;
  delete b;
  return 0;
}
