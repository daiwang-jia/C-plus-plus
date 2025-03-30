#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyString
{
	friend ostream& operator<<(ostream& out, MyString& str);
	friend istream& operator>>(istream& in, MyString& str);
public:
	MyString();
	MyString(int n, char c);// �û����Գ�ʼ���ַ���
	MyString(const MyString& str);
	MyString& operator=(const MyString& str);
	~MyString();

	MyString operator+(const MyString& str);
	MyString operator+(const char *s);

	MyString& operator+=(const MyString& str);
	MyString& operator+=(const char *s);

	int Size();

	char& operator[](int index);




private:
	char* pM; //ָ������ռ�
	int mSize;
};

