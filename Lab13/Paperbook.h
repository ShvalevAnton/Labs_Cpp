#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Item.h"

class Paperbook : public Item
{
private:
	int pages;
public:
	void getdata()
	{
		Item::getdata();
		cout << "Введите число страниц : ";
		cin >> pages;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\nСтраниц:" << pages;
	}
};

