#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//获取文件中有效行数
int getfilelines(FILE*file)
{
	if (file == NULL)
	{
		return -1;
	}
	
	char buf[1024];
	int lines = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		lines++;
		//printf("%s\n", buf);
	}
	//将文件光标置首
	fseek(file, 0, SEEK_SET);
	return lines;


}

//将文件中的数据放入到pArray数组中
void readFileData(FILE*file, char **pArray, int len)
{
	if (file == NULL)
	{
		return;
	}
	if (pArray == NULL)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}

	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		//计算开辟的每个字符串大小
		int currentlen = strlen(buf) + 1;//放\0

		//字符串最后字符改为 \0
		buf[strlen(buf) - 1] = '\0';
		//开辟堆区空间
		char * currentP=malloc(sizeof(char) * currentlen);
		//将文件中读取的内容，放入到开辟的空间中
		strcpy(currentP, buf);

		//将开辟空间的数据放入我们维护的数组中
		pArray[index++] = currentP;

		//清空buf
		memset(buf, 0, 1024);
	}
}
void showFileData(char** pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("第%d行的数据为:%s ", i+1,pArray[i]);
	}

}

//释放堆区空间
void freespace(char** pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			printf("%s 被释放了\n", pArray[i]);
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
	free(pArray);
	pArray = NULL;
}

void test1()
{
	//打开文件
	FILE*file=fopen("./test.txt", "r");
	if (file == NULL)
	{
		printf("文件打开失败");
		return;
	}

	//获取有效行数

	int len = getfilelines(file);
	printf("文件的有效行数为：%d\n", len);
	char** pArray = malloc(sizeof(char*) * len);

	//将文件中的数据放入到pArray数组中
	readFileData(file, pArray, len);

	//打印数组
	showFileData(pArray, len);
	printf("\n");
	//释放堆区空间
	freespace(pArray,len);
	pArray = NULL;

	//关闭文件
	fclose(file);
	file=NULL;
}
int main()
{

	test1();
	return 0;
}