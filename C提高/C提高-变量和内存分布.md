# <center>变量和内存分布</center>  
**typedef的使用** 
1.typedef 可以简化struct关键字   
```c 

struct Person
{
	char name[64];
	int age;
};
typedef struct Person MyPerson;

void test01()
{
	struct Person p1 = { "张三",18 };

	MyPerson p2 = { "李四",19 };
}
```
```c 
typedef struct Person
{
	char name[64];

	int age;
}MyPerson;

void test01()
{
	struct Person p1 = { "张三",18 };

	MyPerson p2 = { "李四",19 };
}
```  
2.区分数据类型
```c
void test02()
{
	char* p1, p2;
	//p1-char*    p2-char
	typedef char* PCHAR;
	PCHAR p1, p2;
	//p1,p2--char*

	char* p1, * p2;
}
```   
3.提高移植性
```c
typedef long long MY_INT;  //typedef int MY_INT;
void test03()
{
	MY_INT a = 10;

	MY_INT b = 10;
}
```   


**void**  




