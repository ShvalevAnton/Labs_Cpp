#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "IdCard.h"
using namespace std;

class StudentEx2
{
public:
   // ������ ������ � �������� � ����
   void save();
   // ���������� ������ Student
   ~StudentEx2();

   StudentEx2(); // ����������� ��� ����������   
   StudentEx2(string name, string last_name, int id, string cat); // ����������� ������ Student
 

   // ��������� ����� ��������
   void set_name(string student_name);

   // ��������� ����� ��������
   string get_name();

   // ��������� ������� ��������
   void set_last_name(string student_last_name);

   // ��������� ������� ��������
   string get_last_name();

   // ��������� ������������� ������
   void set_scores(int student_scores[]);

   // ��������� �������� �����
   void set_average_score(double ball);

   // ��������� �������� �����
   double get_average_score();

   void setIdCard(IdCard* c);

   void setIdCard(int id, string c);

   int getIdCard();

   void display();

private:
   int scores[5]; // ������������� ������
   double average_score; // ������� ����
   string name; // ���
   string last_name; // �������
   IdCard iCard;
};

#endif // STUDENT_H


