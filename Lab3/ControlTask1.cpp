#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>  // для isdigit
using namespace std;

// Функция проверки валидности СНИЛС
bool isValidSNILS(const string& input) {
   string cleaned;
   // Очистка строки: оставляем только цифры, пробелы и дефисы игнорируем
   for (char c : input) {
      if (isdigit(c)) {
         cleaned += c;
      }
      else if (c != ' ' && c != '-') {
         // Недопустимый символ
         return false;
      }
   }

   // Должно быть ровно 11 цифр
   if (cleaned.length() != 11) {
      return false;
   }

   // Преобразуем первые 9 цифр в числа и считаем контрольную сумму
   int sum = 0;
   for (int i = 0; i < 9; ++i) {
      sum += (cleaned[i] - '0') * (9 - i);
   }

   // Вычисляем контрольное число
   int control;
   if (sum < 100) {
      control = sum;
   }
   else if (sum == 100 || sum == 101) {
      control = 0;
   }
   else {
      control = sum % 101;
      if (control == 100) {
         control = 0;
      }
   }

   // Получаем последние две цифры как число
   int givenControl = (cleaned[9] - '0') * 10 + (cleaned[10] - '0');

   return control == givenControl;
}

int ControlTask1() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string snils;
   cout << "Введите СНИЛС: ";
   getline(cin, snils); // используем getline, чтобы захватить пробелы

   if (isValidSNILS(snils)) {
      cout << "СНИЛС валидный." << endl;
   }
   else {
      cout << "СНИЛС НЕ валидный." << endl;
   }

   return 0;
}