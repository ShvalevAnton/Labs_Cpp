#pragma once

#include <iostream>
#include <string>

using namespace std;

class ExScore //класс исключений
{
public:
   string origin; //для имени функции
   int iValue;    //для хранения ошибочного значения

   ExScore(string orig , int sc);
};