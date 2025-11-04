#include "Student.h"

Student::Student(const std::string& first, const std::string& last,
   const std::string& phone, const std::string& email,
   const std::string& uni, const std::string& fac, int crs)
   : Person(first, last, phone, email), university(uni), faculty(fac), course(crs) {
}

void Student::displayInfo() const {
   std::cout << "Студент: " << firstName << " " << lastName << "\n"
      << "Телефон: " << phone << "\n"
      << "Email: " << email << "\n"
      << "Университет: " << university << "\n"
      << "Факультет: " << faculty << "\n"
      << "Курс: " << course << "\n"
      << "------------------------\n";
}

std::string Student::getDetails() const {
   return "Университет: " + university + ", Факультет: " + faculty + ", Курс: " + std::to_string(course);
}

std::unique_ptr<Person> Student::clone() const {
   return std::make_unique<Student>(*this);
}