#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <string>

#include "phonebook.h"

#include "Contact.hpp"

/**
 * Manage the list of contacts
 *
 * Add new contacts, search, select and display them.
 */

class PhoneBook {
 public:
  PhoneBook( void );
  ~PhoneBook( void );
  void add_contact( void );
  void search_contact( void );

 private:
  std::string format_tab_str( std::string str, size_t colsize );
  bool        isnum( std::string const& str );
  std::string itos( int num );
  int         stoi( std::string const& str );

  void new_contact_banner( void );
  void add_secret( std::string& input );
  void add_phonenum( std::string& input );
  void add_nickname( std::string& input );
  void add_lastname( std::string& input );
  void add_firstname( std::string& input );

  void display_contacts( void );
  bool check_input_id( std::string const& id );
  void display_contact( int id );
  void display_none( void );

 private:
  Contact    _contact[MAX_CONTACT];
  static int _count;
  int        _id;
};

#endif
