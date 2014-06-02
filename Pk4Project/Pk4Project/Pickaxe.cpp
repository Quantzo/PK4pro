#include "Pickaxe.h"

Pickaxe::Pickaxe()
{
}
bool Pickaxe::use(Object* oUsedOn)
{
	if (dynamic_cast<Clay*>(oUsedOn))
	{
		//animation
		return true;
	}
	return false;
}

void Pickaxe::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{

}

Pickaxe::~Pickaxe()
{
}