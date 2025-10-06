#include <iostream>
#include <Windows.h>
using namespace std;

// ������� ��� �������� ������������ �����
bool isValidFlag(const char* flag) {
   return (strncmp(flag, "-a", 2) == 0) || (strncmp(flag, "-m", 2) == 0);
}

// ������� ��� ���������� ��������
int performOperation(const char* flag, int a, int b) {
   if (strncmp(flag, "-a", 2) == 0) {
      return a + b;
   }
   else { // "-m"
      return a * b;
   }
}

int ControlTask4()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   string flagStr;
   int num1, num2;

   cout << "������� ���� (-a ��� -m) � ��� ����� �����: ";
   cin >> flagStr >> num1 >> num2;

   // �������� �����
   if (!isValidFlag(flagStr.c_str())) {
      cerr << "������: �������� ����. ����������� -a (��������) ��� -m (���������).\n";
      return 0;
   }

   int result = performOperation(flagStr.c_str(), num1, num2);
   cout << result << endl;

   return 0;
}

