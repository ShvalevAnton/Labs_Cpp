#include "Colleague.h"

Colleague::Colleague(const std::string& first, const std::string& last,
   const std::string& phone, const std::string& email,
   const std::string& comp, const std::string& pos,
   const std::string& dept)
   : Person(first, last, phone, email), company(comp), position(pos), department(dept) {
}

void Colleague::displayInfo() const {
   std::cout << "Коллега: " << firstName << " " << lastName << "\n"
      << "Телефон: " << phone << "\n"
      << "Email: " << email << "\n"
      << "Компания: " << company << "\n"
      << "Должность: " << position << "\n"
      << "Отдел: " << department << "\n"
      << "------------------------\n";
}

std::string Colleague::getDetails() const {
   return "Компания: " + company + ", Должность: " + position + ", Отдел: " + department;
}

std::unique_ptr<Person> Colleague::clone() const {
   return std::make_unique<Colleague>(*this);
}