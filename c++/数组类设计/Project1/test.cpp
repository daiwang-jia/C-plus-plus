#include <iostream>
#include <string>
#include "MyArray.h"

using namespace std;

void printMyarray(MyArray& arr)
{
	for (int i = 0; i < arr.Size(); i++)
	{
		cout << arr.Get(i) << " ";
	}
	cout<< endl;
}
void test1()
{
	MyArray arr(20, 1);
	printMyarray(arr);

	//�޸������е�ֵ
	for (int i = 0; i < arr.Size(); i++)
	{
		arr.Get(i) = i + 100;
	}
	printMyarray(arr);

	//ָ��λ���޸�ֵ
	arr.Set(2, 0);
	printMyarray(arr);

	//�����Ƿ���ǳ����
	MyArray arr2 = arr;
	printMyarray(arr2);
}


void test2()
{
	MyArray arr;

	//���Ԫ��
	
	for (int i = 0; i < 10; i++)
	{
		//ͷ��
		arr.PushFront(i + 10);
	}
	printMyarray(arr);

	for (int i = 0; i < 9; i++)
	{
		//β��
		arr.PushBack(i + 20);
	}
	printMyarray(arr);

	//ָ��λ�ò���
	arr.Insert(10, 520);
	printMyarray(arr);
	
}
int main()
{
	//test1();
	test2();

	return 0;
}