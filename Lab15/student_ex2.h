#pragma once /* Защита от двойного подключения заголовочного файла */
#include "IdCard_ex2.h"
#include <string>

using namespace std;

class Student_ex2
{
public:
   // Конструктор класса Student
   Student_ex2(string, string, IdCard_ex2*);
   Student_ex2(string, string);
   Student_ex2();

   // Установка имени студента
   void set_name(string);
   // Получение имени студента
   string get_name();
   // Установка фамилии студента
   void set_last_name(string);
   // Получение фамилии студента
   string get_last_name();
   // Установка промежуточных оценок
   void set_scores(int[]);
   // Установка среднего балла
   void set_average_score(double);
   // Получение среднего балла
   double get_average_score();
   // Вывод информации о студенте
   void display() const;

   void setIdCard(IdCard_ex2* c);
   IdCard_ex2 getIdCard();

   friend bool operator< (const Student_ex2&, const Student_ex2&);
   friend bool operator> (const Student_ex2&, const Student_ex2&);
   friend bool operator== (const Student_ex2&, const Student_ex2&);
   friend bool operator!= (const Student_ex2&, const Student_ex2&);

private:
   // Промежуточные оценки
   int scores[5];
   // Средний балл
   double average_score;
   // Имя
   string name;
   // Фамилия
   string last_name;
   // Карточка
   IdCard_ex2* iCard;
};

// Функциональный объект для сравнения указателей на Student
class compareStudent
{
public:
   bool operator() (const Student_ex2* ptrSt1, const Student_ex2* ptrSt2) const
   {
      return *ptrSt1 < *ptrSt2;
   }
};