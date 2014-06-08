#include "Event.h"
#include "Bomb.h"
#include "Map.h"
#include "Dynamite.h"

Event::Event(int iXPosition, int iYPosition, Object* oCaller)
{
	this->iXPosition = iXPosition;
	this->iYPosition = iYPosition;
	this->oCaller = oCaller;

}

void Event::handleEvent(Map* map)
{
	if (Bomb* tmp = dynamic_cast<Bomb*>(this->oCaller))
	{
		map->explodeBomb(tmp, this->iXPosition, this->iYPosition);
	}
	else if (Dynamite* tmp = dynamic_cast<Dynamite*>(this->oCaller))
	{
		map->explodeDynamite(tmp, this->iXPosition, this->iYPosition);
	}
}

Event::~Event()
{
}