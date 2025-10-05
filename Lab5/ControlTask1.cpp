#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// ���� �������
void inputArray(int mas[], int n) {
   for (int i = 0; i < n; i++) {
      cout << "mas[" << i << "] = ";
      cin >> mas[i];
   }
}

// ����������
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

// ���������� �������� ��������
double calculateAverage(const int mas[], int n) {
   int sum = 0;
   for (int i = 0; i < n; i++) {
      sum += mas[i];
   }
   return static_cast<double>(sum) / n;
}

// ������� ��������� ����
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

// ����� �������� � ��������� � ���������
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

// ������������ ��������� ����� ����� ���������
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
   cout << "������� ������ �������: ";
   cin >> n;

   if (n <= 0) {
      cout << "������������ ������ �������." << endl;
      return 1;
   }

   int* mas = new int[n];

   // ���� �������
   inputArray(mas, n);

   // ��������� ����� ��������� �������
   int* originalMas = new int[n];
   for (int i = 0; i < n; i++) {
      originalMas[i] = mas[i];
   }

   // ����� ��������� �������
   cout << "\n�������� ������: ";
   for (int i = 0; i < n; i++) {
      cout << originalMas[i] << " ";
   }
   cout << endl;

   // ����������
   selectionSort(mas, n);
   cout << "\n��������������� ������: ";
   for (int i = 0; i < n; i++) {
      cout << mas[i] << " ";
   }
   cout << endl;

   // ������� ��������
   double avg = calculateAverage(mas, n);
   cout << "\n������� ��������: " << avg << endl;

   // ��������� �����
   int sumNeg, sumPos, sumEven, sumOdd;
   calculateSums(mas, n, sumNeg, sumPos, sumEven, sumOdd);
   cout << "����� ������������� ���������: " << sumNeg << endl;
   cout << "����� ������������� ���������: " << sumPos << endl;
   cout << "����� ��������� � ������� ���������: " << sumEven << endl;
   cout << "����� ��������� � ��������� ���������: " << sumOdd << endl;

   // ������� � �������� � ���������
  

   int minVal, maxVal, minIdx, maxIdx;
   findMinMax(originalMas, n, minVal, maxVal, minIdx, maxIdx);
   cout << "\n����������� ��������: " << minVal << " (������ " << minIdx << ")" << endl;
   cout << "������������ ��������: " << maxVal << " (������ " << maxIdx << ")" << endl;

   // ������������ ����� ��� � ����
   int start = min(minIdx, maxIdx) + 1;
   int end = max(minIdx, maxIdx);
   bool hasElements;
   long long product = calculateProductBetween(originalMas, start, end, hasElements);

   if (hasElements) {
      cout << "������������ ��������� ����� ��������� � ����������: " << product << endl;
   }
   else {
      cout << "����� ��������� � ���������� ��� ���������." << endl;
   }

   // ������������ ������
   delete[] mas;
   delete[] originalMas;
}

