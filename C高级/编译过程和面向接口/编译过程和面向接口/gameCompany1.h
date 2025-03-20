#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Player
{
	char name[64];  //姓名
	int level;   //等级
	int exp;   //经验

};
//初始化游戏   //参数1  人物指针     参数2   人物姓名
void INIT_GAME_COMPANY1(void** player, char* name);

//核心战斗  如果战斗胜利 返回1  失败  返回0       参数1   玩家      参数2   副本难度
int FIGHT_GAME_COMPANY1(void* player, int gameDiff);

//查看玩家信息
void  PRINT_GAME_COMPANY1(void* player);


//离开游戏
void EXIT_GAME_COMPANY1(void* player);

//判断玩家是否胜利
int IsWin(int winRate,int diff);