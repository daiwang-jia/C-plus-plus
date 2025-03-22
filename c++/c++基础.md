## 函数指针:    
```c++
#include <iostream>
using namespace std;

//函数指针
double (*ptr)(int a, int b, int c);
void (*ptr1)(int a, int b);

double func(int a, int b, int c)
{
	cout << a << ' ' << b << ' ' << c<<endl;
	return 0.0;
}

void func1(int a, int b)
{
	cout << a << ' ' << b << endl;

}

int main()
{
	ptr = func;
	ptr(4, 5, 6);
	ptr1 = func1;
	//ptr = func1;  错误
	ptr1(5, 6);
	return 0;
}
```     

## 函数指针类型定义:   
```c++
#include <iostream>
using namespace std;

//函数指针的定义
void (*ptr1)(int a, int b, float c, char d);
void(*ptr2)(int a, int b, float c, char d);
void func1(int a, int b, float c, char d)
{
	cout << "func1" << endl;
}

//函数指针的类型定义
typedef void (*ptr)(int a, int b, float c, char d);


int main()
{
	ptr1 = func1;
	ptr1(1, 2, 3, 4);

	ptr2 = func1;
	ptr2(8, 7, 6, 5);

	ptr pt1 = func1;
	pt1(1, 3, 4, 6);
	return 0;
}
```