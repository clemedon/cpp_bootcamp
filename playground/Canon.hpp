#ifndef CANON_HPP_
#define CANON_HPP_

#include <iostream>
#include <string>

/**
 * TODO
 *
 * TODO
 */

class Canon {
 public:
  Canon (void);
  Canon (int const foo);
  Canon (Canon const& src);
  ~Canon (void);
  Canon&      operator= (Canon const& src);
  void        print (std::ostream& stream) const;
  std::string to_string (void) const;

 private:
  int _foo;
};

std::ostream& operator<< (std::ostream& stream, Canon const& canon);

#endif  // CANON_HPP_
