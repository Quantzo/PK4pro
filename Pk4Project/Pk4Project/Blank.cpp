#include "Blank.h"

Blank::Blank()
{
}
void Blank::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{
	sf::RectangleShape shape(sf::Vector2f(10, 10));
	shape.setFillColor(sf::Color::White);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);
}


Blank::~Blank()
{
}