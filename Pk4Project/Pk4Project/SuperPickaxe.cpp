#include "SuperPickaxe.h"
bool SuperPickaxe::use(Object* oUsedOn)
{
	if (dynamic_cast<Clay*>(oUsedOn))
	{
		//animation
		return true;
	}
	else if (dynamic_cast<Granite*>(oUsedOn))
	{
		return true;
	}
	return false;
}
void SuperPickaxe::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{

}

