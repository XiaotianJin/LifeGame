/*************************************
版本 0.3
仅供交流学习之用
在未经作者（金笑天、赵志贤）允许情况下
不得用于任何商业用途
最后一次修改：
2016年9月3日01:44:54
于 武汉理工大学
*************************************/

//V0.1更新内容：
//开始编写程序

//V0.2更新内容： 
//将游戏地图类分离，并单独设计了初始化函数 

//V0.3更新内容：
//加入了文件初始化方法

#include<iostream>
#include<windows.h>
#include<conio.h>

#include"LIFEGAME_H.h"

using namespace std;

void ClearScreen()
{
	system("cls");
}

void Welcome()
{
	cout << "LifeGame	Ver0.3" << endl;
	cout << "Author: WHUT SEZY1402 金笑天，赵志贤" << endl;
	system("pause");
}

bool init(GAME& toInit)
{
	bool isInitSucceed = false;

	while (!isInitSucceed)
	{
		ClearScreen();



		isInitSucceed = toInit.OnGameStart();

		if (!isInitSucceed)
		{
			cout << "ERROR:Initial failed! press Y to reInit, press other keys to quit." << endl;
		}

		char input;
		input = getch();
		if (!(input == 'y' || input == 'Y'))
		{
			break;
		}
	}



	return isInitSucceed;
}

int main()
{
	Welcome();

	LIFEGAME game;

	if (init(game))
	{
		game.RunGame();
	}


	//GameInit(c, r);

	return 0;
}