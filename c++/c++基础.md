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

**手机短号**     
```c++
#include <iostream>
using namespace std;

//手机短号
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char s[12];
		cin >> s;
		cout << '6' << s+6 << endl;
	}
	
	return 0;
}
```    

## 结构体数组
```c++
#include <iostream>
#include <string>
using namespace std;

//结构体数组
struct Book {
	string name;
	double price;
	int value;
};
int main()
{
	Book books[3] = {
		{"C语言程序设计",1999.99,10},
		{"python 零基础",39.99,9},
		{"c++零基础",9999999.99,100000000}
	};
	for (int i = 0; i < 3; i++)
	{
		cout << books[i].name << ' ' << books[i].price << " " << books[i].value << endl;
	}

	return 0;
}
```     

## 结构体指针
```c++
#include <iostream>
#include <string>
using namespace std;

//结构体指针
struct Book {
	string name;
	double price;
	int value;
};
int main()
{
	Book b = { "C语言", 99.99, 7 };
	Book c = b;
	c.name = "C++";
	Book* pb = &b;
	pb->name = "C语言入门";
	cout << b.name << " " << b.price << " " << b.value << endl;
	cout << c.name << " " << c.price << " " << c.value << endl;
	return 0;
}
```  

##  嵌套结构体
```c++
#include <iostream>
#include <string>
using namespace std;

//嵌套结构体
struct Point {
	double x, y;

};

struct Circle {
	Point pt;//double x, y;
	double radius;
};

struct Circles {
	int size;
	Circle c[100];
};
int main()
{
	Circle c;
	c.pt.x = 9;
	c.pt.y = 8;
	c.radius = 5;

	Circles cs = {
		2,{
			{{9,8},5},
		{{2,1},1}

		}
	};
	for (int i = 0; i < cs.size; i++)
	{
		Circle tmp = cs.c[i];
		cout << "(" << tmp.pt.x << "," << tmp.pt.y <<")"<<" "<<tmp.radius << endl;
	}
	return 0;
}
```  

## 结构体传参
```c++
#include <iostream>
#include <string>
using namespace std;

//结构体传参
struct Point {
	double x, y;

};

struct Circle {
	Point pt;//double x, y;
	double radius;
};

void moveCircle(Circle *c, int x, int y)
{
	c->pt.x += x;
	c->pt.y += y;
}

//void printCircle(Circle c)
//{
//	cout << "(" << c.pt.x << "," << c.pt.y << ")" << endl;
//}

void printCircle(const Circle *c)
{
	cout << "(" << c->pt.x << "," << c->pt.y << ")" << endl;
}
int main()
{
	Circle c = { {9,8},5 };
	moveCircle(&c, 1, 2);
	/*printCircle(c);*/
	printCircle(&c);
	return 0;
}
```  

**今年暑假不AC:**  
```c++
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
//今年暑假不Ac
struct Interval
{
	int s;
	int e;
}I[100];

bool cmp(const Interval& a, const Interval& b)
{
	return a.e < b.e;

}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> I[i].s  >> I[i].e;
		}
		sort(I, I + n, cmp);
		int end = -1;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (I[i].s >= end)
			{
				ans++;
				end = I[i].e;
			}
			
		}
		cout << ans << endl;
	}

	return 0;
}
```


## 联合体的定义和使用
```c++
#include <iostream>
#include <string>
#include <algorithm>

//联合体的定义和使用
//与结构体区别：共享内存,相互影响
using namespace std;
union DataU
{
	int i;
	double d;
	char s[10];
};
int main()
{
	DataU ds;
	cout << &ds.i <<endl<< &ds.d <<endl<< &ds.s << endl;
	//0000008A6D2FF968
	//0000008A6D2FF968
	//0000008A6D2FF968
	return 0;
}
```

## 内存布局:
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
union DataU
{
	int i;
	double d;
	char s[7];
};
int main()
{
	cout << sizeof(DataU) << endl;  //8
	DataU du;
	du.s[0] = 255;
	du.s[1] = 1;
	du.s[2] = 0;
	du.s[3] = 0;
	cout << du.i << endl;
	du.i = 258;
	cout << (int)du.s[0] << (int)du.s[1] << (int)du.s[2] << (int)du.s[3] << endl;

	return 0;
}
```

## 内存申请和释放     
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//内存申请和释放
//new 和 delete
int main()
{
	int* ptr = new int(1314);
	*ptr = 520;
	cout << *ptr << endl;

	delete (ptr);
	ptr = NULL;
	while (1)
	{

	}


	return 0;
}
------------------------------------------------------------------------
int* getarr(int* arr, int size)
{
	int* p = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		p[i] = arr[i + 1] - arr[i];
	}
	return p;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int* p = getarr(arr, size);
	for (int i = 0; i < size-1; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl;
	delete(p);
	p = NULL;

	return 0;
}
```