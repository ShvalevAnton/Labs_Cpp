#include <iostream>
#include <string>
#include <Windows.h>
#include "Group_ex2.h"
#include "student_ex2.h"

using namespace std;

Group_ex2::Group_ex2(string name)
{
   this->name = name;
}

Group_ex2::Group_ex2()
{
   name = "Не определена";
}

void Group_ex2::setName(string newName)
{
   name = newName;
}

string Group_ex2::getName()
{
   return name;
}

int Group_ex2::getSize()
{
   return (int)masSt.size();
}

void Group_ex2::addStudent(Student_ex2* newStudent)
{
   masSt.insert(newStudent);
}

void Group_ex2::delStudent(Student_ex2* oldStudent)
{
   masSt.erase(oldStudent);
}

void Group_ex2::GroupOut()
{
   iter = masSt.begin();
   while (iter != masSt.end())
      (*iter++)->display();
}

Student_ex2* Group_ex2::findStudent(string searchName, string searchLastName)
{
   Student_ex2* temp = new Student_ex2(searchName, searchLastName);
   iter = masSt.lower_bound(temp);
   delete temp;
   return (*iter);
}

void Group_ex2::GroupSort()
{
   // multiset автоматически сортирует элементы
}