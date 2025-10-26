#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "IdCard.h"
using namespace std;

class StudentEx2
{
public:
   // Запись данных о студенте в файл
   void save();
   // Деструктор класса Student
   ~StudentEx2();

   StudentEx2(); // Конструктор без параметров   
   StudentEx2(string name, string last_name, int id, string cat); // Конструктор класса Student
 

   // Установка имени студента
   void set_name(string student_name);

   // Получение имени студента
   string get_name();

   // Установка фамилии студента
   void set_last_name(string student_last_name);

   // Получение фамилии студента
   string get_last_name();

   // Установка промежуточных оценок
   void set_scores(int student_scores[]);

   // Установка среднего балла
   void set_average_score(double ball);

   // Получение среднего балла
   double get_average_score();

   void setIdCard(IdCard* c);

   void setIdCard(int id, string c);

   int getIdCard();

   void display();

private:
   int scores[5]; // Промежуточные оценки
   double average_score; // Средний балл
   string name; // Имя
   string last_name; // Фамилия
   IdCard iCard;
};

#endif // STUDENT_H


