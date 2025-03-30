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

	//修改数组中的值
	for (int i = 0; i < arr.Size(); i++)
	{
		arr.Get(i) = i + 100;
	}
	printMyarray(arr);

	//指定位置修改值
	arr.Set(2, 0);
	printMyarray(arr);

	//测试是否发生浅拷贝
	MyArray arr2 = arr;
	printMyarray(arr2);
}


void test2()
{
	MyArray arr;

	//添加元素
	
	for (int i = 0; i < 10; i++)
	{
		//头插
		arr.PushFront(i + 10);
	}
	printMyarray(arr);

	for (int i = 0; i < 9; i++)
	{
		//尾插
		arr.PushBack(i + 20);
	}
	printMyarray(arr);

	//指定位置插入
	arr.Insert(10, 520);
	printMyarray(arr);
	
}
int main()
{
	//test1();
	test2();

	return 0;
}