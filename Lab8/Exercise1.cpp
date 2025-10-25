#include <iostream>
#include <Windows.h>
#include "Student.h"

using namespace std;

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Создание объекта класса Student
   Student student01;
   
   string name;
   string last_name;
   int scores[5];

   // Ввод имени с клавиатуры
   cout << "Name: ";
   getline(cin, name);
   // Ввод фамилии
   cout << "Last name: ";
   getline(cin, last_name);

   // Сумма всех оценок
   int sum = 0;

   for (int i = 0; i < 5; ++i) {
      cout << "Score " << i + 1 << ": ";
      cin >> scores[i];
      // суммирование
      sum += scores[i];
   }

   // Сохранение имени и фамилии в объект класса Student
   student01.set_name(name);
   student01.set_last_name(last_name);
   // Сохранение промежуточных оценок в объект класса Student
   student01.set_scores(scores);

   double average_score = sum / 5.0;
   // Сохранение среднего балла в объект класса Student
   student01.set_average_score(average_score);

   cout << "Average ball for " << student01.get_name() << " "
      << student01.get_last_name() << " is "
      << student01.get_average_score() << endl;

   return 0;
}