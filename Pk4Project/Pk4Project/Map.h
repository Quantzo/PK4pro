#ifndef MAP_HPP
#define MAP_HPP
#include "Object.h"
#include "Blank.h"
#include "Player.h"
#include "Clay.h"
#include "Granite.h"

class Map
{
public:
	Map();
	Map(int iXrange, int iYrange);
	void generateMap();
	void draw(sf::RenderWindow &window);
	void movePlayer(int iDirIndex);
	void changeTool(int iToolIndex);
	void useTool();
	~Map();

private:
	int iXrange;
	int iYrange;
	Object*** oMap;
	int iXplayerPosition;
	int iYplayerPosition;
	int iCurrentDirection;
	Player* pPlayer;
};

Map::Map()
{
	this->iXrange = 50;
	this->iYrange = 50;
	this->iXplayerPosition = 0;
	this->iYplayerPosition = 0;
	this->oMap = new Object**[iXrange];
	for (int i = 0; i < iXrange; i++)
	{
		this->oMap[i] = new Object*[iYrange];
	}
	
	this->pPlayer = new Player();
	this->oMap[0][0] = this->pPlayer;
	this->iCurrentDirection = 1;

}
Map::Map(int iXrange, int iYrange)
{
	this->iXrange = iXrange;
	this->iYrange = iYrange;
	this->iXplayerPosition = 0;
	this->iYplayerPosition = 0;
	this->oMap = new Object**[iXrange];	
	for (int i = 0; i < iXrange; i++)
	{
		this->oMap[i] = new Object*[iYrange];
	}
	this->pPlayer = new Player();
	this->oMap[0][0] = this->pPlayer;
}


Map::~Map()
{
	for (int i = 0; i < this->iXrange; i++)
	{
		for (int j = 0; j < this->iYrange; j++)
		{
			delete this->oMap[i][j];
		}
	}

	for (int i = 0; i < iXrange; i++)
	{
		delete[] this->oMap[i];
	}
	delete[] this->oMap;
}



void Map::generateMap()
{
	for (int i = 0; i < this->iXrange; i++)
	{
		for (int j = 0; j < this->iYrange; j++)
		{
			if (!(i == 0 && j == 0))
			{	
				int tmp = rand() % 3;
				if (tmp == 0)
				{
					this->oMap[i][j] = new Blank();
				}
				else if (tmp == 1)
				{
					this->oMap[i][j] = new Clay();
				}
				else
				{
					this->oMap[i][j] = new Blank();
				}
			}

		}

	}

}

void Map::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < this->iXrange; i++)
	{
		for (int j = 0; j < this->iYrange; j++)
		{
			this->oMap[i][j]->draw(i, j, window);
			
		}

	}
}

void Map::movePlayer(int iDirIndex)
{
	if (iDirIndex == 1)//right
	{
		if (this->iXplayerPosition + 1 < this->iXrange)
		{
			if (dynamic_cast<Blank*>(this->oMap[iXplayerPosition + 1][iYplayerPosition]))
			{
				Object* tmp;
				tmp = this->oMap[iXplayerPosition + 1][iYplayerPosition];
				this->oMap[iXplayerPosition + 1][iYplayerPosition] = this->pPlayer;
				this->oMap[iXplayerPosition][iYplayerPosition] = tmp;
				this->iXplayerPosition = iXplayerPosition + 1;
			}
		}

		this->pPlayer->changeDirection(1);
		this->iCurrentDirection = 1;

	}
	else if (iDirIndex == 2)//left
	{
		if (this->iXplayerPosition - 1 >= 0)
		{
			if (dynamic_cast<Blank*>(this->oMap[iXplayerPosition - 1][iYplayerPosition]))
			{
				Object* tmp;
				tmp = this->oMap[iXplayerPosition - 1][iYplayerPosition];
				this->oMap[iXplayerPosition - 1][iYplayerPosition] = this->pPlayer;
				this->oMap[iXplayerPosition][iYplayerPosition] = tmp;
				this->iXplayerPosition = iXplayerPosition - 1;
			}
		}
		
		this->pPlayer->changeDirection(2);
		this->iCurrentDirection = 2;

	}
	else if (iDirIndex == 3)//up
	{
		if (this->iYplayerPosition - 1 >= 0)
		{
			if (dynamic_cast<Blank*>(this->oMap[iXplayerPosition][iYplayerPosition - 1]))
			{
				Object* tmp;
				tmp = this->oMap[iXplayerPosition][iYplayerPosition - 1];
				this->oMap[iXplayerPosition][iYplayerPosition - 1] = this->pPlayer;
				this->oMap[iXplayerPosition][iYplayerPosition] = tmp;
				this->iYplayerPosition = iYplayerPosition - 1;
			}
		}

		
		this->pPlayer->changeDirection(3);
		this->iCurrentDirection = 3;

	}
	else if (iDirIndex == 4)//down
	{

		if (this->iYplayerPosition + 1 < this->iYrange)
		{
			if (dynamic_cast<Blank*>(this->oMap[iXplayerPosition][iYplayerPosition + 1]))
			{
				Object* tmp;
				tmp = this->oMap[iXplayerPosition][iYplayerPosition + 1];
				this->oMap[iXplayerPosition][iYplayerPosition + 1] = this->pPlayer;
				this->oMap[iXplayerPosition][iYplayerPosition] = tmp;
				this->iYplayerPosition = iYplayerPosition + 1;
			}
		}
		
		this->pPlayer->changeDirection(4);
		this->iCurrentDirection = 4;
	}
}

void Map::changeTool(int iToolIndex)
{
	this->pPlayer->setToolIndex(iToolIndex);
}

void Map::useTool()
{
	if (this->iCurrentDirection == 1)
	{
		if (this->iXplayerPosition + 1 < this->iXrange)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition + 1][iYplayerPosition]))
			{
				delete this->oMap[iXplayerPosition + 1][iYplayerPosition];
				this->oMap[iXplayerPosition + 1][iYplayerPosition] = new Blank();
			}
		}

	}
	else if (this->iCurrentDirection == 2)
	{
		if (this->iXplayerPosition - 1 >= 0)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition - 1][iYplayerPosition]))
			{
				delete this->oMap[iXplayerPosition - 1][iYplayerPosition];
				this->oMap[iXplayerPosition - 1][iYplayerPosition] = new Blank();
			}
		}
	}
	else if (this->iCurrentDirection == 3)
	{
		if (this->iYplayerPosition - 1 >= 0)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition][iYplayerPosition - 1]))
			{
				delete this->oMap[iXplayerPosition][iYplayerPosition - 1];
				this->oMap[iXplayerPosition][iYplayerPosition - 1] = new Blank();
			}
		}
	}
	else if (this->iCurrentDirection == 4)
	{
		if (this->iYplayerPosition + 1 < this->iYrange)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition][iYplayerPosition + 1]))
			{
				delete this->oMap[iXplayerPosition][iYplayerPosition + 1];
				this->oMap[iXplayerPosition][iYplayerPosition + 1] = new Blank();
			}
		}
	}
}
#endif