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