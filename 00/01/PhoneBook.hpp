#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "Contact.hpp"
#include "phonebook.h"

#include <string>

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
  Contact    _contact[MAX_CONTACT];
  static int _count;
  int        _id;
  /* utils */
  std::string _format_tab_str( std::string str, int colsize );
  bool        _isnum( std::string const& str );
  std::string _itos( int num );
  int         _stoi( std::string const& str );
  /* ADD */
  void _new_contact_banner( void );
  void _add_secret( std::string& input );
  void _add_phonenum( std::string& input );
  void _add_nickname( std::string& input );
  void _add_lastname( std::string& input );
  void _add_firstname( std::string& input );
  /* SEARCH */
  void _display_contacts( void );
  bool _check_input_id( std::string const& id );
  void _display_contact( int id );
  void _display_none( void );
};

#endif
