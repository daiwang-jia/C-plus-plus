#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gameCompany1.h"

//初始化游戏   //参数1  人物指针     参数2   人物姓名
typedef void(*INIT_GAME)(void** plarer, char* name);

//核心战斗  如果战斗胜利 返回1  失败  返回0       参数1   玩家      参数2   副本难度
typedef int(*FIGHT_GAME)(void* player, int gameDiff);

//查看玩家信息
typedef void(*PRINT_GAME)(void* player);


//离开游戏
typedef void(*EXIT_GAME)(void* player);

//甲方功能实现
void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME  printGame, EXIT_GAME exitGame)
{
	//初始化游戏
	void* player = NULL;
	printf("请输入玩家的姓名：\n");
	char buf[1024];
	scanf("%s", buf);

	init(&player, buf);

	int diff = -1;

	//战斗
	printf("请选择游戏难度：\n");

	printf("1、简单\n");
	printf("2、中等\n");
	printf("3、困难\n");

	scanf("%d", &diff);

	int ret = fight(player, diff);
	if (ret == 0)
	{
		printf("游戏结束，再接再厉\n");
	}
	else
	{
		printf("恭喜胜利\n");

		//查看玩家当前状态
		printf("玩家当前状态：\n");
		printGame(player);
	}

	//退出游戏
	exitGame(player);
}

int main()
{
	playGame(INIT_GAME_COMPANY1,FIGHT_GAME_COMPANY1,PRINT_GAME_COMPANY1,EXIT_GAME_COMPANY1);
	return 0;
}