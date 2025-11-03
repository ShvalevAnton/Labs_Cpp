
#include "IdCard_ex2.h"


	IdCard_ex2::IdCard_ex2(int n)
	 {
        number = n;
		category = "Не установлена";
	 }
	IdCard_ex2::IdCard_ex2()
	 {
        number = 0;
		category = "Не установлена";
	 }
	IdCard_ex2::IdCard_ex2(int n, string cat)
	 {
        number = n;
		category = cat;
	 }

    void IdCard_ex2::setNumber(int newNumber)
	{
        number = newNumber;
    }
    
	int IdCard_ex2::getNumber()
	{
        return number;
    }


	void IdCard_ex2::setCategory(string cat)
	{
		category = cat;
	}

	string IdCard_ex2::getCategory()
	{
		return category;
	}


