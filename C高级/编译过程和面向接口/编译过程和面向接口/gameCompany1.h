#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Player
{
	char name[64];  //����
	int level;   //�ȼ�
	int exp;   //����

};
//��ʼ����Ϸ   //����1  ����ָ��     ����2   ��������
void INIT_GAME_COMPANY1(void** player, char* name);

//����ս��  ���ս��ʤ�� ����1  ʧ��  ����0       ����1   ���      ����2   �����Ѷ�
int FIGHT_GAME_COMPANY1(void* player, int gameDiff);

//�鿴�����Ϣ
void  PRINT_GAME_COMPANY1(void* player);


//�뿪��Ϸ
void EXIT_GAME_COMPANY1(void* player);

//�ж�����Ƿ�ʤ��
int IsWin(int winRate,int diff);