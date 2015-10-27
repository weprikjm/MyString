
typedef unsigned int uint;

class MyString
{
public:
//Constructors
	MyString(){}
	MyString(uint _capacity);
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
//Getters
	const char* c_str()const;

private:
	int CalculateSize(const char*)const;
private:
	int capacity;
	char* str;

};