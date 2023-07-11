/* src/RPN */
/* Created: 230705 17:29:53 by clem@spectre */
/* Updated: 230705 17:29:53 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

#include "RPN.hpp"

/*  CANON
    ------------------------------------------------- */

RPN::RPN( void ) {}

RPN::RPN( RPN const& src ) { _operands = src._operands; }

RPN::~RPN( void ) {}

RPN& RPN::operator=( RPN const& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  _operands = rhs._operands;
  return *this;
}

/* ---------------------------------------------- */

/**
 * @brief       Perform the corresponding operation.
 */

int RPN::performOperation( char operation, int operandA, int operandB ) {
  switch( operation ) {
    case '+':
      return operandA + operandB;
    case '-':
      return operandA - operandB;
    case '*':
      return operandA * operandB;
    case '/':
      if( operandB == 0 ) {
        throw std::runtime_error( "Error: Division by zero." );
      }
      return operandA / operandB;
    default:
      return 0;
  }
}

/**
 * @brief       The supported operators.
 */

bool RPN::isOperator( char c ) {
  return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

/**
 * @brief       Evaluate an RPN expression and return the result as an integer.
 *
 * - create operands an empty stack of integers
 * - tokenize the string expression using space characters as delimiters
 * - for each token, check if it is a digit or an operator
 * - if digit convert to int and push onto operands stack
 * - if operator pops the top two integers from operands, perform the operation
 *   and push the result back onto operands stack
 * - after iterating over all tokens, if there is exactly one integer left on
 *   the operands stack this is the result returned.
 *
 * Subsequent calls to strtok with a null pointer as the first argument and the
 * same set of delimiters will continue to tokenize the remaining part of the
 * input string until there are no more tokens left. The null pointer tells
 * strtok to continue where it left off in the previous call.
 */

int RPN::evaluateExpression( char* expression ) {
  std::stack<int> operands;
  int             operandA;
  int             operandB;

  const char* token = std::strtok( expression, " " );
  while( token != NULL ) {
    const size_t len = std::strlen( token );

    for( size_t i = 0; i < len; i++ ) {
      if( isdigit( token[i] ) ) {
        operands.push( token[i] - '0' );
      } else if( isOperator( token[i] ) ) {
        if( operands.size() < 2 ) {
          throw std::runtime_error( "Error: Invalid expression." );
        }
        operandB = operands.top();
        operands.pop();
        operandA = operands.top();
        operands.pop();
        operands.push( performOperation( token[i], operandA, operandB ) );
      } else {
        std::string errorMsg = "Error: Invalid character '";
        errorMsg += token[i];
        errorMsg += "' in expression.";
        throw std::runtime_error( errorMsg );
        return 0;
      }
      if( i > 0 && isdigit( token[i - 1] ) && isdigit( token[i] ) ) {
        throw std::runtime_error(
          "Error: Double-digit operand without separation." );
        return 0;
      }
    }

    token = std::strtok( NULL, " " );
  }

  if( operands.size() == 1 ) {
    return operands.top();
  } else {
    throw std::runtime_error( "Error: Invalid expression." );
    return 0;
  }
}
