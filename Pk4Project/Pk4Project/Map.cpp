#include "Map.h"

Map::Map(int iBomb, int iDynamites,Profile* &currentProfile)
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
	this->CurrentProfile = currentProfile;
	this->iBomb = iBomb;
	this->iDynamites = iDynamites;
	this->qEventQueue = new EventQueue();
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
	delete this->qEventQueue;
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
					this->oMap[i][j] = new Clay();
				}
				else if (tmp == 1)
				{
					this->oMap[i][j] = new Clay();
				}
				else
				{
					this->oMap[i][j] = new Clay();
				}
			}

		}

	}

}

void Map::handleEvents()
{
	this->qEventQueue->handleEvents(this);
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




void Map::useCurrentTool(int iXPosition, int iYPosition)
{
	if (this->pPlayer->getToolIndex() == 1)//pickaxe
	{
		this->usePickaxe(iXPosition, iYPosition);
	}
	else if (this->pPlayer->getToolIndex() == 2)//superpickaxe
	{
		this->useSuperPickaxe(iXPosition, iYPosition);
	}
	else if (this->pPlayer->getToolIndex() == 3)//bomb
	{
		this->useBomb(iXPosition, iYPosition);
	}
	else if (this->pPlayer->getToolIndex() == 4)//dynamite
	{
		this->useDynamite(iXPosition, iYPosition);
	}
}


void Map::usePickaxe(int iXPosition, int iYPosition)
{
	delete this->oMap[iXPosition][iYPosition];
	this->oMap[iXPosition][iYPosition] = new Blank();
}
void Map::useSuperPickaxe(int iXPosition, int iYPosition)
{
	delete this->oMap[iXPosition][iYPosition];
	this->oMap[iXPosition][iYPosition] = new Blank();
}
void Map::useBomb(int iXPosition, int iYPosition)
{
	delete this->oMap[iXPosition][iYPosition];
	Bomb* tmp = new Bomb(3);
	this->oMap[iXPosition][iYPosition] = tmp;
	std::thread thread(&Bomb::setUp, tmp, this->qEventQueue,iXPosition,iYPosition);
	thread.detach();
}
void Map::useDynamite(int iXPosition, int iYPosition)
{
	delete this->oMap[iXPosition][iYPosition];
	Dynamite* tmp = new Dynamite(5);
	this->oMap[iXPosition][iYPosition] = tmp;
	std::thread thread(&Dynamite::setUp, tmp, this->qEventQueue, iXPosition, iYPosition);
	thread.detach();
}

void Map::useTool()
{
	if (this->iCurrentDirection == 1)
	{
		if (this->iXplayerPosition + 1 < this->iXrange)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition + 1][iYplayerPosition]))
			{
				this->useCurrentTool(iXplayerPosition + 1, iYplayerPosition);
			}
		}

	}
	else if (this->iCurrentDirection == 2)
	{
		if (this->iXplayerPosition - 1 >= 0)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition - 1][iYplayerPosition]))
			{
				this->useCurrentTool(iXplayerPosition - 1, iYplayerPosition);
			}
		}
	}
	else if (this->iCurrentDirection == 3)
	{
		if (this->iYplayerPosition - 1 >= 0)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition][iYplayerPosition - 1]))
			{
				this->useCurrentTool(iXplayerPosition, iYplayerPosition - 1);
			}
		}
	}
	else if (this->iCurrentDirection == 4)
	{
		if (this->iYplayerPosition + 1 < this->iYrange)
		{
			if (this->pPlayer->useTool(this->oMap[iXplayerPosition][iYplayerPosition + 1]))
			{
				this->useCurrentTool(iXplayerPosition, iYplayerPosition + 1);
			}
		}
	}
}

void Map::explodeBomb(Bomb* oBomb, int iXPosition, int iYPosition)
{
	bool bLeft = false;
	bool bRight = false;
	bool bUp = false;
	bool bDown = false;

	if (iXPosition - 1 >= 0)
	{
		if (oBomb->tryDestroy(this->oMap[iXPosition - 1][iYPosition]))
		{
			delete this->oMap[iXPosition - 1][iYPosition];
			this->oMap[iXPosition - 1][iYPosition] = new Blank();
		}
		bLeft = true;
	}
	if (iXPosition + 1 < iXrange)
	{
		bRight = true;
		if (oBomb->tryDestroy(this->oMap[iXPosition + 1][iYPosition]))
		{
			delete this->oMap[iXPosition + 1][iYPosition];
			this->oMap[iXPosition + 1][iYPosition] = new Blank();
		}
	}
	if (iYPosition - 1 >= 0)
	{
		bUp = true;
		if (oBomb->tryDestroy(this->oMap[iXPosition][iYPosition - 1]))
		{
			delete this->oMap[iXPosition][iYPosition - 1];
			this->oMap[iXPosition][iYPosition - 1] = new Blank();
		}
	}
	if (iYPosition + 1 < iYrange)
	{
		bDown = true;
		if (oBomb->tryDestroy(this->oMap[iXPosition][iYPosition + 1]))
		{
			delete this->oMap[iXPosition][iYPosition + 1];
			this->oMap[iXPosition][iYPosition + 1] = new Blank();
		}
	}
	if (bLeft && bDown)
	{
		if (oBomb->tryDestroy(this->oMap[iXPosition - 1][iYPosition + 1]))
		{
			delete this->oMap[iXPosition - 1][iYPosition + 1];
			this->oMap[iXPosition - 1][iYPosition + 1] = new Blank();
		}
	}
	if (bLeft && bUp)
	{
		if (oBomb->tryDestroy(this->oMap[iXPosition - 1][iYPosition - 1]))
		{
			delete this->oMap[iXPosition - 1][iYPosition - 1];
			this->oMap[iXPosition - 1][iYPosition - 1] = new Blank();
		}
	}
	if (bRight && bDown)
	{
		if (oBomb->tryDestroy(this->oMap[iXPosition + 1][iYPosition + 1]))
		{
			delete this->oMap[iXPosition + 1][iYPosition + 1];
			this->oMap[iXPosition + 1][iYPosition + 1] = new Blank();
		}
	}
	if (bRight && bUp)
	{
		if (oBomb->tryDestroy(this->oMap[iXPosition + 1][iYPosition - 1]))
		{
			delete this->oMap[iXPosition + 1][iYPosition - 1];
			this->oMap[iXPosition + 1][iYPosition - 1] = new Blank();
		}
	}
	delete this->oMap[iXPosition][iYPosition];
	this->oMap[iXPosition][iYPosition] = new Blank();
}

void Map::explodeDynamite(Dynamite* oDynamite, int iXPosition, int iYPosition)
{
	bool bLeft = false;
	bool bRight = false;
	bool bUp = false;
	bool bDown = false;

	if (iXPosition - 1 >= 0)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 1][iYPosition]))
		{
			delete this->oMap[iXPosition - 1][iYPosition];
			this->oMap[iXPosition - 1][iYPosition] = new Blank();
		}
		bLeft = true;
	}
	if (iXPosition + 1 < iXrange)
	{
		bRight = true;
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 1][iYPosition]))
		{
			delete this->oMap[iXPosition + 1][iYPosition];
			this->oMap[iXPosition + 1][iYPosition] = new Blank();
		}
	}
	if (iYPosition - 1 >= 0)
	{
		bUp = true;
		if (oDynamite->tryDestroy(this->oMap[iXPosition][iYPosition - 1]))
		{
			delete this->oMap[iXPosition][iYPosition - 1];
			this->oMap[iXPosition][iYPosition - 1] = new Blank();
		}
	}
	if (iYPosition + 1 < iYrange)
	{
		bDown = true;
		if (oDynamite->tryDestroy(this->oMap[iXPosition][iYPosition + 1]))
		{
			delete this->oMap[iXPosition][iYPosition + 1];
			this->oMap[iXPosition][iYPosition + 1] = new Blank();
		}
	}
	if (bLeft && bDown)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 1][iYPosition + 1]))
		{
			delete this->oMap[iXPosition - 1][iYPosition + 1];
			this->oMap[iXPosition - 1][iYPosition + 1] = new Blank();
		}
	}
	if (bLeft && bUp)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 1][iYPosition - 1]))
		{
			delete this->oMap[iXPosition - 1][iYPosition - 1];
			this->oMap[iXPosition - 1][iYPosition - 1] = new Blank();
		}
	}
	if (bRight && bDown)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 1][iYPosition + 1]))
		{
			delete this->oMap[iXPosition + 1][iYPosition + 1];
			this->oMap[iXPosition + 1][iYPosition + 1] = new Blank();
		}
	}
	if (bRight && bUp)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 1][iYPosition - 1]))
		{
			delete this->oMap[iXPosition + 1][iYPosition - 1];
			this->oMap[iXPosition + 1][iYPosition - 1] = new Blank();
		}
	}
	//second layer
	bool bLeft2 = false;
	bool bRight2 = false;
	bool bUp2 = false;
	bool bDown2 = false;

	if (iXPosition - 2 >= 0)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 2][iYPosition]))
		{
			delete this->oMap[iXPosition - 2][iYPosition];
			this->oMap[iXPosition - 2][iYPosition] = new Blank();
		}
		bLeft2 = true;
	}
	if (iXPosition + 2 < iXrange)
	{
		bRight2 = true;
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 2][iYPosition]))
		{
			delete this->oMap[iXPosition + 2][iYPosition];
			this->oMap[iXPosition + 2][iYPosition] = new Blank();
		}
	}
	if (iYPosition - 2 >= 0)
	{
		bUp2 = true;
		if (oDynamite->tryDestroy(this->oMap[iXPosition][iYPosition - 2]))
		{
			delete this->oMap[iXPosition][iYPosition - 2];
			this->oMap[iXPosition][iYPosition - 2] = new Blank();
		}
	}
	if (iYPosition + 2 < iYrange)
	{
		bDown2 = true;
		if (oDynamite->tryDestroy(this->oMap[iXPosition][iYPosition + 2]))
		{
			delete this->oMap[iXPosition][iYPosition + 2];
			this->oMap[iXPosition][iYPosition + 2] = new Blank();
		}
	}
	if (bLeft2 && bDown2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 2][iYPosition + 2]))
		{
			delete this->oMap[iXPosition - 2][iYPosition + 2];
			this->oMap[iXPosition - 2][iYPosition + 2] = new Blank();
		}

	}
	if (bLeft2 && bUp2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 2][iYPosition - 2]))
		{
			delete this->oMap[iXPosition - 2][iYPosition - 2];
			this->oMap[iXPosition - 2][iYPosition - 2] = new Blank();
		}
	}
	if (bRight2 && bDown2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 2][iYPosition + 2]))
		{
			delete this->oMap[iXPosition + 2][iYPosition + 2];
			this->oMap[iXPosition + 2][iYPosition + 2] = new Blank();
		}
	}
	if (bRight2 && bUp2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 2][iYPosition - 2]))
		{
			delete this->oMap[iXPosition + 2][iYPosition - 2];
			this->oMap[iXPosition + 2][iYPosition - 2] = new Blank();
		}
	}
	//
	if (bLeft && bDown2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 1][iYPosition + 2]))
		{
			delete this->oMap[iXPosition - 1][iYPosition + 2];
			this->oMap[iXPosition - 1][iYPosition + 2] = new Blank();
		}

	}
	if (bLeft && bUp2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 1][iYPosition - 2]))
		{
			delete this->oMap[iXPosition - 1][iYPosition - 2];
			this->oMap[iXPosition - 1][iYPosition - 2] = new Blank();
		}
	}
	if (bRight && bDown2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 1][iYPosition + 2]))
		{
			delete this->oMap[iXPosition + 1][iYPosition + 2];
			this->oMap[iXPosition + 1][iYPosition + 2] = new Blank();
		}
	}
	if (bRight && bUp2)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 1][iYPosition - 2]))
		{
			delete this->oMap[iXPosition + 1][iYPosition - 2];
			this->oMap[iXPosition + 1][iYPosition - 2] = new Blank();
		}
	}
	//
	if (bLeft2 && bDown)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 2][iYPosition + 1]))
		{
			delete this->oMap[iXPosition - 2][iYPosition + 1];
			this->oMap[iXPosition - 2][iYPosition + 1] = new Blank();
		}

	}
	if (bLeft2 && bUp)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition - 2][iYPosition - 1]))
		{
			delete this->oMap[iXPosition - 2][iYPosition - 1];
			this->oMap[iXPosition - 2][iYPosition - 1] = new Blank();
		}
	}
	if (bRight2 && bDown)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 2][iYPosition + 1]))
		{
			delete this->oMap[iXPosition + 2][iYPosition + 1];
			this->oMap[iXPosition + 2][iYPosition + 1] = new Blank();
		}
	}
	if (bRight2 && bUp)
	{
		if (oDynamite->tryDestroy(this->oMap[iXPosition + 2][iYPosition - 1]))
		{
			delete this->oMap[iXPosition + 2][iYPosition - 1];
			this->oMap[iXPosition + 2][iYPosition - 1] = new Blank();
		}
	}

	delete this->oMap[iXPosition][iYPosition];
	this->oMap[iXPosition][iYPosition] = new Blank();
}