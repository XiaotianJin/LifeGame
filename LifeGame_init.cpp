#include<vector>
#include<string>

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<ctime>

#include"LIFEGAME_H.h"
#include"MAP_H.h"

using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

bool LIFEGAME::GameInit()//to initialize the game, return true if succeed
{
	cout << "Please Choose the Way for Init:" << endl;
	cout << "1.Random" << endl;
	cout << "2.Choose a setted map" << endl;
	int in = 0;
	while (in != 1 && in != 2)
	{
		cin >> in;
	}
	if (in == 1)
	{
		int c = 0;
		int r = 0;
		cout << "Please input the number of rolls:";
		cin >> r;
		cout << "Please input the number of columns:";
		cin >> c;
		if (!(c > 0 && r > 0))
		{
			throw "EXP in func LIFEGAME::GameInit : invalid number of column or roll";
			return false;
		}

		gameMap.mapRandomInit(r, c);
	}
	else
	{
		GameInitWithFile();
	}


	return true;
}

bool LIFEGAME::InitFromFile(std::string filename)
{
	ifstream file = ifstream(filename, std::ios::in);
	if (!file)
	{
		throw "EXP in func LIFEGAME::InitFromFile : File " + filename + " is missing";
		return false;
	}

	int numOfR = 0;
	int numOfC = 0;
	file >> numOfR;
	file >> numOfC;
	if (!(numOfR > 0 && numOfC > 0))
	{
		throw "EXP in func LIFEGAME::InitFromFile : File " + filename + "is changed!";
		return false;
	}

	vector<vector<int>> map;
	for (int r = 0; r < numOfR; ++r)
	{
		vector<int> temp;
		for (int c = 0; c < numOfC; ++c)
		{
			int bit;
			file >> bit;
			temp.push_back(bit);
		}
		map.push_back(temp);
	}

	gameMap.mapInit(map);

	return true;
}

bool LIFEGAME::GameInitWithFile()
{
	ifstream list = ifstream(filelist, std::ios::in);
	if (!list)
	{
		throw "EXP in func LIFEGAME::GameInitWithFile : Filelist is missing";
		return false;
	}

	vector<std::string> fileList;
	while (list)
	{
		std::string temp;
		list >> temp;
		temp = "maps\\" + temp + ".txt";

		ifstream check = ifstream(temp, std::ios::in);
		if (check)
		{
			fileList.push_back(temp);
		}
	}

	int num = 1;
	for (auto str : fileList)
	{
		cout << num << ". " << str << endl;
		++num;
	}
	cout << "Please Choose:" << endl;
	int input = -1;
	while (input < 0 && input > fileList.size())
	{
		cin >> input;
	}

	InitFromFile(fileList[input - 1]);

	return true;
}
