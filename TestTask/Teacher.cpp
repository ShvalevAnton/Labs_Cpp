#include "Teacher.h"

Teacher::Teacher(const std::string& first, const std::string& last,
   const std::string& phone, const std::string& email,
   const std::string& uni, const std::string& dept,
   const std::string& degree)
   : Person(first, last, phone, email), university(uni), department(dept), academicDegree(degree) {
}

void Teacher::displayInfo() const {
   std::cout << "Преподаватель: " << firstName << " " << lastName << "\n"
      << "Телефон: " << phone << "\n"
      << "Email: " << email << "\n"
      << "Университет: " << university << "\n"
      << "Кафедра: " << department << "\n"
      << "Ученая степень: " << academicDegree << "\n"
      << "------------------------\n";
}

std::string Teacher::getDetails() const {
   return "Университет: " + university + ", Кафедра: " + department + ", Степень: " + academicDegree;
}

std::unique_ptr<Person> Teacher::clone() const {
   return std::make_unique<Teacher>(*this);
}