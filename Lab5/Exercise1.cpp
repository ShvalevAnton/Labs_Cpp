#include <iostream>
#include <Windows.h>
#include <climits> // ��� INT_MAX � INT_MIN
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

   // ����� �����
   int s = 0;
   for (int i = 0; i < n; i++)
   {
      s += mas[i];
   }
   double avg = static_cast<double>(s) / n;

   // ����� ������������� ���������
   int sumNegative = 0;
   // ����� ������������� ���������
   int sumPositive = 0;
   // ����� ��������� � ��������� ���������
   int sumOddIndex = 0;
   // ����� ��������� � ������� ���������
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

   // �������������� �������:
   // ����� ������������ � ����������� �������� � �� �������
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

   // ������������ ��������� ����� ������������ � �����������
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
      productBetween = 0; // ��� ��������� �����
   }

   // ����� �����������
   cout << "\n=== ���������� ��������� ������� ===" << endl;
   cout << "����� ���� ��������� �������: " << s << endl;
   cout << "������� �������� ��������� �������: " << avg << endl;
   cout << "����� ������������� ���������: " << sumNegative << endl;
   cout << "����� ������������� ���������: " << sumPositive << endl;
   cout << "����� ��������� � ������� ���������: " << sumEvenIndex << endl;
   cout << "����� ��������� � ��������� ���������: " << sumOddIndex << endl;
   cout << "������������ �������: " << maxVal << " (������: " << maxIndex << ")" << endl;
   cout << "����������� �������: " << minVal << " (������: " << minIndex << ")" << endl;

   if (hasElementsBetween)
      cout << "������������ ��������� ����� ����������� � ������������: " << productBetween << endl;
   else
      cout << "����� ����������� � ������������ ���������� ��� ������ ���������." << endl;

   return 0;
}