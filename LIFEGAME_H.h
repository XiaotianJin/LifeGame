#pragma once
#ifndef LIFEGAME_H
#define LIFEGAME_H

#define DEBUG_XT

#include<vector>
#include<string>

#include"GAME_H.h"
#include"MAP_H.h"

using std::vector;
using std::string;

typedef MAP GAMEMAP;

const int SLEEPTIME = 300;
const string filelist = "maps\\list.txt";

class LIFEGAME : public GAME
{
private:
	GAMEMAP gameMap;//To store the map of life game
	vector<GAMEMAP> history;//To store the maps' history
	int LIMIT = 1e6;//To avoid to much updating

	bool InitFromFile(string filename);

public:
	bool GameInit();
	bool GameInitWithFile();

	bool Update() final;

	bool PrintFrame() final;

	bool FinishCondition() final;
};


#endif // !LIFEGAME_H
