#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Object.h"
#include "Tool.h"
#include "Pickaxe.h"
class Player : public Object
{
public:
	Player();
	~Player();
	void changeDirection(int iDirIndex);
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);
	void setToolIndex(int iToolIndex);
	bool useTool(Object* oUsedOn);

private:
	bool bRight;
	bool bLeft;
	bool bUp;
	bool bDown;
	Tool* tCurrentTool;
	int iCurrentToolIndex;

};

Player::Player()
{
	this->bRight = true;
	this->bLeft = false;
	this->bUp = false;
	this->bDown = false;
	this->tCurrentTool = new Pickaxe();
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
	sf::CircleShape shape2(5.f);
	shape2.setFillColor(sf::Color::Green);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);

}

void Player::setToolIndex(int iToolIndex)
{
	this->iCurrentToolIndex = iToolIndex;
}

bool Player::useTool(Object* oUsedOn)
{
	return this->tCurrentTool->use(oUsedOn);
}

Player::~Player()
{
}
#endif