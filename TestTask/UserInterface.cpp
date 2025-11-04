#include "UserInterface.h"
#include "Student.h"
#include "Teacher.h"
#include "Colleague.h"
#include <iostream>
#include <limits>

UserInterface::UserInterface() {
   addressBook = AddressBook::getInstance();
}

void UserInterface::run() {
   int choice;

   do {
      displayMenu();
      std::cin >> choice;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      switch (choice) {
      case 1:
         addNewContact();
         break;
      case 2:
         removeContact();
         break;
      case 3:
         displayAllContacts();
         break;
      case 4:
         findContact();
         break;
      case 5:
         saveToFile();
         break;
      case 6:
         loadFromFile();
         break;
      case 0:
         std::cout << "До свидания!\n";
         break;
      default:
         std::cout << "Неверный выбор. Попробуйте снова.\n";
      }
   } while (choice != 0);
}

void UserInterface::displayMenu() const {
   std::cout << "\n=== АДРЕСНАЯ КНИГА ===\n"
      << "1. Добавить новый контакт\n"
      << "2. Удалить контакт\n"
      << "3. Показать все контакты\n"
      << "4. Найти контакт по имени\n"
      << "5. Сохранить в файл\n"
      << "6. Загрузить из файла\n"
      << "0. Выход\n"
      << "Введите ваш выбор: ";
}

void UserInterface::addNewContact() {
   auto newContact = createContact();
   if (newContact) {
      addressBook->addContact(std::move(newContact));
      std::cout << "Контакт успешно добавлен.\n";
   }
}

void UserInterface::removeContact() {
   addressBook->displayAllContacts();
   if (addressBook->getContactCount() > 0) {
      std::cout << "Введите номер контакта для удаления: ";
      int index;
      std::cin >> index;
      addressBook->removeContact(index - 1);
   }
}

void UserInterface::displayAllContacts() const {
   addressBook->displayAllContacts();
}

void UserInterface::findContact() const {
   std::string name;
   std::cout << "Введите имя для поиска: ";
   std::getline(std::cin, name);

   auto results = addressBook->findContactsByName(name);
   if (results.empty()) {
      std::cout << "Контакты не найдены.\n";
   }
   else {
      std::cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ===\n";
      for (const auto& contact : results) {
         contact->displayInfo();
      }
   }
}

void UserInterface::saveToFile() const {
   std::string filename;
   std::cout << "Введите имя файла: ";
   std::getline(std::cin, filename);
   addressBook->saveToFile(filename);
}

void UserInterface::loadFromFile() {
   std::string filename;
   std::cout << "Введите имя файла: ";
   std::getline(std::cin, filename);
   addressBook->loadFromFile(filename);
}

std::unique_ptr<Person> UserInterface::createContact() const {
   std::string first, last, phone, email;

   std::cout << "Введите имя: ";
   std::getline(std::cin, first);
   std::cout << "Введите фамилию: ";
   std::getline(std::cin, last);
   std::cout << "Введите телефон: ";
   std::getline(std::cin, phone);
   std::cout << "Введите email: ";
   std::getline(std::cin, email);

   std::cout << "Выберите тип контакта:\n"
      << "1. Студент\n"
      << "2. Преподаватель\n"
      << "3. Коллега\n"
      << "Введите выбор: ";

   int type;
   std::cin >> type;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   switch (type) {
   case 1: {
      std::string uni, fac;
      int course;
      std::cout << "Введите университет: ";
      std::getline(std::cin, uni);
      std::cout << "Введите факультет: ";
      std::getline(std::cin, fac);
      std::cout << "Введите курс: ";
      std::cin >> course;
      return std::make_unique<Student>(first, last, phone, email, uni, fac, course);
   }
   case 2: {
      std::string uni, dept, degree;
      std::cout << "Введите университет: ";
      std::getline(std::cin, uni);
      std::cout << "Введите кафедру: ";
      std::getline(std::cin, dept);
      std::cout << "Введите ученую степень: ";
      std::getline(std::cin, degree);
      return std::make_unique<Teacher>(first, last, phone, email, uni, dept, degree);
   }
   case 3: {
      std::string comp, pos, dept;
      std::cout << "Введите компанию: ";
      std::getline(std::cin, comp);
      std::cout << "Введите должность: ";
      std::getline(std::cin, pos);
      std::cout << "Введите отдел: ";
      std::getline(std::cin, dept);
      return std::make_unique<Colleague>(first, last, phone, email, comp, pos, dept);
   }
   default:
      std::cout << "Неверный тип.\n";
      return nullptr;
   }
}