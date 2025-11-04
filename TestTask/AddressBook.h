#pragma once
#define ADDRESSBOOK_H

#include "Person.h"
#include <vector>
#include <memory>
#include <string>
#include <fstream>

// Singleton pattern для AddressBook
class AddressBook {
private:
   static AddressBook* instance;
   std::vector<std::unique_ptr<Person>> contacts;

   // Приватный конструктор для Singleton
   AddressBook() = default;

public:
   // Удаляем копирование и присваивание
   AddressBook(const AddressBook&) = delete;
   AddressBook& operator=(const AddressBook&) = delete;

   // Метод для получения единственного экземпляра
   static AddressBook* getInstance();

   // CRUD операции
   void addContact(std::unique_ptr<Person> person);
   void removeContact(int index);
   void displayAllContacts() const;
   std::vector<Person*> findContactsByName(const std::string& name) const;

   // Работа с файлами
   void saveToFile(const std::string& filename) const;
   void loadFromFile(const std::string& filename);

   // Получение контактов
   size_t getContactCount() const { return contacts.size(); }
   Person* getContact(int index) const;

   // Iterator pattern (упрощенный)
   class Iterator {
   private:
      const AddressBook* book;
      size_t current;

   public:
      Iterator(const AddressBook* b, size_t pos) : book(b), current(pos) {}
      Person* operator*() const { return book->getContact(current); }
      Iterator& operator++() { ++current; return *this; }
      bool operator!=(const Iterator& other) const {
         return current != other.current;
      }
   };

   Iterator begin() const { return Iterator(this, 0); }
   Iterator end() const { return Iterator(this, contacts.size()); }
};


