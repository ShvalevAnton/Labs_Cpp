#include <iostream>
#include <Windows.h>
#include <map>
#include <string>

using namespace std;

#include <string>

   // Структура для хранения информации о студенте и его оценке
   struct StudentGrade {
      std::string studentName;
      char grade;

      // Конструктор по умолчанию (обязателен для использования в map)
      StudentGrade() : studentName(""), grade(' ') {}

      // Конструктор с параметрами
      StudentGrade(const std::string& name, char g) : studentName(name), grade(g) {}
   };

   int ControlTask1()
   {
      SetConsoleOutputCP(1251);
      SetConsoleCP(1251);

      // Контейнер map с ключом string и значением StudentGrade
      std::map<std::string, StudentGrade> studentsMap;

      int choice;

      do {
         std::cout << "\n=== Система учета оценок студентов ===" << std::endl;
         std::cout << "1. Добавить/изменить оценку студента" << std::endl;
         std::cout << "2. Показать все оценки" << std::endl;
         std::cout << "3. Найти оценку студента" << std::endl;
         std::cout << "4. Удалить студента" << std::endl;
         std::cout << "0. Выход" << std::endl;
         std::cout << "Выберите действие: ";
         std::cin >> choice;

         switch (choice) {
         case 1: {
            std::string name;
            char grade;

            std::cout << "Введите имя студента: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "Введите оценку (A, B, C, D, F): ";
            std::cin >> grade;

            // Используем emplace для эффективного добавления
            auto result = studentsMap.emplace(name, StudentGrade(name, grade));
            if (!result.second) {
               // Если студент уже существует, обновляем оценку
               result.first->second.grade = grade;
               std::cout << "Оценка студента " << name << " изменена на " << grade << std::endl;
            }
            else {
               std::cout << "Добавлен новый студент: " << name << " с оценкой " << grade << std::endl;
            }
            break;
         }

         case 2: {
            if (studentsMap.empty()) {
               std::cout << "Список студентов пуст." << std::endl;
            }
            else {
               std::cout << "\n=== Список всех студентов и их оценок ===" << std::endl;
               for (const auto& pair : studentsMap) {
                  std::cout << "Студент: " << pair.second.studentName
                     << ", Оценка: " << pair.second.grade << std::endl;
               }
            }
            break;
         }

         case 3: {
            std::string name;
            std::cout << "Введите имя студента для поиска: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            auto it = studentsMap.find(name);
            if (it != studentsMap.end()) {
               std::cout << "Студент: " << it->second.studentName
                  << ", Оценка: " << it->second.grade << std::endl;
            }
            else {
               std::cout << "Студент с именем '" << name << "' не найден." << std::endl;
            }
            break;
         }

         case 4: {
            std::string name;
            std::cout << "Введите имя студента для удаления: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            auto it = studentsMap.find(name);
            if (it != studentsMap.end()) {
               studentsMap.erase(it);
               std::cout << "Студент " << name << " удален из системы." << std::endl;
            }
            else {
               std::cout << "Студент с именем '" << name << "' не найден." << std::endl;
            }
            break;
         }

         case 0:
            std::cout << "Выход из программы." << std::endl;
            break;

         default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
         }

      } while (choice != 0);

      return 0;
   }
