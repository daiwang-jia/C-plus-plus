#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameCompany1.h"

//��ʼ����Ϸ   //����1  ����ָ��     ����2   ��������
typedef void(*INIT_GAME)(void** plarer, char* name);

//����ս��  ���ս��ʤ�� ����1  ʧ��  ����0       ����1   ���      ����2   �����Ѷ�
typedef int(*FIGHT_GAME)(void* player, int gameDiff);

//�鿴�����Ϣ
typedef void(*PRINT_GAME)(void* player);


//�뿪��Ϸ
typedef void(*EXIT_GAME)(void* player);

//�׷�����ʵ��
void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME  printGame, EXIT_GAME exitGame)
{
	//��ʼ����Ϸ
	void* player = NULL;
	printf("��������ҵ�������\n");
	char buf[1024];
	scanf("%s", buf);

	init(&player, buf);

	int diff = -1;

	//ս��
	printf("��ѡ����Ϸ�Ѷȣ�\n");

	printf("1����\n");
	printf("2���е�\n");
	printf("3������\n");

	scanf("%d", &diff);

	int ret = fight(player, diff);
	if (ret == 0)
	{
		printf("��Ϸ�������ٽ�����\n");
	}
	else
	{
		printf("��ϲʤ��\n");

		//�鿴��ҵ�ǰ״̬
		printf("��ҵ�ǰ״̬��\n");
		printGame(player);
	}

	//�˳���Ϸ
	exitGame(player);
}

int main()
{
	playGame(INIT_GAME_COMPANY1,FIGHT_GAME_COMPANY1,PRINT_GAME_COMPANY1,EXIT_GAME_COMPANY1);
	return 0;
}