#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include "LinkedList.hpp"

const int tg_inventorySize = 4;
const int tg_knowledgeSize = 4;

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


  std::cerr << " ---------- ( ... )" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria( new Ice() );
  src->learnMateria( new Cure() );
  AMateria* m1;
  m1 = src->createMateria( "ice" );
  AMateria* m2;
  m2 = src->createMateria( "cure" );
  src->displayLearned();
  std::cout << std::endl;

  std::cerr << " ---------- ( equip )" << std::endl;
  c1->equip( m1 );
  c2->equip( NULL );
  for( i = 0; i < tg_inventorySize + 1; i++ ) {
    c2->equip( m1 );
  }
  c1->equip( m2 );
  std::cout << std::endl;

  std::cerr << " ---------- ( unequip )" << std::endl;
  for( i = 0 - 1; i < tg_inventorySize + 1; i++ )
    c2->unequip( i );

  std::cerr << " ---------- ( use )" << std::endl;
  /* c1->use( 0, c2 ); */
  /* std::cerr << " ---------- ( use abnormal use )" << std::endl; */

  // TODO = and copy again

  // destructor
  delete c1;
  delete c2;
  delete src;
}
void t_next( void ) {
  std::cout << "Press ENTER to continue";
  std::cin.ignore();
  std::cout << "\033[2J\033[1;1H";
  return;
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
 * Check anytime if a Materia is equipped or unequipped with:
 *  std::cout << m << " status: " << m->checkLockStatus();
 *
 */

int main( void ) {
  /* t_default(); */
  /* t_next(); */
  // TODO press a touch for next && clear
  t_Character();
  return 0;
}
