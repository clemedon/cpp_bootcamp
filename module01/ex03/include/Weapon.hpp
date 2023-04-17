// @author    Clément Vidon
// @created   230324 11:55:45  by  clem@spectre
// @modified  230324 11:55:48  by  clem@spectre
// @filename  Weapon.hpp

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
 public:
  explicit Weapon( std::string weapon );
  ~Weapon( void );

  std::string const& getType( void ) const;
  void               setType( std::string type );

 private:
  std::string _type;
};

#endif /* WEAPON_HPP_ */
