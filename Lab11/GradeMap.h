#pragma once
#include <vector>
#include <string>

struct StudentGrade
{
   std::string name;
   char grade;
};

class GradeMap
{
private:
   std::vector<StudentGrade> m_map;
public:
   GradeMap() {}
   char& operator[](const std::string& name);
};