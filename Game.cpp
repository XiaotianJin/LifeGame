#include<iostream>

#include"GAME_H.h"

bool GAME::SysInit()
{
	try
	{
		system("color f0");
		system("mode con cols=150 lines=90");
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << std::endl;
		return false;
	}
	return true;
}

bool GAME::OnGameStart()
{
	bool sysInitRes = false;
	bool gameInitRes = false;

	sysInitRes = SysInit();
	try
	{
		gameInitRes = GameInit();
	}
	catch (const char* exp)
	{
		std::cerr << exp << std::endl;
	}

	return (sysInitRes && gameInitRes);
}

bool GAME::FinishCondition()
{
	return true;
}

bool GAME::RunGame()
{
	while (FinishCondition())
	{
		try
		{
			Update();
			PrintFrame();
		}
		catch (const char* exp)
		{
			std::cerr << exp << std::endl;
		}
	}

	return GAME::FinishCondition();
}