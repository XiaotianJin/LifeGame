#include<vector>
#include<windows.h>
#include<iostream>

#include"LIFEGAME_H.hpp"
#include"CMD_GUI_H.hpp"

using std::vector;

bool LIFEGAME::Update()
{
	int numOfR = gameMap.size();
	int numOfC = gameMap[0].size();

	GAMEMAP tempFrame = gameMap;
	GAMEMAP nextFrame = gameMap;

	int R_availiable = numOfR - 1;
	int C_availiable = numOfC - 1;
	for (int r = 1; r < R_availiable; ++r)
	{
		for (int c = 1; c < C_availiable; ++c)
		{
			int num_edge[8];
			num_edge[0] = gameMap[r + 1][c + 1];
			num_edge[1] = gameMap[r + 1][c];
			num_edge[2] = gameMap[r + 1][c - 1];
			num_edge[3] = gameMap[r][c - 1];
			num_edge[4] = gameMap[r - 1][c - 1];
			num_edge[5] = gameMap[r - 1][c];
			num_edge[6] = gameMap[r - 1][c + 1];
			num_edge[7] = gameMap[r][c + 1];
			vector<int> vec_edge(num_edge, num_edge + 8);

			int counter = 0;
			for (auto t : vec_edge)
			{
				if (t)
				{
					++counter;
				}
			}

			tempFrame[r][c] = counter;
		}
	}

	//std::cout << "step: " << history.size() << "gameMap:" << std::endl;
	//for (auto roll : gameMap)
	//{
	//	for (auto column : roll)
	//	{
	//		std::cout << column << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << "step: " << history.size() << "counterFrame: " << std::endl;
	//for (auto roll : tempFrame)
	//{
	//	for (auto column : roll)
	//	{
	//		std::cout << column << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//system("pause");

	for (int r = 0; r < numOfR; ++r)
	{
		for (int c = 0; c < numOfC; ++c)
		{
			int thisGrid = tempFrame[r][c];
			if (thisGrid == 3)
			{
				nextFrame[r][c] = 1;
			}
			else if (thisGrid == 2)
			{
				;//do Nothing
			}
			else
			{
				nextFrame[r][c] = 0;
			}
		}
	}

	gameMap = nextFrame;

	history.push_back(gameMap);

	return true;
}



bool isAllDead(GAMEMAP& gameMap)
{
	for (auto roll : gameMap)
	{
		for (auto column : roll)
		{
			if (column == 1)
			{
				return false;
			}
		}
	}
	return true;
}

bool isUpToLimit(const vector<GAMEMAP> history, const int limit)
{
	if (history.size() > limit)
	{
		return true;
	}

	return false;
}

bool isSameAsBefore(const vector<GAMEMAP> history)
{
	if (history.size() < 2)
	{
		return false;
	}

	GAMEMAP thisFrame = history[history.size() - 1];

	int size = history.size();
	for (int i = 0; i < size-1; ++i)
	{
		GAMEMAP previousFrame = history[i];
		if (previousFrame == thisFrame)
		{
			return true;
		}
	}
	
	return false;
}

bool LIFEGAME::FinishCondition()
{
	if (isAllDead(gameMap) || isUpToLimit(history, LIMIT) || isSameAsBefore(history))
	{
		return false;
	}

	return true;
}

bool LIFEGAME::PrintFrame()
{
	system("cls");
	std::cout << "Step: " << history.size() << std::endl;
	for (auto roll : gameMap)
	{
		for (auto column : roll)
		{
			printWithColor(column);
		}
		std::cout << std::endl;
	}
	Sleep(SLEEPTIME);
	return true;
}