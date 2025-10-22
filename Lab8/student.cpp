/* student.cpp */
#include <string>
#include "student.h"

class Student
{
   // Конструктор без параметров
   //Student();
   // Конструктор Student с параметрами
   Student(string name, string last_name)
   {
      Student::set_name(name);
      Student::set_last_name(last_name);
   }
   private:
      int scores[5]; // Промежуточные оценки
      double average_score; // Средний балл
      string name; // Имя
      string last_name; // Фамилия
   public:
      // Установка имени студента
      void set_name(string student_name)
      {
         name = student_name;
      }
      // Получение имени студента
      string get_name()
      {
         return name;
      }
      // Установка фамилии студента
      void set_last_name(string student_last_name)
      {
         last_name = student_last_name;
      }
      // Получение фамилии студента
      string get_last_name()
      {
         return last_name;
      }
      // Установка промежуточных оценок
      void set_scores(int student_scores[])
      {
         for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
         }
      }
      // Установка среднего балла
      void set_average_score(double ball)
      {
         average_score = ball;
      }
      // Получение среднего балла
      double get_average_score()
      {
         return average_score;
      }
};
