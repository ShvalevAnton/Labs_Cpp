#include <iostream>
#include <Windows.h>

using namespace std;

int Exercise2()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char op;

	cout << "������ ���� �����, ������ ���� ���� �����: ";
	cin >> op;

	switch (op)
	{
	case 'V':
		cout << "����������� ����\n";
	case 'S':
		cout << "����� ������ ������\n";
	default:
		cout << "������ �������\n";
		cout << "������ ���������\n";
	}
	return 0;
}