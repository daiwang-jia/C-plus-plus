#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��ȡ�ļ�����Ч����
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
	//���ļ��������
	fseek(file, 0, SEEK_SET);
	return lines;


}

//���ļ��е����ݷ��뵽pArray������
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
		//���㿪�ٵ�ÿ���ַ�����С
		int currentlen = strlen(buf) + 1;//��\0

		//�ַ�������ַ���Ϊ \0
		buf[strlen(buf) - 1] = '\0';
		//���ٶ����ռ�
		char * currentP=malloc(sizeof(char) * currentlen);
		//���ļ��ж�ȡ�����ݣ����뵽���ٵĿռ���
		strcpy(currentP, buf);

		//�����ٿռ�����ݷ�������ά����������
		pArray[index++] = currentP;

		//���buf
		memset(buf, 0, 1024);
	}
}
void showFileData(char** pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("��%d�е�����Ϊ:%s ", i+1,pArray[i]);
	}

}

//�ͷŶ����ռ�
void freespace(char** pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			printf("%s ���ͷ���\n", pArray[i]);
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
	free(pArray);
	pArray = NULL;
}

void test1()
{
	//���ļ�
	FILE*file=fopen("./test.txt", "r");
	if (file == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}

	//��ȡ��Ч����

	int len = getfilelines(file);
	printf("�ļ�����Ч����Ϊ��%d\n", len);
	char** pArray = malloc(sizeof(char*) * len);

	//���ļ��е����ݷ��뵽pArray������
	readFileData(file, pArray, len);

	//��ӡ����
	showFileData(pArray, len);
	printf("\n");
	//�ͷŶ����ռ�
	freespace(pArray,len);
	pArray = NULL;

	//�ر��ļ�
	fclose(file);
	file=NULL;
}
int main()
{

	test1();
	return 0;
}