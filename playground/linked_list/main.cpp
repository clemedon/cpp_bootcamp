/**
 * @author    Clément Vidon
 * @brief     Singly linked-list custom template tests.
 * @date      230301
 * @file      main.cp
 */

#include <iostream>
#include "LinkedList.hpp"

/* Color.hpp */

class Color {
 public:
  Color( int r, int g, int b ) : _r( r ), _g( g ), _b( b ) {
    _history.addBack( this );  // use the LL within a member function
    return;
  }

  void print( std::ostream& o ) const {
    o << "(" << _r << ", " << _g << ", " << _b << ")";
    return;
  }

  void printHistory( void ) const {
    std::cout << _history;
    std::cout << std::endl;
    return;
  }

 public:
  static LinkedList<Color*> _history;  // declare the LL

 private:
  int _r, _g, _b;
};

std::ostream& operator<<( std::ostream& o, Color const& i ) {
  i.print( o );
  return o;
}

/* Color.cpp */

LinkedList<Color*> Color::_history;  // initialize the LL

/* main.cpp */

int main( void ) {
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color  c1( 10, 10, 10 );
  Color  c2( 20, 20, 20 );
  Color* c3 = new Color( 30, 30, 30 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color::_history.addBack( c3 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color::_history.addFront( &c1 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color::_history.delFirst( &c1 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  delete c3;
}
