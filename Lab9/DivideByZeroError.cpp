#include "DivideByZeroError.h"
#include <iostream>

DivideByZeroError::DivideByZeroError() : message("������� �� ����") {
}

void DivideByZeroError::printMessage() const {
   cout << message << endl;
}