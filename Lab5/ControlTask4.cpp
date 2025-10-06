#include <iostream>
#include <Windows.h>
using namespace std;

// Функция для проверки корректности флага
bool isValidFlag(const char* flag) {
   return (strncmp(flag, "-a", 2) == 0) || (strncmp(flag, "-m", 2) == 0);
}

// Функция для выполнения операции
int performOperation(const char* flag, int a, int b) {
   if (strncmp(flag, "-a", 2) == 0) {
      return a + b;
   }
   else { // "-m"
      return a * b;
   }
}

int ControlTask4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string flagStr;
   int num1, num2;

   cout << "Введите флаг (-a или -m) и два целых числа: ";
   cin >> flagStr >> num1 >> num2;

   // Проверка флага
   if (!isValidFlag(flagStr.c_str())) {
      cerr << "Ошибка: Неверный флаг. Используйте -a (сложение) или -m (умножение).\n";
      return 0;
   }

   int result = performOperation(flagStr.c_str(), num1, num2);
   cout << result << endl;

   return 0;
}

