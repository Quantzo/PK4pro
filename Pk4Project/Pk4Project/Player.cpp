#include "Player.h"
Player::Player()
{
	this->bRight = true;
	this->bLeft = false;
	this->bUp = false;
	this->bDown = false;
	this->tCurrentTool = new Pickaxe();
	this->iCurrentToolIndex = 1;
}
void Player::changeDirection(int iDirIndex)
{
	if (iDirIndex == 1)
	{
		this->bRight = true;
		this->bLeft = false;
		this->bUp = false;
		this->bDown = false;
	}
	else if (iDirIndex == 2)
	{
		this->bRight = false;
		this->bLeft = true;
		this->bUp = false;
		this->bDown = false;
	}
	else if (iDirIndex == 3)
	{
		this->bRight = false;
		this->bLeft = false;
		this->bUp = true;
		this->bDown = false;
	}
	else if (iDirIndex == 4)
	{
		this->bRight = false;
		this->bLeft = false;
		this->bUp = false;
		this->bDown = true;
	}
}

void Player::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{
	sf::CircleShape shape(5.f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);

}
int Player::getToolIndex()
{
	return this->iCurrentToolIndex;
}
void Player::setToolIndex(int iToolIndex)
{
	delete this->tCurrentTool;
	this->iCurrentToolIndex = iToolIndex;
	if (iToolIndex == 1)//pickaxe
	{
		this->tCurrentTool = new Pickaxe();
	}
	else if (iToolIndex == 2) //superpickaxe
	{
		//this->tCurrentTool = new SuperPickaxe();
	}
	else if (iToolIndex == 3)//bomb
	{
		this->tCurrentTool = new Bomb(3);
	}
	else if (iToolIndex == 4)//dynamite
	{
		//this->tCurrentTool = new Dynamite();
	}
}

bool Player::useTool(Object* oUsedOn)
{
	return this->tCurrentTool->use(oUsedOn);
}

Player::~Player()
{
}