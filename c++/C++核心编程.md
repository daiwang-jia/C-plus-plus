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


**引用作为函数返回值：**    
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int &getarrayvalue(int arr[], int index)
{
	return  arr[index];
}
int main()
{

	int a[] = { 1,2,3,4,5 };
	cout << getarrayvalue(a, 3) << endl;

	getarrayvalue(a, 3) = 999;
	cout << getarrayvalue(a, 3) << endl;



	return 0;
}
```   

**常量引用：**
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct S
{
	int a, b, c, d, e, f;
};

void printS(const S& s)
{
	//s.b=530;
	cout << s.a << s.b << s.c << s.d << s.e << s.f  << endl;
}

int main()
{
	int a;
	const int& b = a;
	//引用=指针常量
	//常量引用=常量指针常量

	S s = { 1,2,3,4,5,6 };
	printS(s);

	return 0;
}
```    

**<font color=red>指针常量和常量指针：</font>** 
```c++
int main()
{
	int a=1;
	int b=2;
	//指针常量
	//指针的值是一个常量
	int * const p=&a;
	//p=&b;  无法修改
	*p=6;  正确

	printf("-----------------------")

	//常量指针
	int a=1;
	int b=2;
	//指向常量的指针
	const int *p=&a;
    //*p=6;  无法修改
	p=&b; 正确

	return 0;

}

```

**指针引用：**   
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void allocmemory(char*& ptr, int bytes)
{
	ptr = new  char[bytes];
}

void test()
{
	char* p = NULL;
	allocmemory(p, 5);
	cout << (void*)p << endl;
}
int main()
{
	test();
	return 0;
}
```

## 属性和行为
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//面对对象的三大特性：封装、继承、多态

/*
封装的语法；

class 类名
{
访问权限：
	属性（成员变量）
	行为（成员函数）
}；
*/

class hero
{
	//访问权限
public:
	//属性
	int m_ID;  //m->member
	int m_HP; 

	//行为
	void addHP(int HP)
	{
		m_HP += HP;
	}

	void subHP(int HP)
	{
		m_HP -= HP;
	}
};
int main()
{
	//通过类生成对象的过程，叫 实例化
	hero h;
	//访问对象属性
	h.m_ID = 5;
	h.m_HP = 500;
	h.addHP(100);
	cout << "ID为" << h.m_ID << "的英雄，血量是" << h.m_HP << endl;
	h.subHP(100);
	cout << "ID为" << h.m_ID << "的英雄，血量是" << h.m_HP << endl;


	return 0;
}

```   


## 访问权限：
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
访问权限
公共权限  public      类内可以访问，类外也可以访问
保护权限  protected   类内可以访问，类外不可以访问  子类可以访问
私有权限  private     类内可以访问，类外不可以访问  子类不可以访问

B->A

A  父类、基类   名字，房子，支付密码
B  子类、派生类 公有，保护，私有

*/

class People
{
public:
	int m_id;
protected:
	int m_house;
private:
	int m_paypass;

public:
	void work()
	{
		//所有成员变量类内均可以访问
		m_id = 1;
		m_house = 2;
		m_paypass = 1314;
	}

protected:
	void work1()
	{
		//所有成员变量类内均可以访问
		m_id = 1;
		m_house = 2;
		m_paypass = 1314;
	}

private:
	void work2()
	{
		//所有成员变量类内均可以访问
		m_id = 1;
		m_house = 2;
		m_paypass = 1314;
	}

};

class son :public People
{
	void func()
	{
		m_id = 1;
		m_house = 4;   //保护成员，子类可以访问
		//m_paypass = 123;  //私有成员，子类不可以访问
	}
};
int main()
{
	People p;
	p.m_id = 1;   //公有成员，类外可以访问
	//p.m_house = 5;  //保护成员类外不可以访问
	//p.m_paypass = 10;//保护成员类外不可以访问

	p.work();
	//p.work1();  //不可以访问
	//p.work2();  //不可以访问   
	return 0;
}
```  

**<font color=red>class和struct</font>**   
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*

struct && class

struct 默认是公共的  (c++中可以定义函数，c不可以）

class 默认是私有的

*/

class C
{
	int m_a;

};

struct S
{
	int m_a;

	void func()
	{
		m_a = 666;
	}
};
int main()
{
	C c;
	S s;
	//c.m_a;  //错误，私有的
	s.m_a = 1;  //正确，公有的
	
	s.func();
	cout << s.m_a << endl;   //666
	return 0;
}
```   


## 属性私有化：
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//接口，方法，函数 是同一个概念

//1、可以控制读写权限
//2、可以检测数据的有效性
class Hero
{
public:
	void setname(string name)
	{
		m_name = name;
	}
	string getname()
	{
		return m_name;
	}

	int getskillcount()
	{
		return m_skillcount;
	}

	void setspeed(int speed)
	{
		m_speed = speed;
	}
private:
	string m_name;          //可读可写
	int m_skillcount=100;      //只读
	int m_speed;            //只写
};
int main()
{
	Hero h;
	//h.m_name = "123";
	//h.m_skillcount = 4;
	//h.m_speed = 10;
	h.setname("剑圣");
	cout << "英雄的名字叫" << h.getname() << endl;  //可读可写

	cout << h.getskillcount() << endl;   //只读

	h.setspeed(5);




	return 0;
}
```  

## 构造函数：   
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//构造函数需要注意的点
//1、函数类型和类名保持一致
//2、返回类型不需要写
//3、构造函数可以有参数


class Hero
{
public:
	//默认构造函数
	Hero()
	{
		m_skillcount = 4;
		m_speed = 100;
		m_name = "";
		cout << "默认构造函数：Hero构造完毕" << endl;
	}
	//有参构造函数1
	Hero(string name)
	{
		m_skillcount = 4;
		m_speed = 100;
		m_name = name;
		cout << "有参构造函数1：Hero构造完毕" << endl;
	}

	//有参构造函数2
	Hero(string name,int skillcount)
	{
		m_skillcount = skillcount;
		m_speed = 100;
		m_name = name;
		cout << "有参构造函数2：Hero构造完毕" << endl;
	}

private:
	string m_name;
	int m_skillcount;
	int m_speed;
};
int main()
{
	Hero h1;
	Hero h2("剑圣");
	Hero h3(); //不调用，不是对象实例化，是函数声明   int main();  int work();
	Hero h4{};  //默认构造函数：Hero构造完毕
	Hero h5 = Hero("剑圣");  //有参构造函数：Hero构造完毕
	Hero h6("猴子", 4);
	return 0;
}
```    

## 析构函数：
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//析构函数注意点
//1、函数名称与类名一致，并且在最前面加上~
//2、函数返回值不需要写
//3、不能有参数
class Hero
{
public:
	//构造函数
	Hero()
	{
		cout << "Hero默认构造函数构造完毕" << endl;
	}

	//析构函数（无参数）
	~Hero()
	{
		cout << "Hero析构函数构造完毕" << endl;
	}
};

void test()
{
	Hero h;
}
int main()
{
	test();
	Hero h;
	int a;
	cin >> a;

	return 0;
}
```   

## 拷贝构造函数：
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*

拷贝构造函数定义
类名（const 类型& 变量名）

*/
class Hero
{
public:
	//默认构造函数
	Hero()
	{
		m_hp = 100;
		cout << "Hero默认构造函数构造完毕" << endl;
	}
	//有参构造函数
	Hero(int hp)
	{
		m_hp = hp;
		cout << "Hero有参构造函数构造完毕" << endl;
	}

	Hero(const Hero& h)
	{
		//h.m_hp = 4;  报错
		m_hp = h.m_hp;
		cout << "Hero拷贝构造函数构造完毕" << endl;
	}
	//析构函数
	~Hero()
	{
		cout << "析构函数调用完毕" << endl;
	}

private:
	int m_hp;
};

/*
拷贝构造函数的调用时机

1、用已经创建的对象来初始化对象
2、函数的传参
3、函数的返回值

*/

//1、用已经创建的对象来初始化对象
void func1()
{
	cout << "-------------func1------------" << endl;
	Hero h1(20);
	Hero h2(h1);
}
//2、函数的传参
void test1(Hero h)
{

}

void test2(Hero* h)
{

}
void func2()
{
	cout << "-------------func2------------" << endl;
	Hero h1;
	test1(h1);
	test2(&h1);//不会调用
}

//3、函数的返回值
Hero test3()
{
	Hero h(40);
	return h;
}

void func3()
{
	cout << "-------------func3------------" << endl;
	Hero h=test3();//要关闭优化
}
int main()
{
	func1();
	func2();
	func3();
	return 0;
}
```