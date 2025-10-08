#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string filename;
   cout << "������� ��� ����� ��� ������ (��������, �������������.txt): ";
   getline(cin, filename);

   ofstream file(filename);
   if (!file.is_open()) {
      cerr << "������: �� ������� ������� ���� ��� ������." << endl;
      return 1;
   }

   cout << "������� ������������� (��� ��������� ����� ������� ������ ������):" << endl;
   string line;
   while (true) {
      getline(cin, line);
      if (line.empty()) {
         break;
      }
      file << line << '\n';
   }

   file.close();
   cout << "������������� �������� � ����: " << filename << endl;


   return 0;
}