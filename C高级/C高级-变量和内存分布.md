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

**静态变量和全局变量**   

静态变量：   
1.程序运行前分配   
2.生命周期在程序运行结束  死亡     
3.默认属于内部链接属性，在当前文件中使用   

```c
static int a = 10;   //全局作用域

void test1()
{
	static int b = 10;  //   局部作用域  只能在函数中使用
}
```  
全局变量：     
1.默认在C语言下 全局变量前加了关键字 extern    
2.属于外部链接属性   
```c
extern int b = 100;
int main()
{
	extern int G_b;
	G_b = 100;

	return 0;
}
```       


**修饰的常量**       
const修饰的常量
```c
//全局const常量
const int a = 10;  //全局const常量  放在常量区中，受其保护

void test1()
{
	//a = 100;  //直接修改失败  

	//间接修改
	int* p = &a;
	*p = 100;
	printf("%d\n", a);
}

int main()
{
	test1();  //失败
	return 0;
}
``` 
```c
//局部const修饰常量
void test2()
{
	const  int b = 10;
	//b = 100;  //直接修改失败

	//间接修改
	int* p = &b;
	*p = 100;
	printf("%d\n", b);
}

int main()
{
	test2();  //修改成功，放在栈上
	return 0;
}
```  

**字符串常量**     
字符串常量是可以共享的，vs下将相同的字符串常量看成同一个
```c
void test3()
{
	char* p1 = "hello  world";
	char* p2 = "hello  world";
	char* p3 = "hello  world";
}

int main()
{
	test3();

	return 0;
}
```  
字符串常量是否可以修改
```c
//VS下不可以
void test4()
{
	char* p1 = "hello wirld";

	p1[0] = 'w';   //无法修改
}
``` 

**宏函数**   

//宏函数注意：保证运算的完整性
//宏函数使用场景：频繁短小的函数，封装为宏函数
///优点：以空间换时间
```c
#define MYADD(x,y)  ((x)+(y))
int main()
{
	int a = 10;
	int b = 90;
	printf("a+b=%d\n", MYADD(a, b));  //100
	//printf("a+b=%d\n", MYADD(a, b)*20); // 10+90*20=1810
	//解决：加括号
	printf("a+b=%d\n", MYADD(a, b) * 20);  //2000

	return 0;
}
```  

**函数的调用流程**      
主调函数和被调函数要有一致约定，才能正确调用函数，这个约定称为调用惯例         
c/c++默认调用惯例：cdcel         
内容：         
出栈方    主调函数       
参数传递顺序   从右往左      
名称修饰    _+函数名     


**函数变量传递分析**      
```c
void B()
{

}
void A()
{
	int a;  //只能在A和B中可以使用
	B();
}
int main()
{
	int a;  //在main函数和A，B中都可以使用

	A();
	return 0;
}
```


**栈的生长方向**  
栈底 高地址      
栈顶 低地址          
```c
//栈的生长方向
void test1()
{
	int a = 10;
	int b = 10;
	int c = 10;
	int d = 10;
	printf("%d\n", &a);  //栈底  高地址
	printf("%d\n", &b);
	printf("%d\n", &c);
	printf("%d\n", &d);  //栈顶  低地址
}
int main()
{

	test1();
	return 0;

}
```   

**内存存储方式**   
高位字节 高地址       
低位字节 低地址        
```c
void test2()
{
	int a = 0x11223344;
	char* p = &a;

	printf("%x\n", *p);  //44 低位字节

	printf("%x\n", *(p + 1));  //33 高位字节
}

int main()
{
	test2();

	return 0;
}
```










