#include "Bomb.h"
Bomb::Bomb(int iDetonateTime)
{
	this->iDetonateTime = iDetonateTime;
}

Bomb::~Bomb()
{
}
void Bomb::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{
	sf::CircleShape shape(5.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);
}

void Bomb::setUp(EventQueue* qEventQueue, int iXPosition, int iYPosition)
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
	std::cout << "Bombe wybuchle" << std::endl;
	return;
}
bool Bomb::use(Object* oUsedOn)
{
	if (dynamic_cast<Blank*>(oUsedOn))
	{
		return true;
	}
	return false;
}
bool Bomb::tryDestroy(Object* oTestedObject)
{
	if (dynamic_cast<Clay*>(oTestedObject))
	{
		return true;
	}
	return false;
}
