#ifndef BOMB_HPP
#define BOMB_HPP
#include "Tool.h"

class Bomb: public Tool
{
public:
	Bomb();
	~Bomb();

private:
	int iAmount;
	
};

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}
#endif