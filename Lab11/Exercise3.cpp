#include <iostream>
#include <Windows.h>
#include "Distance2.h"

using namespace std;

int Exercise3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance2 dist1(5, 6.0f); // 5 футов 6 дюймов
   Distance2 dist2(2, 3.5f); // 2 фута 3.5 дюймов

   cout << "Исходные расстояния:" << endl;
   cout << "dist1: " << dist1;
   cout << "dist2: " << dist2;

   // Тестирование операторов с разными типами
   cout << "\nОперации с разными типами:" << endl;

   // Distance2 + float
   Distance2 dist3 = dist1 + 1.5f; // 1.5 метра
   cout << "dist1 + 1.5 метра = " << dist3;

   // float + Distance2  
   Distance2 dist4 = 1.5f + dist1;
   cout << "1.5 метра + dist1 = " << dist4;

   // Distance2 - float
   Distance2 dist5 = dist1 - 0.5f; // 0.5 метра
   cout << "dist1 - 0.5 метра = " << dist5;

   // float - Distance2
   Distance2 dist6 = 3.0f - dist2; // 3.0 метра - dist2
   cout << "3.0 метра - dist2 = " << dist6;

   // Комбинированные операции
   cout << "\nКомбинированные операции:" << endl;
   Distance2 result = dist1 + 1.0f - 0.5f;
   cout << "dist1 + 1.0 - 0.5 = " << result;

   return 0;
}