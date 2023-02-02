#include "PhoneBook.hpp"
#include "phonebook.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

int PhoneBook::_count = -1;

PhoneBook::PhoneBook( void ) {
  this->_id = -1;
}

PhoneBook::~PhoneBook( void ) {
}

/**
 * @brief       Format a string so that it fits a table column
 *
 * (foo, 3) will return "fo."
 *
 * @param[in]   str a string
 * @param[in]   colsize the max length of the column
 * @return      a new string
 */

std::string PhoneBook::_format_tab_str( std::string str, int colsize ) {
  int len;

  len = str.length();
  if( len >= colsize ) {
    str.resize( colsize - 1 );
    str.resize( colsize, '.' );
  }
  return str;
}

/**
 * @brief       Check if a string is a number
 *
 * @param[in]   str a string
 * @return      true or fasle
 */

bool PhoneBook::_isnum( std::string const& str ) {
  return str.find_first_not_of( "0123456789" ) == std::string::npos;
}

/**
 * @brief       Turn integer into string
 *
 * @param[in]   num an integer
 * @return      a string
 */

std::string PhoneBook::_itos( int num ) {
  std::stringstream ss;
  std::string       str;

  ss << num;
  ss >> str;
  return str;
}

/**
 * @brief       Turn string into integer
 *
 * @param[in]   str a string
 * @return      an integer
 */

int PhoneBook::_stoi( std::string const& str ) {
  std::stringstream ss;
  int               num;

  ss << str;
  ss >> num;
  return num;
}

/**
 * @brief       Print 'new contact' banner
 */

void PhoneBook::_new_contact_banner( void ) {
  CLEAR;
  std::cout << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << "      * NEW    CONTACT *" << std::endl;
  std::cout << "      * CONTACT    NEW *" << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << std::endl;
}

/**
 * @brief       Ask for new contact secret
 *
 * @param[i/o]  input the secret storage
 */

void PhoneBook::_add_secret( std::string& input ) {
  while( true ) {
    this->_new_contact_banner();
    std::cout << "  Contact Darkest Secret 5/5" << std::endl;
    std::cout << std::endl;
    std::cout << "     (50 characters max)" << std::endl;
    std::cout << "                                                   ↓"
              << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      CLEAR;
      std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
      exit( 1 );
    }
    if( input.empty() || input.length() > 50 ) {
      continue;
    }
    break;
  }
}

/**
 * @brief       Ask for new contact phone number
 *
 * @param[i/o]  input the phone number storage
 */

void PhoneBook::_add_phonenum( std::string& input ) {
  while( true ) {
    this->_new_contact_banner();
    std::cout << "  Contact Phone Number   4/5" << std::endl;
    std::cout << std::endl;
    std::cout << "       (15 digits max)" << std::endl;
    std::cout << "                ↓" << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      CLEAR;
      std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
      exit( 1 );
    }
    if( input.empty() || input.length() > 15 || !this->_isnum( input ) ) {
      continue;
    }
    break;
  }
}

/**
 * @brief       Ask for new contact nick name
 *
 * @param[i/o]  input the nick name storage
 */

void PhoneBook::_add_nickname( std::string& input ) {
  while( true ) {
    this->_new_contact_banner();
    std::cout << "  Contact Nick Name      3/5" << std::endl;
    std::cout << std::endl;
    std::cout << "     (20 characters max)" << std::endl;
    std::cout << "                     ↓" << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      CLEAR;
      std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
      exit( 1 );
    }
    if( input.empty() || input.length() > 20 ) {
      continue;
    }
    break;
  }
}

/**
 * @brief       Ask for new contact last name
 *
 * @param[i/o]  input the last name storage
 */

void PhoneBook::_add_lastname( std::string& input ) {
  while( true ) {
    this->_new_contact_banner();
    std::cout << "  Contact Last Name      2/5" << std::endl;
    std::cout << std::endl;
    std::cout << "     (20 characters max)" << std::endl;
    std::cout << "                     ↓" << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      CLEAR;
      std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
      exit( 1 );
    }
    if( input.empty() || input.length() > 20 ) {
      continue;
    }
    break;
  }
}

/**
 * @brief       Ask for new contact first name
 *
 * @param[i/o]  input the first name storage
 */

void PhoneBook::_add_firstname( std::string& input ) {
  while( true ) {
    this->_new_contact_banner();
    std::cout << "  Contact First Name     1/5" << std::endl;
    std::cout << std::endl;
    std::cout << "     (20 characters max)" << std::endl;
    std::cout << "                     ↓" << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      CLEAR;
      std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
      exit( 1 );
    }
    if( input.empty() || input.length() > 20 ) {
      continue;
    }
    break;
  }
}

/**
 * @brief       Add a new contact to the phonebook
 */

void PhoneBook::add_contact( void ) {
  std::string firstname;
  std::string lastname;
  std::string nickname;
  std::string phonenum;
  std::string secret;
  int         i;

  i = MAX_CONTACT;
  while( --i > 0 ) {
    this->_contact[i] = this->_contact[i - 1];
  }
  _add_firstname( firstname );
  _add_lastname( lastname );
  _add_nickname( nickname );
  _add_phonenum( phonenum );
  _add_secret( secret );
  this->_contact[0].set_firstname( firstname );
  this->_contact[0].set_lastname( lastname );
  this->_contact[0].set_nickname( nickname );
  this->_contact[0].set_phonenum( phonenum );
  this->_contact[0].set_secret( secret );
  this->_count += ( this->_count < MAX_CONTACT - 1 );
}

/**
 * @brief       Display all the phonebook contacts
 */

void PhoneBook::_display_contacts( void ) {
  int      id;
  Contact* contact = this->_contact;

  CLEAR;
  std::cout << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << "      * SEARCH CONTACT *" << std::endl;
  std::cout << "      * CONTACT SEARCH *" << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << std::endl;
  std::cout << "  +----------+----------+----------+----------+" << std::endl;
  std::cout << "  |Index     |FirstName |LastName  |NickName  |" << std::endl;
  std::cout << "  +----------+----------+----------+----------+" << std::endl;
  id = 0;
  while( id < MAX_CONTACT ) {
    if( !contact[id].get_firstname().empty() ) {
      std::cout << "  |";
      std::cout.width( 10 );
      std::cout << std::right << this->_format_tab_str( _itos( id + 1 ), 10 );
      std::cout << "|";
      std::cout.width( 10 );
      std::cout << std::right
                << this->_format_tab_str( contact[id].get_firstname(), 10 );
      std::cout << "|";
      std::cout.width( 10 );
      std::cout << std::right
                << this->_format_tab_str( contact[id].get_lastname(), 10 );
      std::cout << "|";
      std::cout.width( 10 );
      std::cout << std::right
                << this->_format_tab_str( contact[id].get_nickname(), 10 );
      std::cout << "|" << std::endl;
    }
    ++id;
  }
  std::cout << "  +----------+----------+----------+----------+" << std::endl;
  std::cout << std::endl;
}

/**
 * @brief       Display a contact
 */

void PhoneBook::_display_contact( int id ) {
  CLEAR;
  std::cout << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << "      * FOUND  CONTACT *" << std::endl;
  std::cout << "      * CONTACT  FOUND *" << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << std::endl;
  std::cout << "  First Name     → ";
  std::cout << this->_contact[id].get_firstname() << std::endl;
  std::cout << "  Last Name      → ";
  std::cout << this->_contact[id].get_lastname() << std::endl;
  std::cout << "  Nick Name      → ";
  std::cout << this->_contact[id].get_nickname() << std::endl;
  std::cout << "  Phone Number   → ";
  std::cout << this->_contact[id].get_phonenum() << std::endl;
  std::cout << "  Darkest Secret → ";
  std::cout << this->_contact[id].get_secret() << std::endl;
  std::cout << std::endl;
  std::cout << "Press ENTER to continue";
  std::cin.ignore();
  return;
}

/**
 * @brief       Display zero contact
 */

void PhoneBook::_display_none( void ) {
  CLEAR;
  std::cout << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << "      * SEARCH CONTACT *" << std::endl;
  std::cout << "      * CONTACT SEARCH *" << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << std::endl;
  std::cout << "  /! THERE IS NO ONE HERE !\\" << std::endl;
  std::cout << "              -             " << std::endl;
  std::cout << "  start by ADD-ing a contact" << std::endl;
  std::cout << std::endl;
  std::cout << "Press ENTER to continue";
  std::cin.ignore();
}

/**
 * @brief       Check that the index value is valid
 *
 * @param[in]   input a contact index
 * @return      true or false
 */

bool PhoneBook::_check_input_id( std::string const& input ) {
  int id;

  if( input.length() != 1 || !_isnum( input ) ) {
    return false;
  }
  id = this->_stoi( input ) - 1;
  if( id < 0 || id > this->_count ) {
    return false;
  }
  return true;
}

/**
 * @brief       Search a contact
 */

void PhoneBook::search_contact( void ) {
  std::string input;
  int         id;

  if( this->_count == -1 ) {
    this->_display_none();
  } else if( this->_count == 0 ) {
    this->_display_contact( 0 );
  } else {
    while( true ) {
      this->_display_contacts();
      std::cout << "  Enter an Index" << std::endl;
      std::cout << std::endl;
      std::cout << "> ";
      id = -1;
      if( !std::getline( std::cin, input ) ) {
        CLEAR;
        std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
        exit( 1 );
      }
      if( input.empty() ) {
        break;
      }
      if( !_check_input_id( input ) ) {
        continue;
      }
      id = this->_stoi( input );
      this->_display_contact( id - 1 );
      break;
    }
  }
}
