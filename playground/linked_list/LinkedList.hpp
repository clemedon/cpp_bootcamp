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
  Node<T>* current;
  Node<T>* next;

  current = this->_head;
  while( current != NULL ) {
    next = current->next;
    delete current;
    current = next;
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

template <class T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList<T> const& rhs ) {
  std::cerr << " " << __func__ << std::endl;
  Node<T>* current;
  Node<T>* next;

  if( this == &rhs ) {
    return *this;
  }
  current = this->_head;
  while( current != NULL ) {
    next = current->next;
    delete current;
    current = next;
  }
  this->_head = NULL;
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

  current = this->_head;
  while( current ) {
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
  newNode->next = this->_head;
  this->_head = newNode;
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
  if( this->_head == NULL ) {
    this->_head = newNode;
  } else {
    current = this->_head;
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

  current = this->_head;
  previous = NULL;
  while( current != NULL ) {
    if( current->data == data ) {
      if( previous == NULL ) {
        this->_head = current->next;
        delete current;
        current = this->_head;
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

#endif  // LINKEDLIST_HPP_
