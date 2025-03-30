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

## 静态成员变量:
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
静态成员变量的特点：
1.所有对象共享同一份数据
2.编译阶段分配内存
3.需要在类内进行声明，类外初始化


*/
class Hero {
public:
	Hero()
	{
		m_Name = "英雄";
		m_hp = 100;
	}
	~Hero()
	{

	}

	static int m_Herocount;

private:
	string m_Name;
	int m_hp;

};

int Hero::m_Herocount = 100;
int main()
{
	Hero h;
	cout << h.m_Herocount << endl;  
	h.m_Herocount = 101;
	cout << Hero::m_Herocount << endl;

	return 0;
}

```  

## 静态成员函数：
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
静态成员函数
1.所有对象共享函数
2‘静态成员函数只能使用静态成员变量，无法使用普通成员变量

*/

class Hero {
public:
	Hero()
	{
		m_Name = "英雄";
		m_hp = 100;
	}
	~Hero()
	{

	}

	static int m_Herocount;

	static int Getherocount()
	{
		//m_hp+=1;
		return m_Herocount;
	}

private:
	string m_Name;
	int m_hp;

};

int Hero::m_Herocount = 100;
int main()
{
	Hero h;
	cout << h.Getherocount() << endl;

	cout << Hero::Getherocount() << endl;

	return 0;
}
```


## this指针：
```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
this 指针
1、解决命名冲突
2、*this就可以获取到这个对象

this     *this
&h         h
*/

class Hero {
public:
	Hero(int hp) {
		this->hp = hp;
		cout <<this << endl;
	}

	int hp;
};


int main()
{
	Hero h(100);

	cout << h.hp << endl;//100

	cout << &h << endl;
	return 0;
}
```

## const修饰成员函数：
```c++
#include <iostream>
#include <string>

using namespace std;

//const 修饰成员函数
class Hero{
	public :
		Hero():m_hp(0){
		}
		int getHp()const{
			//m_hp+=m_hp;   常函数，不能被修改 
			return m_hp;
		}
		
		int setHp(int hp)
		{
			m_hp=hp;
		}
	private:
		int m_hp;
			
}; 


int main()
{
	const Hero h;
	//h.setHp(100);  错误 
	h.getHp();//可以 
	return 0;
}

```


## mutable关键字:
```c++
#include <iostream>
#include <string>

using namespace std;

//mutable 关键字

class Hero{
	
	public :
		Hero():m_hp(0),m_gethpcounter(0){}
		
		int getHp() const {
			m_gethpcounter++;//如果没有mutable则报错 
			return m_hp;
		}
		
		void printcounter() const{
			cout << "countr:"<<m_gethpcounter<<endl;
		}
		
	private:
		int m_hp;
		mutable int m_gethpcounter;   
};

int main()
{
	Hero h;
	h.getHp(),h.getHp(),h.getHp();
	h.printcounter();
	return 0;
 } 
```

## 友元：
```c++
#include <iostream>
#include <string>
#include <algorithm>


/*
友元的目的

让一个类 或者 函数能够访问另一个类的私有成员

关键字：friend

三种友元：
1.全局函数作为友元
2.类作为友元
3.成员函数作为友元

*/


//全局函数作为友元
using namespace std;

class People {
	friend void friendvisit(People* p);
public:
	People() {
		m_house = "别墅";
		m_car = "跑车";
	}

public:
	string m_house;

private:
	string m_car;
};


void friendvisit(People* p)
{
	cout << "好朋友来访问你的别墅" << p->m_house << endl;
	cout << "好朋友来访问你的跑车" << p->m_car << endl;   //错误消失
}
int main()
{
	People p;
	friendvisit(&p);
	return 0;
}





#include <iostream>
#include <string>
#include <algorithm>

//类作为友元
//让一个类取访问另一个类的私有成员
using namespace std;

class People;
class Peoplefriend {
public:
	Peoplefriend() {

	}

	void vist(People* p);

};


class People {
	friend class Peoplefriend;  
public:

	People() {
		m_house = "别墅";
		m_car = "跑车";
	}
public:
	string m_house;

private:
	string m_car;
};

void Peoplefriend::vist(People* p)
{
	cout << p->m_house << endl;
	cout << p->m_car << endl;  //friend class Peoplefriend;  
}

int main()
{
	People p;
	Peoplefriend pf;
	pf.vist(&p);
	return 0;
}



#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

//成员函数作为友元

class People;

class Peoplefriend{
public:
	Peoplefriend() {
	}

	void vistall(People* p);
	void vistpub(People* p);

};
class People {
	//friend class Peoplefriend;
	friend void Peoplefriend::vistall(People* p);
public:
	People() {
		m_house = "别墅";
		m_car = "跑车";
	}
public:
	string m_house;

private:
	string m_car;

};


void Peoplefriend::vistall(People* p) {
	cout << p->m_house << endl;
	cout << p->m_car << endl;
}
void Peoplefriend::vistpub(People* p) {
	cout << p->m_house << endl;

}

void vistpub(People* p);
int main()
{
	People p;
	Peoplefriend pf;
	pf.vistall(&p);
	pf.vistpub(&p);
	return 0;
}
```    


## 运算符重载
**加号运算符重载：**
```c++
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

class Maker {
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	//写出成员函数，那只需要一个参数，这个参数是加号的右边
	Maker operator+(Maker &m2)
	{
		Maker temp(this->id + m2.id, this->age + m2.age);
		return temp;
	}
public:
	int id;
	int age;
};

//全局方式
//Maker operator+(Maker& p1, Maker& p2)
//{
//	Maker temp(p1.id + p2.id, p1.age + p2.age);
//	return temp;
//}

void test1()
{
	Maker m1(1, 20);
	Maker m2(2, 3);

	Maker m3 = m1 + m2;

	cout << "id:" << m3.id << "age" << m3.age << endl;
	Maker m4 = m1 + m2 + m3;
	cout << "id:" << m4.id << "age" << m4.age << endl;
}

int main()
{
	test1();
	return 0;
}
```   

**右移运算符重载：**
```c++
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

void test1()
{
	int a;
	cin >> a;
	cout << a << endl;

}

class Maker {
	friend istream & operator>>(istream& in, Maker& m);
public:
	Maker(string name, int age)
	{
		this->name = name;

		this->age = age;
	}

	int getAge()
	{
		return age;
	}
private:
	string name;
	int age;

};

istream &operator>>(istream& in, Maker &m)
{
	in >> m.age;
	in >> m.name;

	return in;
}

void test2()
{
	Maker m("悟空", 15);

	Maker m2("悟空2", 13);

	cin >> m>>m2;

	cout << m.getAge() << endl;
	cout << m2.getAge() << endl;
}
int main()
{
	test2();
	return 0;
}
```

## 06.赋值运算符重载（重点）

1.编译器默认给类提供了一个默认的赋值运算符重载函数

2.默认的赋值运算符重载函数进行了简单的赋值操作

```
class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker m1(10, 20);
	Maker m2;

	m2 = m1;//赋值操作
	//默认的赋值运算符重载函数进行了简单的赋值操作
	cout << m2.id << " " << m2.age << endl;
}
```

3.当类有成员指针时，然后在构造函数中申请堆区空间，在析构函数中释放堆区空间，会出现同一块空间释放2次，然后内存泄漏，所以要重写赋值运算符重载函数

```
class Student
{
public:
	Student(const char *name)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
	}
	//防止浅拷贝
	Student(const Student &stu)
	{
		pName = new char[strlen(stu.pName) + 1];
		strcpy(pName, stu.pName);
	}
	//重写赋值运算符重载函数
	Student &operator=(const Student &stu)
	{
		//1.不能确定this->pName指向的空间是否能装下stu中的数据，所以先释放this->pName指向的空间
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}

		//2.申请堆区空间，大小由stu决定
		this->pName = new char[strlen(stu.pName) + 1];
		//3.拷贝数据
		strcpy(this->pName, stu.pName);

		//4.返回对象本身
		return *this;
	}	

	~Student()
	{
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

	void printStudent()
	{
		cout << "Name:" << pName << endl;
	}
public:
	char *pName;
};

void test02()
{
	Student s1("悟空");
	Student s2("小林");

	s1.printStudent();
	s2.printStudent();

	s1 = s2;//赋值操作

	s1.printStudent();
	s2.printStudent();
	
	//复数运算不会出错
	//s1 = s2 = s3;
}
```

4.赋值运算符重载函数中，为什么要返回引用

```
void test03()
{
	Student s1("a");
	Student s2("b");
	Student s3("c");

	s1 = s2 = s3;//s3赋值s2,s2赋值给s1

	cout << &(s2 = s3) << endl;
	cout << &s2 << endl;
	//如果返回的是值，s2=s3这个表达式会产生一个新的对象
	//s1=s2=s3,赋值运算符本来的寓意，是s3赋值s2,s2赋值给s1
	//也就是说s2=s3这个表达式要返回s2这个对象，所以要返回引用

}
```



## 07.关系运算符重载（了解）

```
class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}

	bool operator==(Maker &m)
	{
		if (this->id == m.id && this->age == m.age)
		{
			return true;
		}
		return false;
	}


	bool operator!=(Maker &m)
	{
		if (this->id != m.id || this->age != m.age)
		{
			return true;
		}
		return false;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker p1(1, 20);
	Maker p2;

	if (p1 == p2)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	if (p1 != p2)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}
}
```



## 08.前置加加和后置加加运算符重载（重点难点）

```
class Maker
{
	friend ostream &operator<<(ostream &out, Maker &m);
public:
	Maker(int a)
	{
		this->a = a;
	}
	//重载前置加加
	Maker &operator++()
	{
		++this->a;
		return *this;
	}

	//后置加加,
	Maker operator++(int)//占位参数，必须是int
	{
		//后置加加，先返回，后加加
		Maker tmp(*this);//1.*this里面的值a是等于2
		++this->a;//这个对象的a等3
		return tmp;
	}
private:
	int a;
};

ostream &operator<<(ostream &out, Maker &m)
{
	out << m.a << endl;
	return out;
}

void test02()
{
	Maker m1(1);
	cout << m1 << endl;//1
	cout << ++m1 << endl;//2
	//++(++m1);
	cout << m1++ << endl;//2  这里返回的拷贝的tmp对象
	cout << m1 << endl;//3 这里返回的是++this->a的对象

	//同等条件下，优先使用前置加加，不需要产生新的对象和调用拷贝构造

}
```



## 09.数组下标运算符重载（重点）

```
MyArray.h
class MyArray
{
public:
//重写赋值运算符重载函数
	MyArray&operator=(const MyArray &m);

	//要能当左右值
	int &operator[](int index);

};

MyArray.cpp
//重写赋值运算符重载函数
MyArray&MyArray::operator=(const MyArray &m)
{
	cout << "赋值函数" << endl;
	//1.释放原来的空间
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}
	this->mCapacity = m.mCapacity;
	this->mSize = m.mSize;
	//2.申请空间，大小由m决定
	this->pArray = new int[m.mCapacity];
	//3.拷贝数据
	cout << "this->mSize:"<<this->mSize << endl;
	for (int i = 0; i < this->mCapacity; i++)
	{
		this->pArray[i] = m.pArray[i];
	}

	return *this;
}

//要能当左右值
int &MyArray::operator[](int index)
{
	/*
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	*/
	//赋值时，加加
	
	
	if (this->mSize <=index)
	{
		this->mSize++;
	}
	
	return this->pArray[index];
}

数组下标重载.cpp
void test02()
{
	MyArray arr;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	MyArray arr2;
	arr2 = arr;
	for (int i = 0; i < 20; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << arr2.Size() << endl;
}
```

## 01.智能指针类（重点）

1.智能指针类是管理另一个类的对象的释放

```

class Maker
{
public:
	Maker()
	{
		cout << "无参构造" << endl;
	}
	void printMaker()
	{
		cout << "hello Maker" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

class SmartPoint
{
public:
	SmartPoint(Maker *m)
	{
		this->pMaker = m;
	}

	~SmartPoint()
	{
		if (this->pMaker != NULL)
		{
			cout << "SmartPoint 析构函数" << endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
private:
	Maker *pMaker;
};
void test01()
{
	Maker *p = new Maker;

	SmartPoint sm(p);//栈区，会调用析构函数
	//当test01()函数结束时，会调用SmartPoint的析构函数，
	//在这析构函数中delete了Maker的对象，会调用Maker的析构函数

}

```

2.指针运算符重载

```
	//重载指针运算符
	Maker *operator->()
	{
		return this->pMaker;
	}
	
	
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);
	//sm-> ==> pMaker->
	sm->printMaker();


}
```

3.重载星花

```
//重载星花
	Maker &operator*()
	{
		return *pMaker;
	}
	
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);

	(*sm).printMaker();

}
```



## 02.重载函数调用符号（重点）

1.类里有重载函数调用符号的类实例化的对象也叫仿函数

2.仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）

```
//一个类如重载了函数调用符号，那么这个类实例化出的对象也叫仿函数
//仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）
class Maker
{
public:
	Maker()
	{
		name = "翠花";
	}
	void printMaker()
	{
		cout << name + "你好漂亮" << endl;
	}

	void operator()()
	{
		cout << "hello" << endl;
	}

	void operator()(int v1,int v2)
	{
		cout << v1+v2 << endl;
	}
public:
	string name;
};


void test()
{
	Maker func;

	func();//看起来像函数，其实func是对象

	func(10, 20);

	func.printMaker();
}
```



## 03.其他重载的重载（了解）

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	Maker()
	{
		a = 0;
	}

	void SetA(int val)
	{
		a = val;
	}
	//没有返回值，也没有void
	operator bool()
	{
		if (a <= 0)
		{
			return false;
		}

		return true;
	}

	bool operator!()
	{
		if (a <= 0)
		{
			return true;
		}

		return false;
	}

	operator int()
	{
		return 10;
	}
public:
	int a;
};

void test()
{
	Maker m;
	m.SetA(10);
	if (m)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	if (!m)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	int b = (int)m;
	cout << b << endl;
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}


```



## 04.字符串类（了解）

1.目的：设置一个类，类似于string的效果



## 05.继承的作用（重点）

1.代码复用，2.扩展类的功能

## 06.继承方式（重点）

1.继承方式，公有继承，私有继承，保护继承

2.子类对从父类继承过来的成员的权限

1.公有继承

​	1.父类的公有属性成员，到子类还是公有
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是保护	

2.保护继承

​	1.父类的公有属性成员，到子类是保护
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是保护	

3.私有继承

​	1.父类的公有属性成员，到子类还是私有
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是私有	

## 07.继承中的对象模型工程（了解）

1.打开开发者命令程序

2.进入文件所在的目录 cd 目录所在

​	如果要跨盘符，还要再次输入  盘符名:

3.输入命令:cl /d1reportSingleClassLayout类名 文件名

## 08.继承中的构造和析构（重点）

1.继承中的构造和析构调用顺序

先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之

```
class Father
{
public:
	Father()
	{
		cout << "Father构造函数" << endl;
	}
	~Father()
	{
		cout << "Father析构函数" << endl;
	}
};

class Son :public Father
{
public:
	Son()
	{
		cout << "Son构造函数" << endl;
	}
	~Son()
	{
		cout << "Son析构函数" << endl;
	}
};
//先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之
void test01()
{
	Son s;
}
```

2.继承和组合混搭

先调用父类的构造，然后调用成员对象的构造，最后调用本身的构造，析构函数调用顺序反之

```
class A
{
public:
	A()
	{
		cout << "A 的构造" << endl;
	}
	~A()
	{
		cout << "A 的析构" << endl;
	}
public:

};

class B
{
public:
	B()
	{
		cout << "B 的构造" << endl;
	}
	~B()
	{
		cout << "B 的析构" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C 的构造" << endl;
	}
	~C()
	{
		cout << "C 的析构" << endl;
	}
};

class D:public A
{
public:
	D()
	{
		cout << "D 的构造" << endl;
	}
	~D()
	{
		cout << "D 的析构" << endl;
	}
public:
	B b;
	C c;
};
void test02()
{
	D d;
}
```



## 09.继承中同名成员的处理方法（重点）

1.通过父类名加作用域来访问，当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员

```
//当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员
void test()
{
	Son s;
	cout << s.a << endl;
	cout << sizeof(Son) << endl;//8
	//通过父类名加作用域来访问
	cout<<s.Father::a << endl;
}
```

2.当子类有和父类同名函数时，父类的所有重载函数都会被隐藏

```
class Father
{
public:
	Father()
	{
		a = 10;
	}

	void func()
	{
		cout << "Father func" << endl;
	}
	void func(int a)
	{
		cout << "Father func(int a)" << endl;
	}

	void func(int a,int b)
	{
		cout << "Father func(int a,int b)" << endl;
	}


public:
	int a;
};
class Son :public Father
{
public:
	Son()
	{
		a = 20;
	}
	void func()
	{
		cout << "Son func" << endl;
	}
public:
	int a;
};

//当子类有和父类同名函数时，父类的所有函数重载都会被隐藏
void test02()
{
	Son s;
	s.func();
	//s.func(10);err
	//s.func(10, 20);err
}
```



## 10.继承中静态成员特性（了解）

1.静态成员可以被继承

2.继承中的静态成员变量一样会被同名的子类成员变量隐藏

3.继承中的静态成员函数中，当子类有和父类同名静态函数时，父类的所有重载静态函数都会被隐藏

4.改变从基类继承过来的静态函数的某个特征，返回值或者参数个数，将会隐藏基类重载的函数

5.静态成员函数不能是虚函数

6.从父类继承过来的静态成员变量是父类的静态成员变量

## 11.非自动继承的函数（了解）

1.构造，析构，赋值函数都不能被继承

## 12.多继承（了解）

1.多继承是一个类有两个以上的父类

2.多继承的问题是，当父类中有同名成员时，子类中会产生二义性问题

## 13.菱形继承（重点）

1.虚基类

被虚继承的基类叫虚基类

2.菱形继承的问题

两个父类中有祖类中的数据，然后子类会继承两个父类的数据，会产生二义性问题

3.虚继承

父类虚继承祖类，用virtual关键字

4.虚继承的原理

​	1.编译给类添加了一个指针，指针指向类似于表的组织，该表记录了该指针距离变量的偏移量

​	2.当子类多继承两个父类，那么只有一份成员变量，然后有两个指针，只有一份成员变量，所以不会产生二义性

## 14.动态联编和静态联编（重点难点）

1.静态联编

编译器会根据函数调用的对象类型,在编译阶段就确定函数的调用地址，这就是静态联编（早绑定）

2.虚函数

在普通成员函数前面加virtual，该函数变为虚函数，是告诉编译器这个函数要晚绑定

3.动态联编

在运行阶段才确定调用哪个函数（晚绑定），

4.动态编译的作用，可以晚绑定函数调用地址，这样可以扩展功能，不修改前面的代码的基础上进行项目的扩充

5.类型转换问题

​	1.子类转换成父类（向上转换）：编译器认为指针的寻址范围缩小了，所以是安全的

​	2.父类转换成子类（向下转换）；编译器认为指针的寻址范围扩大了，不安全


## 01.多态（重点难点）

##### 1.什么是多态：

同一个操作作用于不同的对象，可以有不同的解释，会产生不同的效果，这就是多态

```
class People
{
public:
	//虚函数
	virtual void Mypro()
	{

	}
};

class xishi :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约西施" << endl;
	}
};

class wangzhaojun :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约王昭君" << endl;
	}
};



class diaochan :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约貂蝉" << endl;
	}
};

class yangguifei :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约杨贵妃" << endl;
	}
};


//同一个操作
void doLogin(People *pro)
{
	pro->Mypro();//产生不同的效果
}

void test()
{
	People *pro = NULL;
	pro = new xishi;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new wangzhaojun;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new diaochan;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new yangguifei;
	doLogin(pro);//不同的对象
	delete pro;
}
```



##### 2.多态有什么用

1.可以解决项目中的紧耦合问题,提供程序的可扩展性

2.应用程序不必为每一个子类的功能调用编写代码，只需要对抽象的父类进行处理

##### 3.多态发生的三个条件

1.有继承。2.重写父类的虚函数。3.父类指针指向子类对象

## 02.多态的实现原理（重点难点）

```
class Animal
{
public:
	virtual void speak()
	{
		cout << "Anima speak()" << endl;
	}
	
};
class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	cout << sizeof(Animal) << endl;

	Animal *animal = new Dog;
	animal->speak();
}
```



## 03.纯虚函数和抽象类(重点)

1.依赖倒转

业务层依赖抽象层，实现层依赖抽象层

```
//抽象层
class rule
{
public:
	virtual int getnum(int a,int b)
	{
		return 0;
	}
};

//实现层
class plus_rule :public rule
{
public:
	virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
	{
		return a+b;
	}
};




//业务层
int doLogin(rule *cal)
{
	
	int a = 10;
	int b = 20;
	

	int ret=cal->getnum(a, b);//依赖抽象层

	return ret;

}

void test()
{
	rule *r = NULL;
	r = new plus_rule;
	cout << doLogin(r) << endl;
	delete r;

}
```

2.开闭原则

对修改源代码关闭，对扩展新功能开发

```
//抽象层
class rule
{
public:
	virtual int getnum(int a,int b)
	{
		return 0;
	}
};

//实现层
class plus_rule :public rule
{
public:
	virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
	{
		return a+b;
	}
};
//扩展新功能
class miux_rule :public rule
{
public:
	virtual int getnum(int a, int b)
	{
		return a - b;
	}
};


//业务层
int doLogin(rule *cal)
{
	
	int a = 10;
	int b = 20;
	

	int ret=cal->getnum(a, b);//依赖抽象层

	return ret;

}

void test()
{
	rule *r = NULL;
	r = new plus_rule;
	cout << doLogin(r) << endl;
	delete r;
	//增加的代码
	r = new miux_rule;
	cout << doLogin(r) << endl;
	delete r;

}
```

3.纯虚函数

```
class rule
{
public:
	//纯虚函数
	virtual int getnum(int a, int b) = 0;
};
```

4.抽象类

1.有纯虚函数的类叫抽象类，不能实例化对象

```
//有纯虚函数的类叫抽象类，不能实例化对象
class rule
{
public:
	//纯虚函数
	virtual int getnum(int a, int b) = 0;
};

void test02()
{
	//抽象类不能实例化对象
	//rule r;
}
```

2.如果子类继承抽象类，子类必须实现抽象类的所有纯虚函数，不然子类也变为抽象类

```
class Maker
{
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
};

class Son :public Maker
{
public:
	virtual void func1()
	{

	}
	virtual void func2()
	{

	}
};

void test03()
{
	Son s;
}
```



## 04.接口的定义（了解）

1.所谓的接口，即将内部实现细节封装起来，外部用户用过预留的接口可以使用接口的功能而不需要知晓内部具体细节。C++中，通过类实现面向对象的编程，而在基类中只给出纯虚函数的声明，然后在派生类中实现纯虚函数的具体定义的方式实现接口，不同派生类实现接口的方式也不尽相同

```
//抽象类
class Father
{
public:
	virtual void func1() = 0;//接口的声明
	virtual void func2(int a) = 0;
	virtual void func3(int a,int b) = 0;
};

class Son :public Father
{
public:
	virtual void func1()//接口的实现
	{

	}
	virtual void func2(int a)
	{

	}
	virtual void func3(int a, int b)
	{

	}
};
```



## 05.模版方法模式（重点）

1.在抽象类中确定好函数的调用顺序

```
class Drink
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//导入杯中
	virtual void PourInCup() = 0;
	//加点辅料
	virtual void addSonm() = 0;

	//模版方法,把调用函数的顺序确定下来
	void func()
	{
		Boil();
		Brew();
		PourInCup();
		addSonm();
	}
};
```



## 06.虚析构函数和纯虚析构函数（重点）

1.虚析构函数是为了解决基类指针指向派生类对象，并用基类指针释放派生类对象

```
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}
};

class Son :public Animal
{
public:
	Son()
	{
		cout << "Son的构造" << endl;
		pName = new char[64];
		memset(pName, 0, 64);
		strcpy(pName, "如花");
	}

	~Son()
	{
		cout << "Son的析构" << endl;
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

public:
	char *pName;
};

void test()
{
	Animal *animal = new Son;
	delete animal;
}
```

2.纯虚析构函数，有纯虚析构函数的类是抽象类，不能实例化对象

注意：纯虚析构函数需要在类外实现

```
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	/*virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}*/

	//纯虚析构函数，纯虚析构函数需要在类外实现
	virtual ~Animal() = 0;
};

//在类外实现纯虚析构函数
Animal::~Animal()
{
	cout << "Animal的纯虚析构" << endl;
}
```

3.虚析构函数和纯虚析构函数的区别：

1.有纯虚析构函数的类是抽象类，不能实例化对象，而且要在类外实现

2.虚析构函数不需要在类外实现

## 07.多态案例_动物园（重点）

1.创建动物基类

```
class Animal
{
public:
	virtual void speak() = 0;
};
```

2.创建动物

```
class Dog :public Animal
{
public:
	Dog(string name)
	{
		this->name = name;
	}
	virtual void speak()
	{
		cout << "小狗" << name << "汪汪汪" << endl;
	}
private:
	string name;
};

class Dark :public Animal
{
public:
	Dark(string name,string type)
	{
		this->name = name;
		this->type = type;
	}
	virtual void speak()
	{
		cout <<type<<"品牌的"<< "小鸭" << name << "嘎嘎嘎" << endl;
	}
private:
	string name;
	string type;
};

class Tiger :public Animal
{
public:
	Tiger(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	virtual void speak()
	{
		cout << age << "岁" << "老虎" << name << "嗷嗷嗷" << endl;
	}
private:
	string name;
	int age;

};
```

3.创建动物园

```
class Zoo
{
public:
	Zoo()
	{
		mCapacity = 1024;
		mSize = 0;
		//申请空间，存储Animal*的空间，指针数组
		this->p = new Animal*[mCapacity];
	}

	//增加动物
	int AddAnimal(Animal* animal)
	{
		if (mCapacity == mSize)
		{
			return -1;
		}
		//把指针存储到指针数组
		this->p[mSize] = animal;
		mSize++;

		return 0;
	}

	void StartSpeak()
	{
		for (int i = 0; i < mSize; i++)
		{
			p[i]->speak();
		}
	}

	//析构函数
	~Zoo()
	{
		//先释放指针数组中指针指向的堆区空间
		for (int i = 0; i < mSize; i++)
		{
			if (p[i] != NULL)
			{
				delete p[i];
				p[i] = NULL;
			}
		}

		//释放指针数组
		delete[] p;
		p = NULL;
	}


private:
	Animal* *p;
	int mCapacity;//容量
	int mSize;

};

```

4.使用

```
void test()
{
	//创建动物园
	Zoo *zoo = new Zoo;

	//添加动物
	zoo->AddAnimal(new Dog("晋三"));
	zoo->AddAnimal(new Dark("黑鸭", "周黑鸭"));
	zoo->AddAnimal(new Tiger("三胖", 35));

	zoo->StartSpeak();

	//烧了动物园
	delete zoo;
}
```

## 08.父类引用子类对象

```
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal speak()" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	Animal &animal = Dog();
	animal.speak();

	Animal* dog = new Dog();
	Animal* &an = dog;
	an->speak();
	delete dog;
}
```



## 09.重写，重载，重定义（隐藏）

1.重载，同一作用域的同名函数

2.重写（覆盖）:

​	1. 有继承

​	2.子类（派生类）重写父类（基类）的virtual函数

​	3.函数返回值，函数名字，函数参数，必须和基类中的虚函数一致

3.重定义（隐藏）

​	1. 有继承

​	2.子类（派生类）重新定义父类（基类）的同名成员（非virtual函数）
