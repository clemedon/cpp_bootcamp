// @author    Clément Vidon
// @created   230417 15:59:40  by  clem@spectre
// @modified  230417 16:00:26  by  clem@spectre
// @filename  main.cpp

#include <cassert>
#include <iostream>
#include <list>

#include "MutantStack.hpp"

void subjectTest( void ) {
  std::cout << "** MutantStack Output **" << std::endl;
  MutantStack<int> mstack;
  mstack.push( 5 );
  mstack.push( 17 );
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push( 3 );
  mstack.push( 5 );
  mstack.push( 737 );
  //[...]
  mstack.push( 0 );
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while( it != ite ) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s( mstack );
  return;
}

void verify( void ) {
  std::cout << "** std::list Output **" << std::endl;
  std::list<int> lstack;
  lstack.push_back( 5 );
  lstack.push_back( 17 );
  std::cout << lstack.back() << std::endl;
  lstack.pop_back();
  std::cout << lstack.size() << std::endl;
  lstack.push_back( 3 );
  lstack.push_back( 5 );
  lstack.push_back( 737 );
  //[...]
  lstack.push_back( 0 );
  std::list<int>::iterator it = lstack.begin();
  std::list<int>::iterator ite = lstack.end();
  ++it;
  --it;
  while( it != ite ) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::list<int> > s( lstack );
  return;
}

void myTest( void ) {
  std::cout << "** My Tests **" << std::endl;

  // constructor
  MutantStack<int> stack1;
  assert( stack1.size() == 0 );

  // push, pop, top
  stack1.push( 1 );
  stack1.push( 2 );
  stack1.push( 3 );
  assert( stack1.top() == 3 );
  stack1.pop();
  assert( stack1.top() == 2 );

  // copy constructor
  MutantStack<int> stack2( stack1 );
  MutantStack<int> stack3;

  // assignment operator
  stack3 = stack1;
  assert( stack2.top() == stack3.top() );

  // Test iterator functions
  assert( stack1.begin() != stack1.end() );
  assert( *stack1.begin() == 1 );
  assert( *( --stack1.end() ) == 2 );
  assert( stack1.rbegin() != stack1.rend() );
  assert( *stack1.rbegin() == 2 );
  assert( *( --stack1.rend() ) == 1 );

  // Test const_iterator functions
  const MutantStack<int>& stack4 = stack1;
  assert( stack4.begin() != stack4.end() );
  assert( *stack4.begin() == 1 );
  assert( *( --stack4.end() ) == 2 );
  assert( stack4.rbegin() != stack4.rend() );
  assert( *stack4.rbegin() == 2 );
  assert( *( --stack4.rend() ) == 1 );

  std::cout << ">> OK <<" << std::endl;
  return;
}

/**
 * 'MutantStack<T>' inherit 'c' member from its base class 'std::stack<T>', it
 * represents the underlying container of the stack and it is used by the stack
 * operations to store and retrieve elements.  'MutantStack<T>' can access it
 * directly with 'std::stack<T>::c' or simply with 'this->c'.
 */

int main( void ) {
  subjectTest();
  verify();
  myTest();
  return 0;
}
