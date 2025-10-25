#include "DivideByZeroError.h"
#include <iostream>

DivideByZeroError::DivideByZeroError() : message("Деление на нуль") {
}

void DivideByZeroError::printMessage() const {
   cout << message << endl;
}