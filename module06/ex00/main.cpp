#include <iostream>
#include "castor.hpp"

/** Underflow:
 *
 *  Underflow is a concept that is specific to floating-point values and does
 *  not apply to non-floating-point values.
 *
 *  Underflow occurs when the magnitude of the number is smaller than the
 *  smallest representable value.  If a number is smaller than the smallest
 *  positive value that can be represented by a float data type, it will result
 *  in underflow. The number will be rounded down to zero, and the precision of
 *  the number will be lost.
 *
 *  Underflow does not occur when a number is smaller than the smallest negative
 *  value that can be represented by a float data type because the negative
 *  values are represented by the sign bit of the float data type. Numbers
 *  smaller than the smallest negative value are simply negative numbers with a
 *  smaller magnitude.
 *
 * Overflow:
 *
 *  Overflow can occur in both floating-point and non-floating-point numbers.
 *
 *  In the case of non-floating-point numbers overflow occurs when the result of
 *  an arithmetic operation exceeds the largest representable value for that
 *  type whether negative or positive.
 *
 *  In the case of floating-point numbers, overflow occurs when the magnitude of
 *  a number becomes too large to be represented by the data type. The number
 *  will be rounded to infinity or to the largest representable value of the
 *  data type, and the precision of the number will be lost.
 *
 *
 * out_of_range:
 *
 *  occurs when *the input value* to a function is outside the range of values
 *  that the function can handle.
 *
 * overflow_error:
 *
 *  occurs when *the result of a mathematical operation* exceeds the largest
 *  representable value for the data type.
 *
 * Float:
 *
 *  std::numeric_limits<float>::infinity()   == inf           == overflow
 *  std::numeric_limits<float>::max()        == 3.40282e+38   < overflow
 *  std::numeric_limits<float>::min()        == 1.17549e-38   > underflow
 *  std::numeric_limits<float>::lowest()     == -3.40282e+38  > overflow
 *
 *    -inff < -3.4e+38f <= float <= -3.4e+38f < inff
 */

int main() {
  tests();

  /* std::string const = "0.1"; */
  std::cout << std::endl;
  return 0;
}
