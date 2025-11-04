#include "AddressBook.h"
#include "Student.h"
#include "Teacher.h"
#include "Colleague.h"
#include <iostream>
#include <sstream>

AddressBook* AddressBook::instance = nullptr;

AddressBook* AddressBook::getInstance() {
   if (!instance) {
      instance = new AddressBook();
   }
   return instance;
}

void AddressBook::addContact(std::unique_ptr<Person> person) {
   contacts.push_back(std::move(person));
}

void AddressBook::removeContact(int index) {
   if (index >= 0 && index < static_cast<int>(contacts.size())) {
      contacts.erase(contacts.begin() + index);
      std::cout << "Контакт успешно удален.\n";
   }
   else {
      std::cout << "Неверный индекс.\n";
   }
}

void AddressBook::displayAllContacts() const {
   if (contacts.empty()) {
      std::cout << "Адресная книга пуста.\n";
      return;
   }

   std::cout << "\n=== ВСЕ КОНТАКТЫ ===\n";
   int index = 1;
   for (const auto& contact : contacts) {
      std::cout << index++ << ". ";
      contact->displayInfo();
   }
}

std::vector<Person*> AddressBook::findContactsByName(const std::string& name) const {
   std::vector<Person*> results;

   for (const auto& contact : contacts) {
      if (contact->getFirstName().find(name) != std::string::npos ||
         contact->getLastName().find(name) != std::string::npos) {
         results.push_back(contact.get());
      }
   }

   return results;
}

Person* AddressBook::getContact(int index) const {
   if (index >= 0 && index < static_cast<int>(contacts.size())) {
      return contacts[index].get();
   }
   return nullptr;
}

void AddressBook::saveToFile(const std::string& filename) const {
   std::ofstream file(filename);
   if (!file) {
      std::cout << "Ошибка открытия файла для записи.\n";
      return;
   }

   for (const auto& contact : contacts) {
      file << contact->getType() << "\n"
         << contact->getFirstName() << "\n"
         << contact->getLastName() << "\n"
         << contact->getPhone() << "\n"
         << contact->getEmail() << "\n"
         << contact->getDetails() << "\n";
   }

   file.close();
   std::cout << "Контакты сохранены в файл: " << filename << "\n";
}

void AddressBook::loadFromFile(const std::string& filename) {
   std::ifstream file(filename);
   if (!file) {
      std::cout << "Ошибка открытия файла для чтения.\n";
      return;
   }

   contacts.clear();
   std::string type, first, last, phone, email, details;

   while (std::getline(file, type)) {
      std::getline(file, first);
      std::getline(file, last);
      std::getline(file, phone);
      std::getline(file, email);
      std::getline(file, details);

      if (type == "Student") {
         contacts.push_back(std::make_unique<Student>(first, last, phone, email, "Неизвестно", "Неизвестно", 1));
      }
      else if (type == "Teacher") {
         contacts.push_back(std::make_unique<Teacher>(first, last, phone, email, "Неизвестно", "Неизвестно", "Неизвестно"));
      }
      else if (type == "Colleague") {
         contacts.push_back(std::make_unique<Colleague>(first, last, phone, email, "Неизвестно", "Неизвестно", "Неизвестно"));
      }
   }

   file.close();
   std::cout << "Контакты загружены из файла: " << filename << "\n";
}