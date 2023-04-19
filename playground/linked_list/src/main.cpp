// @author    Clément Vidon
// @created   230419 16:28:52  by  clem@spectre
// @modified  230419 16:52:04  by  clem@spectre
// @filename  main.cpp

#include <iostream>
#include "LinkedList.hpp"

/* Color.hpp */

class Color {
 public:
  Color( int r, int g, int b ) : _r( r ), _g( g ), _b( b ) { return; }

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
  Color* c1 = new Color( 10, 10, 10 );
  Color* c2 = new Color( 20, 20, 20 );
  Color* c3 = new Color( 30, 30, 30 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color::_history.addBack( c1 );
  Color::_history.addBack( c2 );
  Color::_history.addBack( c3 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color::_history.delFirst( c2 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;

  Color::_history.addFront( c2 );
  std::cout << "list:" << std::endl;
  std::cout << Color::_history << std::endl;
}
