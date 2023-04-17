#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

#include "phonebook.h"

/**
 * Contact sheet
 *
 * Hold the contact attributes.
 */

class Contact {
 public:
  Contact( void );
  ~Contact( void );

  std::string get_firstname( void ) const;
  std::string get_lastname( void ) const;
  std::string get_nickname( void ) const;
  std::string get_phonenum( void ) const;
  std::string get_secret( void ) const;
  void        set_firstname( std::string );
  void        set_lastname( std::string );
  void        set_nickname( std::string );
  void        set_phonenum( std::string );
  void        set_secret( std::string );

 private:
  std::string _firstname;
  std::string _lastname;
  std::string _nickname;
  std::string _phonenum;
  std::string _secret;
};

#endif
