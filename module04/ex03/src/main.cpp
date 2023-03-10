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

void t_next( void ) {
  std::cout << "Press ENTER to continue";
  std::cin.ignore();
  std::cout << "\033[2J\033[1;1H";
  return;
}

void t_default() {
  std::cerr << "  ---> " << __func__ << "( all tests )";
  std::cout << std::endl << std::endl;

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

  delete bob;
  delete me;
  delete src;

  t_next();
  return;
}

void t_custom() {
  int i;

  std::cerr << " ---> " << __func__ << "( Character default constructor )";
  std::cout << std::endl << std::endl;
  ICharacter* c1 = new Character( "Xav" );
  t_next();

  std::cerr << " ---> " << __func__ << "( Character copy constructor )";
  std::cout << std::endl << std::endl;
  ICharacter* c2 = new Character( *c1 );
  t_next();

  std::cerr << " ---> " << __func__ << "( Character copy assignment )";
  std::cout << std::endl << std::endl;
  *c2 = *c1;
  t_next();

  std::cerr << " ---> " << __func__ << "( Character output operator )";
  std::cout << std::endl << std::endl;
  std::cout << *c1 << std::endl;
  std::cout << *c2 << std::endl;
  t_next();

  std::cerr << " ---> " << __func__ << "( MateriaSource constructor )";
  std::cout << std::endl << std::endl;
  IMateriaSource* s1 = new MateriaSource();
  t_next();

  std::cerr << " ---> " << __func__ << "( MateriaSource copy constructor )";
  std::cout << std::endl << std::endl;
  IMateriaSource* s2 = new MateriaSource( *s1 );
  t_next();

  std::cerr << " ---> " << __func__ << "( MateriaSource copy assignment )";
  std::cout << std::endl << std::endl;
  *s2 = *s1;
  *s1 = *s2;
  *s1 = *s1;
  t_next();

  std::cerr << " ---> " << __func__ << "( MateriaSource output operator )";
  std::cout << std::endl << std::endl;
  std::cout << *s1 << std::endl;
  std::cout << *s2 << std::endl;
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia constructor )";
  std::cout << std::endl << std::endl;
  AMateria* m0 = new Cure();
  AMateria* m1 = new Ice();
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia copy constructor )";
  std::cout << std::endl << std::endl;
  AMateria* m2 = new Cure( *m1 );
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia copy assignment )";
  std::cout << std::endl << std::endl;
  *m2 = *m1;
  *m1 = *m2;
  *m1 = *m1;
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia output operator )";
  std::cout << std::endl << std::endl;
  std::cout << *m1 << " (addr." << m1 << ")" << std::endl;
  std::cout << *m2 << " (addr." << m2 << ")" << std::endl;
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia clone )";
  std::cout << std::endl << std::endl;
  AMateria* m3 = m0->clone();
  (void)m3;
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia use )";
  std::cout << std::endl << std::endl;
  m0->use( *c1 );
  m1->use( *c2 );
  t_next();

#if defined( DEBUG )
  std::cerr << " ---> " << __func__ << "( Materia displayFreeMaterias )";
  std::cout << std::endl << std::endl;
  m1->displayFreeMaterias();
#endif

  std::cerr << " ---> " << __func__ << "( MateriaSource learnMateria )";
  std::cout << std::endl << std::endl;
  s1->learnMateria( m1 );
  s2->learnMateria( m2 );
  t_next();

  std::cerr << " ---> " << __func__ << "( MateriaSource createMateria )";
  std::cout << std::endl << std::endl;
  m1 = s1->createMateria( "ice" );
  m2 = s1->createMateria( "cure" );
  t_next();

#if defined( DEBUG )
  std::cerr << " ---> " << __func__ << "( MateriaSource displayKnowledge )";
  std::cout << std::endl << std::endl;
  s1->displayKnowledge();
  t_next();
#endif

  std::cerr << " ---> " << __func__ << "( Character equip / unequip )";
  std::cout << std::endl << std::endl;
  c2->equip( NULL );
  for( i = 0; i < tg_inventorySize + 1; i++ ) {
    c2->equip( m1 );
    c1->equip( s1->createMateria( "ice" ) );
  }
  c1->equip( m1 );
  c1->equip( m2 );
  c2->unequip( 0 );
  for( i = 0 - 1; i < tg_inventorySize + 1; i++ ) {
    c2->unequip( i );
    c1->unequip( i );
  }
  c1->unequip( 0 );
  c1->equip( m1 );
  c2->equip( m2 );
  for( i = 0 - 1; i < tg_inventorySize + 1; i++ ) {
    c2->equip( m1 );
    c2->equip( m2 );
  }
  t_next();

  std::cerr << " ---> " << __func__ << "( Character use )";
  std::cout << std::endl << std::endl;
#if defined( DEBUG )
  c1->displayInventory();
  c2->displayInventory();
#endif
  for( i = 0; i < tg_inventorySize + 1; i++ ) {
    c1->use( i, *c2 );
  }
  c1->use( 0, *c2 );
  c1->use( 1, *c2 );
  c1->use( 0, *c1 );
  c1->use( 1, *c1 );
  c2->use( 0, *c2 );
  c2->use( 1, *c2 );
  c2->use( 0, *c1 );
  c2->use( 1, *c1 );
  t_next();

  std::cerr << " ---> " << __func__ << "( Character copy assignment )";
  std::cout << std::endl << std::endl;
#if defined( DEBUG )
  c1->displayInventory();
  c2->displayInventory();
#endif
  *c2 = *c1;
#if defined( DEBUG )
  c1->displayInventory();
  c2->displayInventory();
#endif
  std::cerr << " ---> " << __func__ << "( Character copy constructor )";
  std::cout << std::endl << std::endl;
  ICharacter* c3 = new Character( *c2 );
#if defined( DEBUG )
  c3->displayInventory();
#endif
  t_next();

  std::cerr << " ---> " << __func__ << "( Destructors )";
  std::cout << std::endl << std::endl;
  delete s1;
  delete s2;
  delete c1;
  delete c2;
  delete c3;
  return;
}

/*
 *  After many hours playing with NULL and cout I finally implemented the
 *  AMateria checkLockStatus and lock member functions with the _lockStatus data
 *  member to prevent a segfault caused by a destructor double delete in the
 *  case that a Character equips the same material twice, or two Character share
 *  the same one. TODO any other solutions? repro: comment out the
 *  checkLockStatus in equip()
 *
 *  AMateria keeps track of all Materias that are created through a linked list,
 *  if a Materia ends up in the hands of a Character AMateria loses
 *  responsibility for it and thus removes it from its tracking list. TODO is
 *  there a way other than the linked list to make a VLA without Containers?
 *
 *  AMateria is an abstract class so it is not supposed to be instantiated, the
 *  only way to create a custom Materia is to define its class as a subclass of
 *  AMateria and instantiate it.
 *
 *  I ran into a problem that I thought was an infinite loop in
 *  Character::Character( ICharacter const& src ), the problem turned out to be
 *  my attempt to print src using the output operator but src being the
 *  Character's interface it does not have any implementation for such output
 *  operator handling.
 *
 *  Character's copy constructor uses its getName() getter instead of a direct
 *  access to src._name because src is an interface thus it does not have _name
 *  data member.
 */

int main( void ) {
  (void)tg_inventorySize;
  (void)tg_knowledgeSize;
  t_next();
  t_default();
  t_custom();

  return 0;
}
