#include "Contact.hpp"
#include "phonebook.h"

#include <string>

Contact::Contact( void ) {
  this->_firstname = "";
  this->_lastname = "";
  this->_nickname = "";
  this->_phonenum = "";
  this->_secret = "";
}

Contact::~Contact( void ) {
}

std::string Contact::get_firstname( void ) const {
  return this->_firstname;
}

std::string Contact::get_lastname( void ) const {
  return this->_lastname;
}

std::string Contact::get_nickname( void ) const {
  return this->_nickname;
}

std::string Contact::get_phonenum( void ) const {
  return this->_phonenum;
}

std::string Contact::get_secret( void ) const {
  return this->_secret;
}

void Contact::set_firstname( std::string firstname ) {
  this->_firstname = firstname;
}

void Contact::set_lastname( std::string lastname ) {
  this->_lastname = lastname;
}

void Contact::set_nickname( std::string nickname ) {
  this->_nickname = nickname;
}

void Contact::set_phonenum( std::string phonenum ) {
  this->_phonenum = phonenum;
}

void Contact::set_secret( std::string secret ) {
  this->_secret = secret;
}
