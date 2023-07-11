/* include/RPN */
/* Created: 230705 17:29:52 by clem@spectre */
/* Updated: 230705 17:29:52 by clem@spectre */
/* Maintainer: Clément Vidon */

#ifndef RPN_HPP_
#define RPN_HPP_

#include <iosfwd>
#include <stack>
#include <string>

class RPN {
 public:
  RPN( void );
  RPN( RPN const& src );
  virtual ~RPN( void );
  RPN& operator=( RPN const& rhs );

 private:
  std::stack<int> _operands;

  int  performOperation( char operation, int operandA, int operandB );
  bool isOperator( char c );

 public:
  int evaluateExpression( char* expression );
};

#endif  // RPN_HPP_
