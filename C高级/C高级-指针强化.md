**空指针和野指针** 
不能向空指针和野指针指向的内存进行操作       
```c
void test1()
{
	char* p = NULL;
	//给p指向的内存空间区域拷贝内容
	strcpy(p, "11111");   //err

	char* q = 0x1122;
	//给q指向的内存区域拷贝
	strcpy(q, "2222");  //err
}

int main()
{
	test1();

	return 0;
}
```

**野指针的三种情况**      
```c
int* dowork()
{
	int a = 10;
	int* p = &a;
	return p;

}
void test2()
{
	//1.声明未初始化指针
	int* p;

	printf("%d\n", *p);


	//2.malloc后free的指针
	int* p = malloc(4);
	*p = 100;
	printf(" % d\n", *p);

	free(p);
	printf("%d\n", *p);
	//*p=100;  不要去操作野指针
	p = NULL;  //将野指针置空


	//3.指针变量超出作用域
	int* p2 = dowork;
	printf("%d\n", *p2);

	free(p);
	//空指针可以重复释放，野指针奴可以
}


int main()
{
	test2();

	return 0;
}
```   

**指针的步长**     
```c
//1.指针变量+1后跳跃的字节数
void test1()
{
	char* p = NULL;

	printf("%d\n", p);  //0
	printf("%d\n", p+1);  //1


	double* p2 = NULL;

	printf("%d\n", p2);  //0
	printf("%d\n", p2 + 1);  //8
}

//2.在解引用时取出的字节数
test2()
{
	char buf[1024] = { 0 };
	int a = 1000;
	memcpy(buf+1, &a, sizeof(int));

	char* p = buf;
	printf("%d\n", *(int*)(p+1));

}
int main()
{
	test1();
	test2();

	return 0;
}
```  
指针步长练习：    
```c
#include <stddef.h>   //offsetof的头文件
struct Person
{
	char a;  //0-3
	int b;  //4-7
	char buf[64];  //8-71
	int d;  //72-75
};

void test3()
{
	struct Person p = { 'q',10,"hello world",10000 };

	//p中的d属性偏移量是多少
	printf("d的偏移量是为：%d\n", offsetof(struct Person, d));  //72

	printf("d的值为：%d\n", *(int*)((char*)&p + offsetof(struct Person, d)));
}

int main()
{
	test3();
	return 0;
}
```  


**指针的意义-间接赋值**        
成立的三大条件：        
1. 2个变量  普通变量+指针变量    实参+形参        
2. 建立关系
3. 通过*操作指针指向的空间         
```c
void test1()
{
	//1.两个变量
	int a = 10; 
	int* p = NULL;
	//2.建立关系
	p = &a;
	//3.通过*操作
	*p = 1000;

}

void changeVaule(int *p)
{
	*p = 1000;
}
void test2()
{
	int a = 10;

	changeVaule(&a);

	printf("%d\n", a);

}

int main()
{
	test2();
	return 0;
}
```    

**指针做函数参数的输入特性**      
输入特性:                     
在主调函数分配内存，被调函数调用         
输出特性:       
在被调函数中分配内存        
```c
//在主调函数分配内存，被调函数调用 
void func(char* p)
{
	strcpy(p, "hello");
}
void test1()
{
	//在栈上分配内存
	char buf[1024] = { 0 };
	func(buf);

	printf("%s\n", buf);
}

void printString(char *p)
{
	printf("%s\n", p);
}
void test2()
{
	//在堆区分配内存
	char* p = malloc(sizeof(char) * 64);
	memset(p, 0, 64);

	strcpy(p, "hello");

	printString(p);

	free(p);
	p = NULL;
}

//在被调函数分配内存
void allocateSpace(char **p)
{
	char *temp=malloc(sizeof(char)*64);
	memset(temp,0,64);
	strcpy(temp,"hello");

	*p=temp;
}
void test3()
{
	char *p=NULL;
	allocateSpace(&p);

	printf("%s\n",p);

	free(p);
	p = NULL;
}
int main()
{
	test1();  //  hello

	test2();  //hello

	test3();
	return 0;
}
```    

**字符串注意事项**        
```c
void test1()
{
	//1.字符串结尾要加\0
	char str1[] = { 'h','e','l','l','o' ,'\0'};
	printf("%s\n", str1);  //hello

	char str2[100]= { 'h','e','l','l','o' ,'\0' };
	printf("%s\n", str2);   //hello

	char str3[] = "hello";
	printf("%s\n", str3);   // hello
	printf("%d\n", sizeof(str3));    //6
	printf("%d\n", strlen(str3));  //5

	char str4[100] = "hello";
	printf("%s\n", str4);    //hello
	printf("%d\n", sizeof(str4));   //100
	printf("%d\n", strlen(str4));  //5

	char str5[] = "hello\0world";
	printf("%s\n", str5);    //hello
	printf("%d\n", sizeof(str5));   //12
	printf("%d\n", strlen(str5));  //5

	char str6[] = "hello\012world";
	printf("%s\n", str6);    //hello   world
	printf("%d\n", sizeof(str6));   //12   \012 八进制12---10   ASCII 10- 换行
	printf("%d\n", strlen(str6));  //11  strlen遇到\0换行
}

int main()
{
	test1(); 

	return 0;
}
```  

**字符串练习**       
```c
//1.字符串拷贝

void copystring1(char *dest,char *source)
{
	//利用下标方式拷贝
	int len = strlen(source);
	for (int i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}
	dest[len] = '\0';
}
void copystring2(char* dest, char* source)
{
	//利用指针方式
	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

void copystring3(char* dest, char* source)
{
	while (*dest++ = *source++)
	{

	}
}
void test1()
{
	char* str = "hello world";

	char buf[1024] ;

	//copystring1(buf,str);
	//copystring2(buf, str);
	copystring3(buf, str);
	printf("%s\n", buf);
}

int main()
{
	test1();
	return 0;
}
```
```c
//2.字符串反转
void reversestring1(char* str)
{
	int len = strlen(str);
	int start = 0;  //开始
	int end = len - 1;  //结束
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}

void reversestring2(char* str)
{
	int len = strlen(str);
	char* start = str;  //指向第一个字符的指针

	char* end = str + len - 1;  //指向最后一个字符指针

	while (start < end)
	{
		//交换元素
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;

	}
}
void test2()
{
	char str[] = "abcdef";

	//reversestring1(str);

	reversestring2(str);
	printf("%s\n", str);
}
int main()
{
	test2();

	return 0;
}
```   


**sprintf的使用**     
1.格式化字符串    
```c
void test1()
{
	char buf[1024];
	memset(buf, 0, 1024);
	
	//参数1 格式化后目标字符串
	//参数2 格式化形式
	//参数3 格式化中的参数
	sprintf(buf, "今天是%d年%d月%d日", 2025, 3, 12);

	printf("%s\n", buf);
}

int main()
{
	test1();
	return 0;
}
```  
2.字符串拼接
```c
memset(buf,0,1024);
char str1[]="hello";
char str2[]="world";
int len=sprintf(bbuf,"%s %s",str1,str2);
printf("%s %d\n",buf,len);  // len=11
```
3.数字转字符串
```c
memset(buf,0,1024);
int num=100;
sprintf(buf,"%d",num);
printf("buf:%s\n",buf);

```
设置宽度 8 右对齐 “8d"      |    左对齐   "-8d"              
十六进制   ”0x%x“       
八进制   ”0%o“                



**calloc和realloc**       
realloc机制：       
首先在原有空间查看空闲空间，如果空闲空间足够大，直接在原空间后续开辟新空间大小并且使用,如果不够用，在内存中直接找一块足够大的空间，将原有空间下的数据拷贝到新空间下，并且释放原有空间内存，将新空间的首地址返回         

calloc会清零    
```c
int *p=malloc(sizeof(int)*10);

int *p=realloc(p,sizeof(int)*20);
```
```c
//calloc
void test1()
{
	//malloc不会清零操作
	/*int* p = malloc(sizeof(int) * 10);*/

	//calloc会清空
	//都是在堆区开辟空间
	int *p=calloc(10, sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}
	free(p);
	p = NULL;
}


//realloc
void test2()
{
	//功能重新分配内存
	int* p = malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}
	printf("%d\n", p);

	//重新分配内存
	//参数1 原空间首地址    
	//参数2 新的空间大小
	p=realloc(p, sizeof(int) * 100);
	printf("%d\n", p);
}
int main()
{
	//test1();
	test2();
	return 0;
}
```


