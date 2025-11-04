#pragma once
#define USERINTERFACE_H

#include "AddressBook.h"
#include <memory>

// Facade pattern для упрощения взаимодействия
class UserInterface {
private:
   AddressBook* addressBook;

   void displayMenu() const;
   void addNewContact();
   void removeContact();
   void displayAllContacts() const;
   void findContact() const;
   void saveToFile() const;
   void loadFromFile();

   // Factory Method pattern для создания контактов
   std::unique_ptr<Person> createContact() const;

public:
   UserInterface();
   void run();
};

