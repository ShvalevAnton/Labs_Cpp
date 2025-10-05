#include <iostream>
#include <Windows.h>
#include <climits> // для INT_MAX и INT_MIN
using namespace std;

int Exercise1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   const int n = 10;
   int mas[n];

   for (int i = 0; i < n; i++)
   {
      cout << "mas[" << i << "] = ";
      cin >> mas[i];
   }

   // Общая сумма
   int s = 0;
   for (int i = 0; i < n; i++)
   {
      s += mas[i];
   }
   double avg = static_cast<double>(s) / n;

   // Сумма отрицательных элементов
   int sumNegative = 0;
   // Сумма положительных элементов
   int sumPositive = 0;
   // Сумма элементов с нечётными индексами
   int sumOddIndex = 0;
   // Сумма элементов с чётными индексами
   int sumEvenIndex = 0;

   for (int i = 0; i < n; i++)
   {
      if (mas[i] < 0)
         sumNegative += mas[i];
      else if (mas[i] > 0)
         sumPositive += mas[i];

      if (i % 2 == 0)
         sumEvenIndex += mas[i];
      else
         sumOddIndex += mas[i];
   }

   // Дополнительные задания:
   // Найти максимальный и минимальный элементы и их индексы
   int maxVal = mas[0], minVal = mas[0];
   int maxIndex = 0, minIndex = 0;

   for (int i = 1; i < n; i++)
   {
      if (mas[i] > maxVal)
      {
         maxVal = mas[i];
         maxIndex = i;
      }
      if (mas[i] < minVal)
      {
         minVal = mas[i];
         minIndex = i;
      }
   }

   // Произведение элементов между максимальным и минимальным
   long long productBetween = 1;
   bool hasElementsBetween = false;

   int start = (minIndex < maxIndex) ? minIndex + 1 : maxIndex + 1;
   int end = (minIndex < maxIndex) ? maxIndex : minIndex;

   if (start < end)
   {
      hasElementsBetween = true;
      for (int i = start; i < end; i++)
      {
         productBetween *= mas[i];
      }
   }
   else
   {
      productBetween = 0; // Нет элементов между
   }

   // Вывод результатов
   cout << "\n=== Результаты обработки массива ===" << endl;
   cout << "Сумма всех элементов массива: " << s << endl;
   cout << "Среднее значение элементов массива: " << avg << endl;
   cout << "Сумма отрицательных элементов: " << sumNegative << endl;
   cout << "Сумма положительных элементов: " << sumPositive << endl;
   cout << "Сумма элементов с чётными индексами: " << sumEvenIndex << endl;
   cout << "Сумма элементов с нечётными индексами: " << sumOddIndex << endl;
   cout << "Максимальный элемент: " << maxVal << " (индекс: " << maxIndex << ")" << endl;
   cout << "Минимальный элемент: " << minVal << " (индекс: " << minIndex << ")" << endl;

   if (hasElementsBetween)
      cout << "Произведение элементов между минимальным и максимальным: " << productBetween << endl;
   else
      cout << "Между минимальным и максимальным элементами нет других элементов." << endl;

   return 0;
}