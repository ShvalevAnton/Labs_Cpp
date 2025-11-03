#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
#include "student_ex2.h"
#include <list>
#include <algorithm>
#include <set>  // Добавлено для работы с multiset

using namespace std;

class Group_ex2
{
private:
   string name;
   multiset<Student_ex2*, compareStudent> masSt;  // Заменен list на multiset
   multiset<Student_ex2*, compareStudent>::iterator iter;  // Соответствующий итератор

public:
   Group_ex2(string name);
   Group_ex2();

   int getSize();
   void addStudent(Student_ex2* newStudent);  // Изменен параметр на указатель
   void delStudent(Student_ex2* oldStudent);  // Изменен параметр на указатель
   Student_ex2* findStudent(string, string);  // Изменен возвращаемый тип на указатель
   void GroupSort();
   void GroupOut();

   void setName(string newName);
   string getName();
};