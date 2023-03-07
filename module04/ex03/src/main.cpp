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
  /* std::cout << "Press ENTER to continue"; */
  /* std::cin.ignore(); */
  /* std::cout << "\033[2J\033[1;1H"; */
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
  /* int i; */

  /* std::cerr << " ---> " << __func__ << "( Character default constructor )";
   */
  /* std::cout << std::endl << std::endl; */
  /* ICharacter* c1 = new Character( "Xav" ); */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( Character copy constructor )"; */
  /* std::cout << std::endl << std::endl; */
  /* ICharacter* c2 = new Character( *c1 ); */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( Character copy assignment )"; */
  /* std::cout << std::endl << std::endl; */
  /* *c2 = *c1; */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( Character output operator )"; */
  /* std::cout << std::endl << std::endl; */
  /* std::cout << *c1 << std::endl; */
  /* std::cout << *c2 << std::endl; */
  /* t_next(); */

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
  std::cout << *m1 << " (addr." << s1 << ")" << std::endl;
  std::cout << *m2 << " (addr." << s2 << ")" << std::endl;
  t_next();

  std::cerr << " ---> " << __func__ << "( Materia clone )";

  AMateria* m3 = m1->clone();
  (void)m3;

  /* AMateria* m4 = new Ice(); */
  /* (void)m4; */

  t_next();

  /* std::cerr << " ---> " << __func__ << "( Materia use )"; */
  /* virtual AMateria* use( void ) const; */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( MateriaSource learnMateria )"; */
  /* virtual void use( ICharacter & target ); */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( MateriaSource learnMateria )"; */
  /* s1->learnMateria( new Ice() ); */
  /* s1->learnMateria( new Cure() ); */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( MateriaSource createMateria )"; */
  /* AMateria* m1; */
  /* m1 = s1->createMateria( "ice" ); */
  /* AMateria* m2; */
  /* m2 = s1->createMateria( "cure" ); */
  /* t_next(); */

  /* #if defined( DEBUG ) */
  /* std::cerr << " ---> " << __func__ << "( MateriaSource displayKnowledge )";
   */
  /* s1->displayKnowledge(); */
  /* t_next(); */
  /* #endif */

  (void)m1;
  (void)m2;

  delete s1;
  delete s2;
  return;

  /* std::cerr << " ---> " << __func__ << "( Character equip / unequip )"; */
  /* std::cout << std::endl << std::endl; */
  /* c2->equip( NULL ); */
  /* for( i = 0; i < tg_inventorySize + 1; i++ ) { */
  /*   c2->equip( m1 ); */
  /*   c1->equip( s1->createMateria( "ice" ) ); */
  /* } */
  /* c1->equip( m1 ); */
  /* c1->equip( m2 ); */
  /* c2->unequip( 0 ); */
  /* for( i = 0 - 1; i < tg_inventorySize + 1; i++ ) { */
  /*   c2->unequip( i ); */
  /*   c1->unequip( i ); */
  /* } */
  /* c1->unequip( 0 ); */
  /* c1->equip( m1 ); */
  /* c2->equip( m2 ); */
  /* for( i = 0 - 1; i < tg_inventorySize + 1; i++ ) { */
  /*   c2->equip( m1 ); */
  /*   c2->equip( m2 ); */
  /* } */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( use )"; */
  /* std::cout << std::endl << std::endl; */
#if defined( DEBUG )
  /* c1->displayInventory(); */
  /* c2->displayInventory(); */
#endif
  /* for( i = 0; i < tg_inventorySize + 1; i++ ) { */
  /*   c1->use( i, *c2 ); */
  /* } */
  /* c1->use( 0, *c2 ); */
  /* c1->use( 1, *c2 ); */
  /* c1->use( 0, *c1 ); */
  /* c1->use( 1, *c1 ); */
  /* c2->use( 0, *c2 ); */
  /* c2->use( 1, *c2 ); */
  /* c2->use( 0, *c1 ); */
  /* c2->use( 1, *c1 ); */
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( Character copy assignment )"; */
  /* std::cout << std::endl << std::endl; */
#if defined( DEBUG )
  /* c1->displayInventory(); */
  /* c2->displayInventory(); */
#endif
  /* *c1 = *c2; */
#if defined( DEBUG )
  /* c1->displayInventory(); */
  /* c2->displayInventory(); */
#endif
  /* std::cerr << " ---> " << __func__ << "( Character copy constructor )"; */
  /* std::cout << std::endl << std::endl; */
  /* ICharacter* c3 = new Character( *c2 ); */
#if defined( DEBUG )
  /* c3->displayInventory(); */
#endif
  /* t_next(); */

  /* std::cerr << " ---> " << __func__ << "( Character destructor )"; */
  /* std::cout << std::endl << std::endl; */
  /* delete c1; */
  /* delete c2; */
  /* delete c3; */
  /* delete s1; */
  /* t_next(); */
  /* return; */
}

/*
 *  ./a.out | cat -e * shoots an ice bolt at bob *$ * heals bob's wounds *$
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
 *  I ran into a problem that I thought was an infinite loop in
 *  Character::Character( ICharacter const& src ), the problem turned out to be
 *  my attempt to print src using the output operator while src being the
 *  Character's interface it does not have any implementation for such output
 *  operator handling.
 *
 * Check anytime if a Materia is equipped or unequipped with: std::cout << m <<
 * " status: " << m->checkLockStatus();
 *
 * TODO check if abstract class dont need same treatment as interfaces..
 *
 */

int main( void ) {
  /* t_next(); */
  /* t_default(); */
  /* t_custom(); */

  AMateria* m0 = new Ice();
  (void)m0;

  /* AMateria* m1 = new Ice( *m0 ); */
  /* (void)m1; */

  /* src/AMateria.cpp CONSTRUCTED ice{free} */
  /* src/Ice.cpp CONSTRUCTED ice{busy} */
  /* src/AMateria.cpp CONSTRUCTED ice{free} */
  /* src/Ice.cpp COPY CONSTRUCTED ice{free} FROM ice{busy} */

  AMateria* m1 = m0->clone();
  (void)m1;

  /* src/AMateria.cpp CONSTRUCTED ice{free} */
  /* src/Ice.cpp CONSTRUCTED ice{busy} */
  /* src/AMateria.cpp COPY CONSTRUCTED ice{free} FROM ice{busy} */

  std::cout << *m1 << m1 << std::endl;

  /*   m1->displayFreeMaterias(); */

  delete m1;  // TODO m1 must be destroyed because it is not handled

  return 0;
}
