#include <iostream>
#include <string>
#include "student.cpp"
using namespace std;
int Exercise4()
{
	// Создание объекта класса Student
	string name;
	string last_name;
	// Ввод имени с клавиатуры
	cout << "Name: ";
	getline(cin, name);
	// Ввод фамилии
	cout << "Last name: ";
	getline(cin, last_name);
	Student *student = new Student(name, last_name);

	// Оценки
	int scores[5];
	// Сумма всех оценок
	int sum = 0;
	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}
	// Сохраняем промежуточные оценки в объект класса Student
	student->set_scores(scores);
	// Считаем средний балл
	double average_score = sum / 5.0;
	// Сохраняем средний балл в объект класса Student
	student->set_average_score(average_score);
	// Выводим данные по студенту
	cout << "Average ball for " << student->get_name() << " "
		<< student->get_last_name() << " is "
		<< student->get_average_score() << endl;

	delete student;
	return 0;
}