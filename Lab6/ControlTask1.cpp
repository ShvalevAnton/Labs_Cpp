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
   cout << "Введите имя файла для записи (например, Стихотворение.txt): ";
   getline(cin, filename);

   ofstream file(filename);
   if (!file.is_open()) {
      cerr << "Ошибка: не удалось открыть файл для записи." << endl;
      return 1;
   }

   cout << "Введите стихотворение (для окончания ввода введите пустую строку):" << endl;
   string line;
   while (true) {
      getline(cin, line);
      if (line.empty()) {
         break;
      }
      file << line << '\n';
   }

   file.close();
   cout << "Стихотворение записано в файл: " << filename << endl;


   return 0;
}