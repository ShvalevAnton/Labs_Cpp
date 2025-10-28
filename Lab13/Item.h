#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Item
{
private:
	string title;
	double price;
public:
	virtual void getdata()
	{
		cout << "\nВведите заголовок : ";
		cin >> title;
		cout << "Введите цену : ";
		cin >> price;
	}
	virtual void putdata()
	{
		cout << "\nЗаголовок: " << title;
		cout << "\nЦена:" << price;
	}
};