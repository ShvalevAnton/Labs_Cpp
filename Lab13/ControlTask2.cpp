// human.h
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <memory>
#pragma once

class human {
public:
   // Конструктор класса human
   human(std::string last_name, std::string name, std::string second_name)
   {
      this->last_name = last_name;
      this->name = name;
      this->second_name = second_name;
   }

   // Виртуальный деструктор для корректного удаления объектов
   virtual ~human() = default;

   // Получение ФИО человека
   virtual std::string get_full_name()
   {
      std::ostringstream full_name;
      full_name << this->last_name << " "
         << this->name << " "
         << this->second_name;
      return full_name.str();
   }

   // Виртуальный метод для получения информации (полиморфизм)
   virtual std::string get_info() = 0;

   // Виртуальный метод для роли
   virtual std::string get_role() = 0;

private:
   std::string name;        // имя
   std::string last_name;   // фамилия
   std::string second_name; // отчество
};

class student : public human {
public:
   student(std::string last_name, std::string name, std::string second_name,
      std::vector<int> scores) : human(last_name, name, second_name) {
      this->scores = scores;
   }

   // Получение среднего балла студента
   float get_average_score() {
      unsigned int count_scores = this->scores.size();
      unsigned int sum_scores = 0;

      for (unsigned int i = 0; i < count_scores; ++i) {
         sum_scores += this->scores[i];
      }

      return (float)sum_scores / (float)count_scores;
   }

   // Переопределение виртуального метода get_info()
   std::string get_info() override {
      return "Студент: " + get_full_name() +
         ", средний балл: " + std::to_string(get_average_score());
   }

   // Переопределение виртуального метода get_role()
   std::string get_role() override {
      return "Студент";
   }

private:
   std::vector<int> scores; // Оценки студента
};

class teacher : public human {
public:
   teacher(
      std::string last_name,
      std::string name,
      std::string second_name,
      unsigned int work_time
   ) : human(last_name, name, second_name) {
      this->work_time = work_time;
   }

   // Получение количества учебных часов
   unsigned int get_work_time() {
      return this->work_time;
   }

   // Переопределение виртуального метода get_info()
   std::string get_info() override {
      return "Преподаватель: " + get_full_name() +
         ", учебных часов: " + std::to_string(work_time);
   }

   // Переопределение виртуального метода get_role()
   std::string get_role() override {
      return "Преподаватель";
   }

private:
   unsigned int work_time; // Учебные часы
};



using namespace std;

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // Оценки студента
   std::vector<int> scores = { 5, 3, 4, 4, 5, 3, 3, 3, 3 };

   // Создание объектов через указатели на базовый класс
   human* people[3];

   people[0] = new student("Петров", "Иван", "Алексеевич", scores);
   people[1] = new teacher("Сергеев", "Дмитрий", "Сергеевич", 40);
   people[2] = new student("Иванова", "Мария", "Петровна", { 5, 5, 4, 5, 4 });

   // Демонстрация полиморфизма
   cout << "=== Демонстрация полиморфизма ===" << endl;

   for (int i = 0; i < 3; i++) {
      cout << "---" << endl;
      // Полиморфный вызов методов
      cout << "Роль: " << people[i]->get_role() << endl;
      cout << "Информация: " << people[i]->get_info() << endl;
      cout << "ФИО: " << people[i]->get_full_name() << endl;
   }

   // Альтернативный способ с использованием умных указателей
   cout << "\n=== Использование умных указателей ===" << endl;

   std::vector<std::unique_ptr<human>> people_list;
   people_list.push_back(std::make_unique<student>("Сидоров", "Алексей", "Викторович",
      std::vector<int>{4, 4, 5, 4, 3}));
   people_list.push_back(std::make_unique<teacher>("Кузнецова", "Ольга", "Ивановна", 35));
   people_list.push_back(std::make_unique<student>("Фролов", "Сергей", "Дмитриевич",
      std::vector<int>{5, 5, 5, 4, 5}));

   for (auto& person : people_list) {
      cout << "---" << endl;
      cout << person->get_info() << endl;
   }

   // Очистка памяти
   for (int i = 0; i < 3; i++) {
      delete people[i];
   }

   return 0;
}