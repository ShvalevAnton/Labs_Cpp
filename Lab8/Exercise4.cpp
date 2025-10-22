#include <iostream>
#include <string>
#include "student.cpp"
using namespace std;
int Exercise4()
{
	// �������� ������� ������ Student
	string name;
	string last_name;
	// ���� ����� � ����������
	cout << "Name: ";
	getline(cin, name);
	// ���� �������
	cout << "Last name: ";
	getline(cin, last_name);
	Student *student = new Student(name, last_name);

	// ������
	int scores[5];
	// ����� ���� ������
	int sum = 0;
	// ���� ������������� ������
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// ������������
		sum += scores[i];
	}
	// ��������� ������������� ������ � ������ ������ Student
	student->set_scores(scores);
	// ������� ������� ����
	double average_score = sum / 5.0;
	// ��������� ������� ���� � ������ ������ Student
	student->set_average_score(average_score);
	// ������� ������ �� ��������
	cout << "Average ball for " << student->get_name() << " "
		<< student->get_last_name() << " is "
		<< student->get_average_score() << endl;

	delete student;
	return 0;
}