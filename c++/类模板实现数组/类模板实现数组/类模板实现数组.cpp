#include <iostream>
using namespace std;
#include "Myarray.hpp"
#include <string>
class Maker
{
	
public:
	Maker() {}
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

public:
	string name;
	int age;
};

void printMaker(Myarray<Maker>& arr)
{
	for (int i = 0; i < arr.getmsize(); i++)
	{
		cout << "ĞÕÃû;" << arr[i].name << "ÄêÁä£º" << arr[i].age << endl;
	}
}
void test()
{
	Myarray<Maker> myarr(4);
	Maker m1("Îò¿Õ", 18);
	Maker m2("Îò¿Õ2", 181);
	Maker m3("Îò¿Õ3", 182);
	Maker m4("Îò¿Õ4", 184);
	myarr.Push_back(m1);
	myarr.Push_back(m2);
	myarr.Push_back(m3);
	myarr.Push_back(m4);

	printMaker(myarr);

	Myarray<int> myint(10);
	for (int i = 0; i < 10; i++)
	{
		myint.Push_back(i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myint[i] << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}