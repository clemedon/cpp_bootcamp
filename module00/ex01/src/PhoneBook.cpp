// @author    Clément Vidon
// @created   230324 11:42:14  by  clem@spectre
// @modified  230324 11:42:16  by  clem@spectre
// @filename  PhoneBook.cpp

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "phonebook.h"

#include "PhoneBook.hpp"

int PhoneBook::_count = -1;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

PhoneBook::PhoneBook( void ) {
  return;
}

/**
 * @brief       Default Destructor
 */

PhoneBook::~PhoneBook( void ) {
  return;
}

/* ---------------------------------------------- */

/**
 * @brief       Format a string so that it fits a table column
 *
 * (foo, 3) will return "fo."
 *
 * @param[in]   str a string
 * @param[in]   colsize the max length of the column
 * @return      a new string
 */

std::string PhoneBook::format_tab_str( std::string str, size_t colsize ) {
  size_t len;

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

bool PhoneBook::isnum( std::string const& str ) {
  return str.find_first_not_of( "0123456789" ) == std::string::npos;
}

/**
 * @brief       Turn integer into string
 *
 * @param[in]   num an integer
 * @return      a string
 */

std::string PhoneBook::itos( int num ) {
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

int PhoneBook::stoi( std::string const& str ) {
  std::stringstream ss;
  int               num;

  ss << str;
  ss >> num;
  return num;
}

/**
 * @brief       Print 'new contact' banner
 */

void PhoneBook::new_contact_banner( void ) {
  CLEAR;
  std::cout << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << "      * NEW    CONTACT *" << std::endl;
  std::cout << "      * CONTACT    NEW *" << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Ask for new contact secret
 *
 * @param[i/o]  input the secret storage
 */

void PhoneBook::add_secret( std::string& input ) {
  while( true ) {
    new_contact_banner();
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

void PhoneBook::add_phonenum( std::string& input ) {
  while( true ) {
    new_contact_banner();
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
    if( input.empty() || input.length() > 15 || !isnum( input ) ) {
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

void PhoneBook::add_nickname( std::string& input ) {
  while( true ) {
    new_contact_banner();
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

void PhoneBook::add_lastname( std::string& input ) {
  while( true ) {
    new_contact_banner();
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

void PhoneBook::add_firstname( std::string& input ) {
  while( true ) {
    new_contact_banner();
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
    _contact[i] = _contact[i - 1];
  }
  add_firstname( firstname );
  add_lastname( lastname );
  add_nickname( nickname );
  add_phonenum( phonenum );
  add_secret( secret );
  _contact[0].set_firstname( firstname );
  _contact[0].set_lastname( lastname );
  _contact[0].set_nickname( nickname );
  _contact[0].set_phonenum( phonenum );
  _contact[0].set_secret( secret );
  _count += ( _count < MAX_CONTACT - 1 );
  return;
}

/**
 * @brief       Display all the phonebook contacts
 */

void PhoneBook::display_contacts( void ) {
  int      id;
  Contact* contact = _contact;

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
      std::cout << std::right << format_tab_str( itos( id + 1 ), 10 );
      std::cout << "|";
      std::cout.width( 10 );
      std::cout << std::right
                << format_tab_str( contact[id].get_firstname(), 10 );
      std::cout << "|";
      std::cout.width( 10 );
      std::cout << std::right
                << format_tab_str( contact[id].get_lastname(), 10 );
      std::cout << "|";
      std::cout.width( 10 );
      std::cout << std::right
                << format_tab_str( contact[id].get_nickname(), 10 );
      std::cout << "|" << std::endl;
    }
    ++id;
  }
  std::cout << "  +----------+----------+----------+----------+" << std::endl;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Display a contact
 */

void PhoneBook::display_contact( int id ) {
  CLEAR;
  std::cout << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << "      * FOUND  CONTACT *" << std::endl;
  std::cout << "      * CONTACT  FOUND *" << std::endl;
  std::cout << "      ******************" << std::endl;
  std::cout << std::endl;
  std::cout << "  First Name     → ";
  std::cout << _contact[id].get_firstname() << std::endl;
  std::cout << "  Last Name      → ";
  std::cout << _contact[id].get_lastname() << std::endl;
  std::cout << "  Nick Name      → ";
  std::cout << _contact[id].get_nickname() << std::endl;
  std::cout << "  Phone Number   → ";
  std::cout << _contact[id].get_phonenum() << std::endl;
  std::cout << "  Darkest Secret → ";
  std::cout << _contact[id].get_secret() << std::endl;
  std::cout << std::endl;
  std::cout << "Press ENTER to continue";
  std::cin.ignore();
  return;
}

/**
 * @brief       Display zero contact
 */

void PhoneBook::display_none( void ) {
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
  return;
}

/**
 * @brief       Check that the index value is valid
 *
 * @param[in]   input a contact index
 * @return      true or false
 */

bool PhoneBook::check_input_id( std::string const& input ) {
  int id;

  if( input.length() != 1 || !isnum( input ) ) {
    return false;
  }
  id = stoi( input ) - 1;
  if( id < 0 || id > _count ) {
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

  if( _count == -1 ) {
    display_none();
  } else if( _count == 0 ) {
    display_contact( 0 );
  } else {
    while( true ) {
      display_contacts();
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
      if( !check_input_id( input ) ) {
        continue;
      }
      id = stoi( input );
      display_contact( id - 1 );
      break;
    }
  }
}
