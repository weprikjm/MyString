#include <iostream>
#include "MyString.h"


int main(int argc, char** argv)
{
	MyString string0;
	MyString string(string0);
	MyString string2("hello");
	MyString string3("hell");

	if (string2 != string3){ }
		
	if (string2 != "hello"){ }

	if (string2 == "hello"){ }
	
	
	printf("\n%s",string3.c_str());
	getchar();
	return 0;
}