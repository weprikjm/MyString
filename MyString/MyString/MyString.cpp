#include "MyString.h"
#include <iostream>


const char* MyString::c_str()const
{
	if (str != NULL)
		return str;
}





MyString::MyString(uint _capacity)
{
	if (_capacity > 0)
	{
		str = new char[_capacity];
		capacity = _capacity;
	}
	else
	{
		printf("Error found: Capacity should be higher than 0.");
	}

}
MyString::MyString(const char* _str)
{

	if (_str != NULL)
	{
		int size = CalculateSize(_str);

		if (size > 0)//In case _str is empty ""
		{
			size += 1;
			str = new char[size];
			capacity = size;
			strcpy_s(str, size, _str);
		}
		else
		{
			capacity = 1;
			str = new char[1];
			*str = '\0';
			
		}
	}
	else
		printf("Error found: The string trying to build is empty");


}
MyString::MyString(const MyString& _myString)
{

	if (_myString.c_str() != NULL||_myString.capacity > 0)
	{
		const char* s = _myString.c_str();

		int sizeB = CalculateSize(s);
		sizeB++;						//We add one position for the 0 because it is not taken into account.

		str = new char[sizeB];
		capacity = sizeB;

		strcpy_s(str, sizeB, s);
	}
	else
	{
		capacity = 1;
		str = new char[1];
		str = '\0';
	}


}

MyString::~MyString()
{
	delete[] str;
}


int MyString::CalculateSize(const char* str)const
{
	int size = 0;
	const char* tmpStr = str;


	for (; *tmpStr != '\0'; tmpStr++)
	{
		size++;
	}

	return size;
}