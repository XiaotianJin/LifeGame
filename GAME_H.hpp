#pragma once
#ifndef GAME_H
#define GAME_H

class GAME
{
private:
	virtual bool SysInit();//TO init the cmd or shell
	virtual bool GameInit() = 0;//To init the game-related varibles

	virtual bool Update() = 0;//During the game, update the game-related varibles
	virtual bool PrintFrame() = 0;//To print
	virtual bool FinishCondition();//return false if it is end.

public:
	virtual bool OnGameStart();//before running the game

	virtual bool RunGame();//start game
};

#endif // !GAME_H
