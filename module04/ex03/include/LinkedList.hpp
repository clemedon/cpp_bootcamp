// @author    Clément Vidon
// @created   230419 15:52:00  by  clem@spectre
// @modified  230419 16:29:48  by  clem@spectre
// @filename  LinkedList.hpp

/**
 * @author    Clément Vidon
 * @brief     Singly linked-list custom template.
 * @date      230301
 * @file      LinkedList.hpp
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iosfwd>
#include <string>

/**
 *  Generic Linked List
 */

template <class T>
class Node {
 public:
  T     data;
  Node* next;
};

template <class T>
class LinkedList {
 public:
  LinkedList( void );
  LinkedList( LinkedList const& src );
  virtual ~LinkedList( void );
  LinkedList&  operator=( LinkedList const& rhs );
  virtual void print( std::ostream& o ) const;

  void addFront( T const& newData );
  void addBack( T const& newData );
  void delFirst( T const& data );
  void clear( void );

 private:
  Node<T>* _head;
};

template <class T>
std::ostream& operator<<( std::ostream& o, LinkedList<T> const& i );

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

template <class T>
LinkedList<T>::LinkedList( void ) : _head( NULL ) {
  std::cerr << "LINKEDLIST CONSTRUCTOR" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

template <class T>
LinkedList<T>::LinkedList( LinkedList const& src ) : _head( NULL ) {
  std::cerr << "LINKEDLIST COPY CONSTRUCTOR" << std::endl;
  Node<T>* current;

  current = src._head;
  while( current != NULL ) {
    addBack( current->data );
    current = current->next;
  }
  return;
}

/**
 * @brief       Destructor
 */

template <class T>
LinkedList<T>::~LinkedList( void ) {
  std::cerr << "LINKEDLIST DESTRUCTOR" << std::endl;
  clear();
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

template <class T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList<T> const& rhs ) {
  Node<T>* current;
  Node<T>* next;

  if( this == &rhs ) {
    return *this;
  }
  current = _head;
  while( current != NULL ) {
    next = current->next;
    delete current;
    current = next;
  }
  _head = NULL;
  current = rhs._head;
  while( current != NULL ) {
    addBack( current->data );
    current = current->next;
  }
  return *this;
}

/**
 * @brief       Print State
 */

template <class T>
void LinkedList<T>::print( std::ostream& o ) const {
  Node<T>* current;

  current = _head;
  o << " list address  ";
  o << " node address  ";
  o << " data address  ";
  o << " data preview  ";
  std::cout << std::endl;
  while( current ) {
    o << " " << this;
    o << " " << current;
    o << " " << current->data;
    o << " " << *current->data;
    std::cout << std::endl;
    current = current->next;
  }
  return;
}

/**
 * @brief       Output Operator Handling
 */

template <class T>
std::ostream& operator<<( std::ostream& o, LinkedList<T> const& i ) {
  i.print( o );
  return o;
}

/*  BASIC OPERATIONS
------------------------------------------------- */

/**
 * @brief       Add a node to the front of the list
 */

template <typename T>
void LinkedList<T>::addFront( T const& newData ) {
  std::cerr << "LINKEDLIST " << __func__ << std::endl;
  Node<T>* newNode;

  newNode = new Node<T>();
  newNode->data = newData;
  newNode->next = _head;
  _head = newNode;
  return;
}

/**
 * @brief       Add a node to the back of the list
 */

template <class T>
void LinkedList<T>::addBack( T const& newData ) {
  std::cerr << "LINKEDLIST " << __func__ << std::endl;
  Node<T>* newNode;
  Node<T>* current;

  newNode = new Node<T>();
  newNode->data = newData;
  newNode->next = NULL;
  if( _head == NULL ) {
    _head = newNode;
  } else {
    current = _head;
    while( current->next != NULL )
      current = current->next;
    current->next = newNode;
  }
  return;
}

/**
 * @brief       Delete the first node with matching data
 */

template <typename T>
void LinkedList<T>::delFirst( T const& data ) {
  std::cerr << "LINKEDLIST " << __func__ << std::endl;
  Node<T>* current;
  Node<T>* previous;

  current = _head;
  previous = NULL;
  while( current != NULL ) {
    if( current->data == data ) {
      if( previous == NULL ) {
        _head = current->next;
        delete current;
        current = _head;
        return;
      } else {
        previous->next = current->next;
        delete current;
        current = previous->next;
        return;
      }
    }
    previous = current;
    current = current->next;
  }
  return;
}

template <typename T>
void LinkedList<T>::clear( void ) {
  std::cerr << "LINKEDLIST " << __func__ << std::endl;
  Node<T>* current;
  Node<T>* next;

  current = _head;
  while( current != NULL ) {
    std::cout << " delete  " << *current->data << current->data << std::endl;
    next = current->next;
    delete current->data;
    delete current;
    current = next;
  }
  _head = NULL;
}

#endif  // LINKEDLIST_HPP_
