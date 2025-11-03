#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>

using namespace std;

 class IdCard_ex2
 {
 private:
	 int number;
	 string category;

 public:
	 IdCard_ex2();
	 IdCard_ex2(int);
	 IdCard_ex2(int, string);

    void setNumber(int newNumber);
	 int getNumber();
	 void setCategory(string cat);
	 string getCategory();

};