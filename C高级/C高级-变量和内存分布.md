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
1.void无类型  不能创建变量，因为编译器无法分配空间大小
```c
void test01()
{
	//void a = 10;
}
```  
2.用途： 限定函数返回值  限定函数参数
```c
void func()
{
	return 10;
}
void test02()
{
	printf("%d\n", func());
}
int main()
{
	test02();  /// 发生错误
	return 0;
}
```  
```c
int func(void)
{
	return 10;
}
void test02()
{
	func(10, 10);
}
int main()
{
	test02();  
	return 0;
}
```  
3.void* 万能指针
```c
void test03()
{
	void* p = NULL;
	/*printf("p的内存空间：%d\n", sizeof(p));*/  //8个字节
	int* pInt = NULL;
	char* pChar = NULL;

	pChar = (char*)pInt;  //不同类型指针之间需要强制类型转换才不会报警告
	pChar = p;  //可以不通过强制类型转换
}
int main()
{
	//test02();
	test03();
	return 0;
}
```  

**sizeof**  
1.本质上sizeof不是函数，是一个运算符 + - * /  
```c

void test01()
{
	printf("sizeof int =%d\n", sizeof(int));  //4

	//但是在统计变量时候可以不加小括号
	double d = 3.14;
	printf("sizeof d =%d\n", sizeof d );  //8
}
int main()
{
	test01();

	return 0;
}
```  
2.sizeof的返回值是什么
unsigned int 
```c 
void test02()
{
	//unsigned int a = 10;
	//if (a - 20 > 0)  //运算结果转为usigned int
	//{
	//	printf("大于0\n");
	//}
	//else
	//{
	//	printf("小于0\n");
	//}
	//大于0
	if ((sizeof(int) - 5) > 0)
	{
		printf("大于0\n");
		printf(" % d\n", sizeof(int) - 5);  //-1
		printf(" % u\n", sizeof(int) - 5);
	}
	else
	{
		printf("小于0");
	}
}
int main()
{
	test02();  //大于0

	return 0;
}
```  
3.sizeof的其他用法
统计数组占用内存空间大小
```c
void test03()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	printf("sizeof od arr=%d\n", sizeof(arr));  //32
}
```  

**变量的修改方式**   
```c
void test1()
{
	int a = 10;
	//1.直接修改
	a = 20;

	//2.间接修改
	int* p = &a;
	//解引用操作
	*p = 200;
	printf("a=%d\n", a);
}
int main()
{
	test1();

	return 0;
}
```
```c
//自定义数据类型练习
struct Person
{
	char a;
	int b;
	char c;
	int d;
};

void test2()
{
	struct Person p1 = { 'a',10,'b',20 };

	//直接修改d属性
	p1.d = 100;
	printf("%d\n", p1.d);

	//间接修改
	/*struct Person* p = &p1;*/
	char* p = &p1;
	/*p->d = 1000;
	printf("%d\n", p1.d);*/
	//printf("%d\n", p);
	printf("%d\n",*(int*)(p+12));
	printf("%d\n", *(int*)((int*)p + 3));
}
int main()
{
	test2();
	return 0;
} 
```  


**内存四区**  

运行之前：预处理，编译，汇编，链接      
代码区:(共享的，只读的)        
数据区(静态变量全局变量，常量，已初始化(data)，未初始化(bss))       

运行之后：      
栈区:先进后出，编译器管理数据开辟和释放，容量有限     
堆区：容量远远大于栈区，手动开辟和释放数据  ，malloc,free    


**栈区注意事项**    

```c
int* func()
{
	int a = 10;  //栈上创建的变量
	return &a;
}
void test1()
{
	int* p = func();
	//a早已经被释放，因此再去操作这块内存是非法操作。
	printf("%d\n", *p);
	printf("%d\n", *p);
}
int main()
{
	test1();
	return 0;
}
```
```c
char* getstring()
{
	char str[] = "hello";
	return str;
}
void test2()
{
	char* p = NULL;

	p = getstring();

	printf("p=%s\n", p);//乱码

}
int main()
{
	test2();
	return 0;
}
```  
1.不要返回局部变量的地址，因为局部变量在函数体执行完毕后会被释放


**堆区使用**     
```c

int * getspace()
{
	int *p=malloc(sizeof(int) * 5);
	if (p == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < 5; i++)
	{
		p[i] = 100 + i;
	}
	return p;
}
void test1()
{
	int* p = getspace();
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", p[i]);
	}
}
int main()
{
	test1();
	system("pause");
	return 0;
}
```

**堆区注意事项**   
1.如果给主调函数中一个空指针分配内存，在被调函数中，利用同级的指针是分配失败的      
解决方法：利用高级指针修饰低级指针       
```c
void allocateSpace(char *p)
{
	char* tmp = malloc(100);
	memset(tmp, 0, 100);
	strcpy(tmp, "hello");
	p = tmp;
}
void test2()
{
	char* p = NULL;
	allocateSpace(p);
	printf("p=%s", p);
}

void allocateSpace2(char** p)
{
	char* tmp = malloc(100);
	memset(tmp, 0, 100);
	strcpy(tmp, "hello");
	*p = tmp;
}

void test3()
{
	char* p2 = NULL;
	allocateSpace2(&p2);
	printf("p2=%s", p2);
}
int main()
{
	test2();  //  p=(null)
	printf("\n");  //p2=hello
	test3();   
	return 0;
}

```









