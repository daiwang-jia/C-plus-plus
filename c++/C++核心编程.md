## 引用：
**引用的语法：** 
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//引用：给变量取别名
//&
//数据类型 & 变量名=变量

void test()
{
	int a_very_very_very_very_very_very_array[8] = { 1,1 };
	for (int i = 2; i < 8; i++)
	{
		a_very_very_very_very_very_very_array[i] = a_very_very_very_very_very_very_array[i - 1] * a_very_very_very_very_very_very_array[i - 1] + a_very_very_very_very_very_very_array[i - 2] * a_very_very_very_very_very_very_array[i - 2];
	}
	for (int i = 0; i < 8; i++)
	{
		cout << a_very_very_very_very_very_very_array[i] << " ";
	}

	cout << endl;
	for (int i = 2; i < 8; i++)
	{
		a_very_very_very_very_very_very_array[i] = 0;
	}

	for (int i = 2; i < 8; i++)
	{
		int pre1 = a_very_very_very_very_very_very_array[i - 1];
		int pre2 = a_very_very_very_very_very_very_array[i - 2];
		int &now = a_very_very_very_very_very_very_array[i];
		now = pre1 * pre1 + pre2 * pre2;
	}

	for (int i = 0; i < 8; i++)
	{
		cout << a_very_very_very_very_very_very_array[i] << " ";
	}

}
int main()
{
	//int a = 1314;
	//int& b = a;
	//b = 520;
	//cout << "a=" << a << endl;//520
	//cout << "b=" << b << endl;//520

	int a = 1314;
	int* b =& a;
	*b = 520;
	cout << "a=" << a << endl;//520
	cout << "b=" << *b << endl;//520

	test();
	return 0;
}
```     
**引用的特性：**      
1. 必须初始化
2. 初始化以后无法修改
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	//int &a;  错误写法
	int a = 3, c = 6;
	int& b = a;
	b = c;  //b=6
	cout << a << b << c << endl;  //666
	return 0;
}
```      
**引用的本质：**   
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	int a = 520;
	//int &b=a;

	//b=1314;

	int* const b = &a;//指针常量

	*b = 1314;

	return 0;
}
```   
**引用作为函数传参：**   
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countandsum(int arr[], int size, int target, int& count)//int * count
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			count++;
			sum += arr[i];
		}
	}
	return sum;
}

struct S
{
	int a, b, c, d, e, f, g;
};

void printS(S& s)
{
	cout << s.a << s.b << s.c << s.d << s.e << s.f << s.g << endl;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,2,8,2,0 };
	int c = 0;
	int sum=countandsum(arr, 10, 2, c);///&c
	cout << sum << " " << c << endl;

	S s = { 1,2,3,4,5,6,7 };

	printS(s);
	return 0;

}
```