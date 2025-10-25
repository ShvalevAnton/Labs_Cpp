#include "Functions.h"
#include "DivideByZeroError.h"

float quotient(int numerator, int denominator) {
   if (denominator == 0) {
      throw DivideByZeroError();
   }
   return static_cast<float>(numerator) / denominator;
}