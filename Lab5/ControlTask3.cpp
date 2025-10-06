#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

// ‘ункци€ поиска с транспозицией
int transpositionSearch(vector<int>& arr, int key) {
   for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] == key) {
         // ≈сли элемент не первый Ч мен€ем с предыдущим
         if (i > 0) {
            swap(arr[i], arr[i - 1]);
            return i - 1; // возвращаем новый индекс
         }
         return i; // если уже на первом месте
      }
   }
   return -1; // элемент не найден
}

int ControlTask3()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   vector<int> data = { 10, 20, 30, 40, 50 };

   cout << "»сходный массив: ";
   for (int x : data) cout << x << " ";
   cout << "\n";

   int key = 30;
   int index = transpositionSearch(data, key);

   if (index != -1) {
      cout << "Ёлемент " << key << " найден на позиции " << index << "\n";
   }
   else {
      cout << "Ёлемент " << key << " не найден\n";
   }

   cout << "ћассив после поиска: ";
   for (int x : data) cout << x << " ";
   cout << "\n";

   return 0;
}

