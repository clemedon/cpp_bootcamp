// @author    Clément Vidon
// @created   230324 11:42:05  by  clem@spectre
// @modified  230324 11:42:08  by  clem@spectre
// @filename  Contact.cpp

#include <string>

#include "phonebook.h"

#include "Contact.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Contact::Contact( void )
  : _firstname( "" ),
    _lastname( "" ),
    _phonenum( "" ),
    _secret( "" ) {
  return;
}

/**
 * @brief       Default Destructor
 */

Contact::~Contact( void ) {
  return;
}

/* ---------------------------------------------- */

std::string Contact::get_firstname( void ) const {
  return _firstname;
}

std::string Contact::get_lastname( void ) const {
  return _lastname;
}

std::string Contact::get_nickname( void ) const {
  return _nickname;
}

std::string Contact::get_phonenum( void ) const {
  return _phonenum;
}

std::string Contact::get_secret( void ) const {
  return _secret;
}

void Contact::set_firstname( std::string firstname ) {
  _firstname = firstname;
  return;
}

void Contact::set_lastname( std::string lastname ) {
  _lastname = lastname;
  return;
}

void Contact::set_nickname( std::string nickname ) {
  _nickname = nickname;
  return;
}

void Contact::set_phonenum( std::string phonenum ) {
  _phonenum = phonenum;
  return;
}

void Contact::set_secret( std::string secret ) {
  _secret = secret;
  return;
}
