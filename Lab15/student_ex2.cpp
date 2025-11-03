#include <iostream>
#include <string>
#include "student_ex2.h"
#include "Group_ex2.h"
using namespace std;

// Конструктор Student
Student_ex2::Student_ex2(string name, string last_name, IdCard_ex2*id)
{
   Student_ex2::set_name(name);
   Student_ex2::set_last_name(last_name);
	Student_ex2::setIdCard(id);
	Student_ex2::set_average_score(0);
}

// Конструктор Student с 2 параметрами
Student_ex2::Student_ex2(string name, string last_name)
{
   Student_ex2::set_name(name);
   Student_ex2::set_last_name(last_name);
   Student_ex2::setIdCard(nullptr);
   Student_ex2::set_average_score(0);

   // Инициализация массива scores
   for (int i = 0; i < 5; ++i) {
      scores[i] = 0;
   }
}

Student_ex2::Student_ex2(){}
// Установка имени студента
void Student_ex2::set_name(std::string student_name)
{
    Student_ex2::name = student_name;
}

// Получение имени студента
std::string Student_ex2::get_name()
{
    return Student_ex2::name;
}

// Установка фамилии студента
void Student_ex2::set_last_name(std::string student_last_name)
{
    Student_ex2::last_name = student_last_name;
}

// Получение фамилии студента
std::string Student_ex2::get_last_name()
{
    return Student_ex2::last_name;
}

// Установка промежуточных оценок
void Student_ex2::set_scores(int scores[])
{
    for (int i = 0; i < 5; ++i) {
        Student_ex2::scores[i] = scores[i];
    }
}

// Установка среднего балла
void Student_ex2::set_average_score(double ball)
{
    Student_ex2::average_score = ball;
}

// Получение среднего балла
double Student_ex2::get_average_score()
{
    return Student_ex2::average_score;
}

 void Student_ex2::setIdCard(IdCard_ex2 *c)
 {
        iCard = c;
 }

 IdCard_ex2 Student_ex2::getIdCard()
 {
        return *iCard;
 }

 void Student_ex2::display() const // вывод всех данных о студенте
 {
	 cout << last_name << " " << name << "\t" << average_score << "\t" << iCard->getNumber()<< "\t" << iCard->getCategory() << endl;
}

 bool operator== (const Student_ex2& p1, const Student_ex2& p2)
 {
    return (p1.name == p2.name && p1.last_name == p2.last_name) ? true : false;
 }
 bool operator< (const Student_ex2& p1, const Student_ex2& p2)
 {
    if (p1.last_name == p2.last_name)
       return (p1.name < p2.name) ? true : false;
    return (p1.last_name < p2.last_name) ? true : false;
 }
 bool operator!= (Student_ex2& p1, Student_ex2& p2)
 {
    return !(p1 == p2);
 }
 bool operator> (Student_ex2& p1, Student_ex2& p2)
 {
    return !(p1 < p2) && !(p2 == p2);
 }