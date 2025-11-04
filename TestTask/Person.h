#pragma once
#define PERSON_H

#include <string>
#include <memory>
#include <iostream>

// Абстрактный класс Person
class Person {
protected:
   std::string firstName;
   std::string lastName;
   std::string phone;
   std::string email;

public:
   Person(const std::string& first, const std::string& last,
      const std::string& phone, const std::string& email);
   virtual ~Person() = default;

   // Общие методы
   virtual void displayInfo() const = 0;
   virtual std::string getType() const = 0;
   virtual std::string getDetails() const = 0;

   // Геттеры
   std::string getFirstName() const { return firstName; }
   std::string getLastName() const { return lastName; }
   std::string getPhone() const { return phone; }
   std::string getEmail() const { return email; }

   // Сеттеры
   void setPhone(const std::string& newPhone) { phone = newPhone; }
   void setEmail(const std::string& newEmail) { email = newEmail; }

   // Виртуальный метод для клонирования (Prototype pattern)
   virtual std::unique_ptr<Person> clone() const = 0;
};


