#include "gameCompany1.h"




//初始化游戏   //参数1  人物指针     参数2   人物姓名
void INIT_GAME_COMPANY1(void** pl, char* name)
{
	struct Player*player=malloc(sizeof(struct  Player));
	if (player == NULL)
	{
		return ;
	}
	*pl = player;

	strcpy(player->name, name);  //给玩家姓名赋值
	player->exp = 0;
	player->level = 0;
	
}

//核心战斗  如果战斗胜利 返回1  失败  返回0       参数1   玩家      参数2   副本难度
int FIGHT_GAME_COMPANY1(void* p, int gameDiff)
{
	struct Player* player = p;

	int addExp = 0;  //给玩家增加经验

	switch (gameDiff)
	{
	case 1:
		//传入胜率，当前难度
		addExp = IsWin(90, 1);
		break;
	case 2:
		addExp = IsWin(50, 2);
		break;
	case 3:
		addExp = IsWin(30, 3);
		break;
	default :
		break;
	}
	//将经验累加在玩家身上
	player->exp += addExp;

	player->level = player->exp / 10;

	if (addExp == 0)
	{
		//战斗失败
		return 0;
	}
	else
	{
		return 1;
	}
}

//判断玩家是否胜利
int IsWin(int winRate, int diff)
{
	//随机1-100
	int random = rand() % 100 + 1;
	if (random <= winRate)
	{
		//胜利
		return diff * 10;
	}
	else
	{
		//失败
		return 0;
	}
}

//查看玩家信息
void  PRINT_GAME_COMPANY1(void* p)
{
	struct Player* player = p;
	printf("玩家<%s>------当前等级<%d>------当前经验<%d>\n", player->name, player->level, player->exp);

}

//离开游戏
void EXIT_GAME_COMPANY1(void* player)
{
	if (player == NULL)
	{
		return;
	}
	free(player);
	player = NULL;
}