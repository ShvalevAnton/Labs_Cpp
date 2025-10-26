#pragma once
#include <iostream>
using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0) {}
	// конструктор с двум€ параметрами
	Distance(int ft, float in) : feet(ft), inches(in) {}
	void getdist()
	{
		cout << "\n¬ведите число футов : ";
		cin >> feet;
		cout << "\n¬ведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\" - " << inches << "\"\n";
	}
	Distance operator+ (const Distance&) const;

	Distance operator- (const Distance&) const;

	friend ostream& operator<< (std::ostream& out, const Distance& dist);
};