#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Item.h"


class AudioBook : public Item
{
private:
	double time;
public:
	void getdata()
	{
		Item::getdata();
		cout << "Введите время звучания : ";
		cin >> time;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\nВремя звучания : " << time;
	}
};