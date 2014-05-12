#ifndef MAP_HPP
#define MAP_HPP
#include "Object.h"

class Map
{
public:
	Map();
	Map(int iXrange, int iYrange);
	void generateMap();
	int movePlayer();
	~Map();

private:
	int iXrange;
	int iYrange;
	Object** oMap;
	int iXplayerPosition;
	int iYplayerPosition;
};

Map::Map()
{
	this->iXrange = 50;
	this->iYrange = 50;
	this->iXplayerPosition = 0;
	this->iYplayerPosition = 0;
	this->oMap = new Object*[iXrange];
	for (int i = 0; i < iXrange; i++)
	{
		this->oMap[i] = new Object[iYrange];
	}

}
Map::Map(int iXrange, int iYrange)
{
	this->iXrange = iXrange;
	this->iYrange = iYrange;
	this->iXplayerPosition = 0;
	this->iYplayerPosition = 0;
	this->oMap = new Object*[iXrange];
	for (int i = 0; i < iXrange; i++)
	{
		this->oMap[i] = new Object[iYrange];
	}
}


Map::~Map()
{
	for (int i = 0; i < iXrange; i++)
	{
		delete[] this->oMap[i];
	}
	delete[] this->oMap;
}

void Map::generateMap()
{

}

#endif