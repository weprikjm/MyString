#include <iostream>
#include "MyString.h"


int main(int argc, char** argv)
{
	MyString string0;
	MyString string(string0);
	MyString string2("hello");
	MyString string3(string2);


	printf("%s",string3.c_str());
	getchar();
	return 0;
}