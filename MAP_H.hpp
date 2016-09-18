#pragma once
#ifndef MAP_H
#define MAP_H

#include<vector>
#include<ctime>
#include<cstdlib>

using std::vector;

class MAP
{
private:
	vector<vector<int>> _map;

public:
	vector<vector<int>>& mapRandomInit(int numOfR, int numOfC);
	vector<vector<int>>& mapInit(const vector<vector<int>> map);

	vector<int>& operator[](const int& num);
	bool operator==(const MAP& toCompare);
	bool operator==(const vector<vector<int>>& toCompare);
	vector<vector<int>>::iterator end();
	vector<vector<int>>::iterator begin();
	size_t size();
	void clear();
};

#endif // !MAP_H
