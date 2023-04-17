// @author    Clément Vidon
// @created   230417 10:34:59  by  clem@spectre
// @modified  230417 10:35:19  by  clem@spectre
// @filename  utils.cpp

#include <sstream>
#include <string>

#include "utils.hpp"

/**
 * @brief       Turn integer into string
 *
 * @param[in]   num an integer
 * @return      a string
 */

std::string intToString( int num ) {
  std::stringstream ss;
  std::string       str;

  ss << num;
  ss >> str;
  return str;
}
