#include <iostream>
#include <Windows.h>
#include "StudentEx2.h"

using namespace std;

int Exercise2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int card_number;
   string card_category;

   // Ввод номера карты с клавиатуры
   cout << "Card number: ";
   cin >> card_number;
   cin.ignore(); // Очистка буфера после ввода числа

   // Ввод категории карты
   cout << "Card category: ";
   getline(cin, card_category);  

   string name;
   string last_name;
   // Ввод имени с клавиатуры
   cout << "Name: ";
   getline(std::cin, name);
   // Ввод фамилии
   cout << "Last name: ";
   getline(std::cin, last_name);

   // Выделение памяти для объекта Student
   StudentEx2* student02 = new StudentEx2(name, last_name, card_number, card_category);

   // Оценки
   int scores[5];
   // Сумма всех оценок
   int sum = 0;
   // Ввод промежуточных оценок
   for (int i = 0; i < 5; ++i) {
      cout << "Score " << i + 1 << ": ";
      cin >> scores[i];
      // суммирование
      sum += scores[i];
   }

   // Сохранение имени и фамилии в объект класса Students
   student02->set_name(name);
   student02->set_last_name(last_name);
   // Сохраняем промежуточные оценки в объект класса Student
   student02->set_scores(scores);
   // Считаем средний балл
   float average_score = sum / 5.0;
   // Сохраняем средний балл в объект класса Student
   student02->set_average_score(average_score);
   // Выводим данные по студенту
   student02->display();

   delete student02;

   return 0;
}