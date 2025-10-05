#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// Ввод массива
void inputArray(int mas[], int n) {
   for (int i = 0; i < n; i++) {
      cout << "mas[" << i << "] = ";
      cin >> mas[i];
   }
}

// Сортировка
void selectionSort(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      int minIndex = i;
      for (int j = i + 1; j < n; j++) {
         if (arr[j] < arr[minIndex]) {
            minIndex = j;
         }
      }
      if (i != minIndex) {
         int temp = arr[i];
         arr[i] = arr[minIndex];
         arr[minIndex] = temp;
      }
   }
}

// Вычисление среднего значения
double calculateAverage(const int mas[], int n) {
   int sum = 0;
   for (int i = 0; i < n; i++) {
      sum += mas[i];
   }
   return static_cast<double>(sum) / n;
}

// Подсчёт различных сумм
void calculateSums(const int mas[], int n,
   int& sumNegative, int& sumPositive,
   int& sumEvenIndex, int& sumOddIndex) {
   sumNegative = sumPositive = sumEvenIndex = sumOddIndex = 0;

   for (int i = 0; i < n; i++) {
      if (mas[i] < 0)
         sumNegative += mas[i];
      else if (mas[i] > 0)
         sumPositive += mas[i];

      if (i % 2 == 0)
         sumEvenIndex += mas[i];
      else
         sumOddIndex += mas[i];
   }
}

// Поиск минимума и максимума с индексами
void findMinMax(const int mas[], int n,
   int& minVal, int& maxVal,
   int& minIndex, int& maxIndex) 
{
   minVal = maxVal = mas[0];
   minIndex = maxIndex = 0;

   for (int i = 1; i < n; i++) {
      if (mas[i] > maxVal) {
         maxVal = mas[i];
         maxIndex = i;
      }
      if (mas[i] < minVal) {
         minVal = mas[i];
         minIndex = i;
      }
   }
}

// Произведение элементов между двумя индексами
long long calculateProductBetween(const int mas[], int start, int end, bool& hasElements) {
   hasElements = false;
   if (start >= end) {
      return 0;
   }

   hasElements = true;
   long long product = 1;
   for (int i = start; i < end; i++) {
      product *= mas[i];
   }
   return product;
}



int ControlTask1()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   int n;
   cout << "Введите размер массива: ";
   cin >> n;

   if (n <= 0) {
      cout << "Некорректный размер массива." << endl;
      return 1;
   }

   int* mas = new int[n];

   // Ввод массива
   inputArray(mas, n);

   // Сохранить копию исходного массива
   int* originalMas = new int[n];
   for (int i = 0; i < n; i++) {
      originalMas[i] = mas[i];
   }

   // Вывод исходного массива
   cout << "\nИсходный массив: ";
   for (int i = 0; i < n; i++) {
      cout << originalMas[i] << " ";
   }
   cout << endl;

   // Сортировка
   selectionSort(mas, n);
   cout << "\nОтсортированный массив: ";
   for (int i = 0; i < n; i++) {
      cout << mas[i] << " ";
   }
   cout << endl;

   // Среднее значение
   double avg = calculateAverage(mas, n);
   cout << "\nСреднее значение: " << avg << endl;

   // Различные суммы
   int sumNeg, sumPos, sumEven, sumOdd;
   calculateSums(mas, n, sumNeg, sumPos, sumEven, sumOdd);
   cout << "Сумма отрицательных элементов: " << sumNeg << endl;
   cout << "Сумма положительных элементов: " << sumPos << endl;
   cout << "Сумма элементов с чётными индексами: " << sumEven << endl;
   cout << "Сумма элементов с нечётными индексами: " << sumOdd << endl;

   // Минимум и максимум с индексами
  

   int minVal, maxVal, minIdx, maxIdx;
   findMinMax(originalMas, n, minVal, maxVal, minIdx, maxIdx);
   cout << "\nМинимальное значение: " << minVal << " (индекс " << minIdx << ")" << endl;
   cout << "Максимальное значение: " << maxVal << " (индекс " << maxIdx << ")" << endl;

   // Произведение между мин и макс
   int start = min(minIdx, maxIdx) + 1;
   int end = max(minIdx, maxIdx);
   bool hasElements;
   long long product = calculateProductBetween(originalMas, start, end, hasElements);

   if (hasElements) {
      cout << "Произведение элементов между минимумом и максимумом: " << product << endl;
   }
   else {
      cout << "Между минимумом и максимумом нет элементов." << endl;
   }

   // Освобождение памяти
   delete[] mas;
   delete[] originalMas;
}

