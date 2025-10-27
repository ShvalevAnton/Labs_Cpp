#include <iostream>
#include <Windows.h>
#include "Distance2.h"

using namespace std;

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   Distance2 dist2;

   Distance2 dist1 = 2.35F;

   float mtrs;

   mtrs = static_cast<float>(dist1);
   
   mtrs = dist2;

   cout << "dist2 в метрах (неявное преобразование): " << mtrs << " м" << endl;

   // Дополнительная демонстрация
   cout << "\nДополнительная демонстрация:" << endl;
   cout << "Вывод через оператор << : " << dist1;

   // Проверка обратного преобразования
   Distance2 dist3(3, 6.5f); // 3 фута 6.5 дюймов
   cout << "dist3 (3 фута 6.5 дюймов): " << dist3;
   cout << "dist3 в метрах: " << static_cast<float>(dist3) << " м" << endl;

   return 0;
}