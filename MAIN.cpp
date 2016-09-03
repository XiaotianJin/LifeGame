/*************************************
�汾 0.3
��������ѧϰ֮��
��δ�����ߣ���Ц�졢��־�ͣ����������
���������κ���ҵ��;
���һ���޸ģ�
2016��9��3��01:44:54
�� �人����ѧ
*************************************/

//V0.1�������ݣ�
//��ʼ��д����

//V0.2�������ݣ� 
//����Ϸ��ͼ����룬����������˳�ʼ������ 

//V0.3�������ݣ�
//�������ļ���ʼ������

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
	cout << "Author: WHUT SEZY1402 ��Ц�죬��־��" << endl;
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