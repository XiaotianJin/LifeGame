#include<vector>
#include<ctime>
#include<cstdlib>

#include"MAP_H.hpp"

using std::vector;

vector<vector<int>>& MAP::mapInit(const vector<vector<int>> map)
{
	int numOfR = 0;
	int numOfC = 0;
	numOfR = map.size();
	if (numOfR > 0)
	{
		numOfC = map[0].size();
	}
	if (numOfC <= 0)
	{
		throw "Map init Failed due to wrong input file";
		return _map;
	}

	vector<int> edges;
	for (int i = 0; i < numOfC + 2; ++i)
	{
		edges.push_back(0);
	}

	_map.push_back(edges);
	for (int r = 0; r < numOfR; ++r)
	{
		vector<int> tempVec;
		tempVec.push_back(0);
		for (int c = 0; c < numOfC; ++c)
		{
			//Here is the initial for the map of our lifegame entity.(using random method
			tempVec.push_back(map[r][c]);
		}
		tempVec.push_back(0);
		_map.push_back(tempVec);
	}
	_map.push_back(edges);

	return _map;
}

vector<vector<int>>& MAP::mapRandomInit(int numOfR, int numOfC)
{
	srand((unsigned)time(NULL));

	if (!(numOfR > 0 && numOfC > 0))
	{
		throw "Map init Failed due to invalid number of rolls and column";
		return _map;
	}

	vector<int> edges;
	for (int i = 0; i < numOfC + 2; ++i)
	{
		edges.push_back(0);
	}

	_map.push_back(edges);
	for (int r = 0; r < numOfR; ++r)
	{
		vector<int> tempVec;
		tempVec.push_back(0);
		for (int c = 0; c < numOfC; ++c)
		{
			//Here is the initial for the map of our lifegame entity.(using random method
			tempVec.push_back(rand() % 2);
		}
		tempVec.push_back(0);
		_map.push_back(tempVec);
	}
	_map.push_back(edges);

	return _map;
}

vector<int>& MAP::operator[](const int& num)
{
	return _map[num];
}

bool MAP::operator==(const MAP& toCompare)
{
	return _map == toCompare._map;
}

bool MAP::operator==(const vector<vector<int>>& toCompare)
{
	return _map == toCompare;
}

vector<vector<int>>::iterator MAP::end()
{
	vector<vector<int>>::iterator it;
	it = _map.end();
	return it;
}

vector<vector<int>>::iterator MAP::begin()
{
	vector<vector<int>>::iterator it;
	it = _map.begin();
	return it;
}

size_t MAP::size()
{
	return _map.size();
}

void MAP::clear()
{
	_map.clear();
}
