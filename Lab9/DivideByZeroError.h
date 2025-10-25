#pragma once

#include <iostream>
#include <string>

using namespace std;

class DivideByZeroError {
public:
    DivideByZeroError();
    void printMessage() const;

private:
    string message;
};