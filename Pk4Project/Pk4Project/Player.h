#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Object.h"
class Player : public Object
{
public:
	Player();
	~Player();
	void changeDirection(int iDirIndex);

private:
	bool bRight;
	bool bLeft;
	bool bUp;
	bool bDown;

};

Player::Player()
{
	this->bRight = true;
	this->bLeft = false;
	this->bUp = false;
	this->bDown = false;
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
Player::~Player()
{
}
#endif