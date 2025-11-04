#pragma once
#define TEACHER_H

#include "Person.h"
#include <string>
#include <vector>

class Teacher : public Person {
private:
   std::string university;
   std::string department;
   std::string academicDegree;

public:
   Teacher(const std::string& first, const std::string& last,
      const std::string& phone, const std::string& email,
      const std::string& uni, const std::string& dept,
      const std::string& degree);

   void displayInfo() const override;
   std::string getType() const override { return "Teacher"; }
   std::string getDetails() const override;
   std::unique_ptr<Person> clone() const override;

   std::string getUniversity() const { return university; }
   std::string getDepartment() const { return department; }
   std::string getAcademicDegree() const { return academicDegree; }
};


