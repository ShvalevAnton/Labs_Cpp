#pragma once
#include <iostream>
using namespace std;

class Distance2
{
private:
	int feet;
	float inches;
	const float MTF;
public:
	// конструктор по умолчанию
	Distance2() : feet(0), inches(0.0), MTF(3.280833F) {}
	// конструктор с двум€ параметрами
	Distance2(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}
	Distance2(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters; // перевод в футы
		feet = int(fltfeet); // число полных футов
		inches = 12 * (fltfeet - feet); // остаток - это дюймы
	}
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
	Distance2 operator+ (const Distance2&) const;

	Distance2 operator- (const Distance2&) const;

	// ƒружественные функции дл€ работы с разными типами
	friend Distance2 operator+ (const Distance2&, float);
	friend Distance2 operator+ (float, const Distance2&);
	friend Distance2 operator- (const Distance2&, float);
	friend Distance2 operator- (float, const Distance2&);

	friend ostream& operator<< (std::ostream& out, const Distance2& dist);

	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}
};

