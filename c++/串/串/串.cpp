#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>

using namespace std;

class String
{
private:
	char* str;
	size_t length;

public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	size_t getlength() const;
	char operator [] (size_t index) const;
	String& operator=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	String copy() const;
	String operator+(const String& s);
	friend ostream& operator<<(ostream& out, const String& s);
};

String::String()
{
	length = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
}

String::String(const String& s)
{
	length = s.length;
	str = new char[length + 1];
	strcpy(str, s.str);
}

String::~String()
{
	delete[] str;
}

size_t String::getlength() const
{
	return length;
}

char String :: operator[](size_t index) const
{
	return str[index];
}

String& String ::operator=(const String& s)
{
	if (this != &s)
	{
		delete[] str;
		length = s.length;
		str = new char[length + 1];
		strcpy(str, s.str);
	}
	return *this;
}

bool String::operator==(const String& s)
{
	return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String& s)
{
	return strcmp(str, s.str) != 0;
}

String String::copy() const
{
	String s = *this;//�൱��s(*this)
	return s;
}

String String::operator+(const String& s)
{
	String result;
	result.length = length + s.length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcat(result.str, s.str);
	return result;
}

ostream& operator<<(ostream& out, const String& s)
{
	out << s.str;
	return out;
}


int main()
{
	String s("12345d");
	cout << s << endl;
	cout << s + "445" << endl;
	cout << s[5] << endl;
	cout << (s == "12345d") << endl;
	cout << (s != "12345d") << endl;
	s = s + "asd";
	cout << s << endl;
	String a, b, c;
	a = b = c = s;
	cout << a << b << c << s << endl;
	String x = s.copy();
	cout << x << endl;

	return 0;
}