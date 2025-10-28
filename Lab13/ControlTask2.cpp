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
   // ����������� ������ human
   human(std::string last_name, std::string name, std::string second_name)
   {
      this->last_name = last_name;
      this->name = name;
      this->second_name = second_name;
   }

   // ����������� ���������� ��� ����������� �������� ��������
   virtual ~human() = default;

   // ��������� ��� ��������
   virtual std::string get_full_name()
   {
      std::ostringstream full_name;
      full_name << this->last_name << " "
         << this->name << " "
         << this->second_name;
      return full_name.str();
   }

   // ����������� ����� ��� ��������� ���������� (�����������)
   virtual std::string get_info() = 0;

   // ����������� ����� ��� ����
   virtual std::string get_role() = 0;

private:
   std::string name;        // ���
   std::string last_name;   // �������
   std::string second_name; // ��������
};

class student : public human {
public:
   student(std::string last_name, std::string name, std::string second_name,
      std::vector<int> scores) : human(last_name, name, second_name) {
      this->scores = scores;
   }

   // ��������� �������� ����� ��������
   float get_average_score() {
      unsigned int count_scores = this->scores.size();
      unsigned int sum_scores = 0;

      for (unsigned int i = 0; i < count_scores; ++i) {
         sum_scores += this->scores[i];
      }

      return (float)sum_scores / (float)count_scores;
   }

   // ��������������� ������������ ������ get_info()
   std::string get_info() override {
      return "�������: " + get_full_name() +
         ", ������� ����: " + std::to_string(get_average_score());
   }

   // ��������������� ������������ ������ get_role()
   std::string get_role() override {
      return "�������";
   }

private:
   std::vector<int> scores; // ������ ��������
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

   // ��������� ���������� ������� �����
   unsigned int get_work_time() {
      return this->work_time;
   }

   // ��������������� ������������ ������ get_info()
   std::string get_info() override {
      return "�������������: " + get_full_name() +
         ", ������� �����: " + std::to_string(work_time);
   }

   // ��������������� ������������ ������ get_role()
   std::string get_role() override {
      return "�������������";
   }

private:
   unsigned int work_time; // ������� ����
};



using namespace std;

int ControlTask2()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   // ������ ��������
   std::vector<int> scores = { 5, 3, 4, 4, 5, 3, 3, 3, 3 };

   // �������� �������� ����� ��������� �� ������� �����
   human* people[3];

   people[0] = new student("������", "����", "����������", scores);
   people[1] = new teacher("�������", "�������", "���������", 40);
   people[2] = new student("�������", "�����", "��������", { 5, 5, 4, 5, 4 });

   // ������������ ������������
   cout << "=== ������������ ������������ ===" << endl;

   for (int i = 0; i < 3; i++) {
      cout << "---" << endl;
      // ����������� ����� �������
      cout << "����: " << people[i]->get_role() << endl;
      cout << "����������: " << people[i]->get_info() << endl;
      cout << "���: " << people[i]->get_full_name() << endl;
   }

   // �������������� ������ � �������������� ����� ����������
   cout << "\n=== ������������� ����� ���������� ===" << endl;

   std::vector<std::unique_ptr<human>> people_list;
   people_list.push_back(std::make_unique<student>("�������", "�������", "����������",
      std::vector<int>{4, 4, 5, 4, 3}));
   people_list.push_back(std::make_unique<teacher>("���������", "�����", "��������", 35));
   people_list.push_back(std::make_unique<student>("������", "������", "����������",
      std::vector<int>{5, 5, 5, 4, 5}));

   for (auto& person : people_list) {
      cout << "---" << endl;
      cout << person->get_info() << endl;
   }

   // ������� ������
   for (int i = 0; i < 3; i++) {
      delete people[i];
   }

   return 0;
}