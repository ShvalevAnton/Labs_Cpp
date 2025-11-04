#pragma once
#define COLLEAGUE_H

#include "Person.h"
#include <string>

class Colleague : public Person {
private:
   std::string company;
   std::string position;
   std::string department;

public:
   Colleague(const std::string& first, const std::string& last,
      const std::string& phone, const std::string& email,
      const std::string& comp, const std::string& pos,
      const std::string& dept);

   void displayInfo() const override;
   std::string getType() const override { return "Colleague"; }
   std::string getDetails() const override;
   std::unique_ptr<Person> clone() const override;

   std::string getCompany() const { return company; }
   std::string getPosition() const { return position; }
   std::string getDepartment() const { return department; }
};


