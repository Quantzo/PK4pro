#include "Dynamite.h"
Dynamite::Dynamite(int iDetonateTime)
{
	this->iDetonateTime = iDetonateTime;
}

Dynamite::~Dynamite()
{
}
void Dynamite::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{
	sf::CircleShape shape(5.f);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);
}

void Dynamite::setUp(EventQueue* qEventQueue, int iXPosition, int iYPosition)
{
	sf::Clock clock;
	while (true)
	{
		sf::Time time = clock.getElapsedTime();

		if ((int)time.asSeconds() >= this->iDetonateTime)
		{
			break;
		}
	}
	qEventQueue->addEvent(iXPosition, iYPosition, this);
	return;
}
bool Dynamite::use(Object* oUsedOn)
{
	if (dynamic_cast<Blank*>(oUsedOn))
	{
		return true;
	}
	return false;
}
bool Dynamite::tryDestroy(Object* oTestedObject)
{
	if (dynamic_cast<Clay*>(oTestedObject))
	{
		return true;
	}
	else if (dynamic_cast<Granite*>(oTestedObject))
	{
		return true;
	}
	return false;
}
