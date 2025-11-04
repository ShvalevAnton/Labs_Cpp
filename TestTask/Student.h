#pragma once
#define STUDENT_H

#include "Person.h"
#include <string>

class Student : public Person {
private:
   std::string university;
   std::string faculty;
   int course;

public:
   Student(const std::string& first, const std::string& last,
      const std::string& phone, const std::string& email,
      const std::string& uni, const std::string& fac, int crs);

   void displayInfo() const override;
   std::string getType() const override { return "Student"; }
   std::string getDetails() const override;
   std::unique_ptr<Person> clone() const override;

   std::string getUniversity() const { return university; }
   std::string getFaculty() const { return faculty; }
   int getCourse() const { return course; }
};


