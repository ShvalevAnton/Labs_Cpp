#include <iostream>
#include <Windows.h>
using namespace std;

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string snils;
   cout << "Введите СНИЛС: "; cin >> snils;

   bool isValid = true;

   // Проверяем длину строки: 11 символов (9 цифр + 2 контрольных)
   if (snils.length() != 11) {
      isValid = false;
   }
   else {
      // Проверяем, что все символы - цифры
      for (int i = 0; i < 11; i++) {
         if (snils[i] < '0' || snils[i] > '9') {
            isValid = false;
            break;
         }
      }

      if (isValid) {
         // Проверяем, что в основной части (первые 9 цифр) нет более двух одинаковых цифр подряд
         for (int i = 0; i < 7; i++) {
            if (snils[i] == snils[i + 1] && snils[i] == snils[i + 2]) {
               isValid = false;
               break;
            }
         }

         if (isValid) {
            // Вычисляем контрольное число
            int sum = 0;
            for (int i = 0; i < 9; i++) {
               int digit = snils[8 - i] - '0';  // цифра
               sum += digit * (i + 1);          // умножаем на позицию с конца (1..9)
            }

            int controlNumber = 0;
            if (sum < 100) {
               controlNumber = sum;
            }
            else if (sum == 100 || sum == 101) {
               controlNumber = 0;
            }
            else {
               controlNumber = sum % 101;
               if (controlNumber == 100) {
                  controlNumber = 0;
               }
            }

            // Извлекаем контрольное число из строки (последние 2 цифры)
            int inputControl = (snils[9] - '0') * 10 + (snils[10] - '0');

            if (inputControl != controlNumber) {
               isValid = false;
            }
         }
      }
   }

   if (isValid) {
      cout << "True" << endl;
   }
   else {
      cout << "False" << endl;
   }

  
   return 0;
}

