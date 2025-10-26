#include "StudentEx2.h"
#include <string>
#include <fstream>
#include "IdCard.h"
#include <iostream>


// Конструктор Student без параметров
StudentEx2::StudentEx2() {
   // Инициализация
   name = "";
   last_name = "";
   average_score = 0.0;
   for (int i = 0; i < 5; i++) {
      scores[i] = 0;
   }
}

StudentEx2::StudentEx2(string name, string last_name, int id, string cat)
{
   StudentEx2::set_name(name);
   StudentEx2::set_last_name(last_name);
   StudentEx2::setIdCard(id, cat);
}

// Деструктор Student
StudentEx2::~StudentEx2()
{
   StudentEx2::save();
}


// Запись данных о студенте в файл
void StudentEx2::save()
{
   ofstream fout("students.txt", ios::app);
   fout << StudentEx2::get_name() << " "
      << StudentEx2::get_last_name() << " ";
   for (int i = 0; i < 5; ++i) {
      fout << StudentEx2::scores[i] << " ";
   }
   fout << endl;
   fout.close();
}

// Установка имени студента
void StudentEx2::set_name(string student_name)
{
   name = student_name;
}

// Получение имени студента
string StudentEx2::get_name()
{
   return name;
}

// Установка фамилии студента
void StudentEx2::set_last_name(string student_last_name)
{
   last_name = student_last_name;
}

// Получение фамилии студента
string StudentEx2::get_last_name()
{
   return last_name;
}

// Установка промежуточных оценок
void StudentEx2::set_scores(int student_scores[])
{
   for (int i = 0; i < 5; ++i) {
      scores[i] = student_scores[i];
   }
}

// Установка среднего балла
void StudentEx2::set_average_score(double ball)
{
   average_score = ball;
}

// Получение среднего балла
double StudentEx2::get_average_score()
{
   return average_score;
}

void StudentEx2::setIdCard(int id, string c)
{
   iCard = IdCard(id, c);
}
int StudentEx2::getIdCard()
{
   return iCard.getNumber();
}
void StudentEx2::display() // вывод всех данных о студенте 
{ 
   cout << last_name << " " << name << "\t" << average_score << "\t" << iCard.getNumber()<< "\t" 
      << iCard.getCategory() << endl; 
}
