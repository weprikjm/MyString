#include "MyString.h"
#include <iostream>

MyString::MyString(){}

const char* MyString::c_str()const
{
	if (str != NULL)
		return str;
}


MyString::MyString(uint capacity)
{
	if (capacity > 0)
	{
		str = new char[capacity];
		this->capacity = capacity;
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

		uint sizeB = CalculateSize(s);
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
	if (str != NULL)
		delete[] str;
}


int MyString::CalculateSize(const char* str)const
{
	return strlen(str);
}





bool MyString::operator==(const MyString& _string)const
{
	bool ret = false;
	int size =_string.CalculateSize(_string.c_str());
	if (size > 0)
	{
		
		if (!strcmp(_string.c_str(),c_str()))
		{
			printf("Equals");
			ret = true;
		}
		else
		{
			printf("Different");
		}

		
	}
	return ret;
}

bool MyString::operator==(const char* str)const
{
	bool ret = false;
	int size = strlen(str);
	if (size > 0)
	{

		if (!strcmp(str, c_str()))
		{
			printf("Equals");
			ret = true;
		}
		else
		{
			printf("Different");
		}


	}
	return ret;
}





bool MyString::operator!=(const MyString& _string)const
{
	bool ret = false;
	int size = _string.CalculateSize(_string.c_str());
	if (size > 0)
	{

		if (strcmp(_string.c_str(), c_str()))
		{
			printf("Different");
			ret = true;
		}
		else
		{
			printf("Equals");
		}

		
	}
	return ret;
}


bool MyString::operator!=(const char* str)const
{
	bool ret = false;
	int size = CalculateSize(str) + 1;
	if (size > 0)
	{

		if (strcmp(str, c_str()))
		{
			printf("Different");
			ret = true;
		}
		else
		{
			printf("Equals");
		}


	}
	return ret;
}


const MyString& MyString::operator+=(const MyString& mStr)
{
	if (mStr.c_str() != NULL && str != NULL)
	{
		int sizeToFill = CalculateSize(str) + CalculateSize(mStr.c_str()) + 1;

		

		if (sizeToFill > GetCapacity())
		{	
			char* tmp = new char[sizeToFill];
			memset(tmp,0,sizeToFill);
			strcpy_s(tmp, CalculateSize(str)+1,str);
			//tmp[CalculateSize(str)] = '\0';
			delete(str);
			strcat_s(tmp, sizeToFill, mStr.str);
			str = tmp;

		}
		else
		{
			strcat_s(str, CalculateSize(mStr.c_str()) + 1, mStr.c_str());
		}
	}
	else
	{
		printf("Cannot Concatenate if any of the strings is null");
	}
	

	return (*this);
}


const MyString& MyString::operator+=(const char* mStr)
{
	
	if (mStr != NULL && str != NULL)
	{
		int sizeToFill = CalculateSize(str) + CalculateSize(mStr) + 1;



		if (sizeToFill > GetCapacity())
		{
			char* tmp = new char[sizeToFill];
			memset(tmp, 0, sizeToFill);
			strcpy_s(tmp, CalculateSize(str) + 1, str);
			delete(str);
			strcat_s(tmp, sizeToFill, mStr);
			str = tmp;

		}
		else
		{
			strcat_s(str, sizeToFill, mStr);
		}
	}
	else
	{
		printf("Cannot Concatenate if any of the strings is null");
	}


	return (*this);
}

const uint MyString::GetCapacity()const
{
	return capacity;
}