#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iosfwd>
#include <string>

/**
 * @brief       Generic Linked List
 *
 * @param[out]  TODO
 * @param[in]   TODO
 * @return      TODO
 */

template <class T>
class Node {
 public:
  T     data;
  Node* next;  // TODO <T>?
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
  void delOne( T const& target );

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
#if defined( DEBUG )
  std::cerr << "---------------------LINKEDLIST CONSTRUCTOR";
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

template <class T>
LinkedList<T>::LinkedList( LinkedList const& src ) : _head( NULL ) {
#if defined( DEBUG )
  std::cerr << "---------------------LINKEDLIST COPY CONSTRUCTOR";
  std::cerr << std::endl;
#endif
  Node<T>* curr;

  curr = src._head;
  while( curr != NULL ) {
    addBack( curr->data );
    curr = curr->next;
  }
  return;
}

/**
 * @brief       Destructor
 */

template <class T>
LinkedList<T>::~LinkedList( void ) {
#if defined( DEBUG )
  std::cerr << "---------------------LINKEDLIST DESTRUCTOR";
  std::cerr << std::endl;
#endif
  Node<T>* curr;
  Node<T>* next;

  curr = this->_head;
  while( curr != NULL ) {
    next = curr->next;
    delete curr;
    curr = next;
#if defined( DEBUG )
    std::cerr << "---------------------LINKEDLIST delete node";
    std::cerr << std::endl;
#endif
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

template <class T>
LinkedList<T>& LinkedList<T>::operator=( LinkedList<T> const& rhs ) {
#if defined( DEBUG )
  std::cerr << "---------------------" << __func__;
  std::cerr << std::endl;
#endif
  Node<T>* curr;
  Node<T>* next;

  if( this == &rhs ) {
    return *this;
  }
  curr = this->_head;
  while( curr != NULL ) {
    next = curr->next;
    delete curr;
    curr = next;
  }
  this->_head = NULL;
  curr = rhs._head;
  while( curr != NULL ) {
    addBack( curr->data );
    curr = curr->next;
  }
  return *this;
}

/**
 * @brief       Print State
 */

template <class T>
void LinkedList<T>::print( std::ostream& o ) const {
  Node<T>* curr;

  curr = this->_head;
  while( curr ) {
    o << *curr->data << " ";
    curr = curr->next;
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
#if defined( DEBUG )
  std::cerr << "---------------------" << __func__;
  std::cerr << std::endl;
#endif
  Node<T>* newNode;

  newNode = new Node<T>();
  newNode->data = this->newData;
  newNode->next = this->_head;
  this->_size++;
  return;
}

/**
 * @brief       Add a node to the end of the list
 */

template <class T>
void LinkedList<T>::addBack( T const& newData ) {
#if defined( DEBUG )
  std::cerr << "---------------------" << __func__;
  std::cerr << std::endl;
#endif
  Node<T>* newNode;
  Node<T>* curr;

  newNode = new Node<T>();
  newNode->data = newData;
  newNode->next = NULL;

  if( this->_head == NULL ) {
    this->_head = newNode;
  } else {
    curr = this->_head;
    while( curr->next != NULL )
      curr = curr->next;
    curr->next = newNode;
  }
  return;
}

/**
 * @brief       Delete a node from the list
 */

template <typename T>
void LinkedList<T>::delOne( T const& data ) {
#if defined( DEBUG )
  std::cerr << "---------------------" << __func__;
  std::cerr << std::endl;
#endif
  Node<T>* curr;
  Node<T>* prev;

  curr = this->_head;
  prev = NULL;

  while( curr != NULL && curr->data != data ) {
    prev = curr;
    curr = curr->next;
  }
  if( curr == NULL ) {
    return;
  }
  if( prev == NULL ) {
    curr = curr->next;
  } else {
    prev->next = curr->next;
  }
  delete curr;
}

#endif  // LINKEDLIST_HPP_
