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
	// ����������� �� ���������
	Distance2() : feet(0), inches(0.0), MTF(3.280833F) {}
	// ����������� � ����� �����������
	Distance2(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}
	Distance2(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters; // ������� � ����
		feet = int(fltfeet); // ����� ������ �����
		inches = 12 * (fltfeet - feet); // ������� - ��� �����
	}
	void getdist()
	{
		cout << "\n������� ����� ����� : ";
		cin >> feet;
		cout << "\n������� ����� ������ : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\" - " << inches << "\"\n";
	}
	Distance2 operator+ (const Distance2&) const;

	Distance2 operator- (const Distance2&) const;

	// ������������� ������� ��� ������ � ������� ������
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

