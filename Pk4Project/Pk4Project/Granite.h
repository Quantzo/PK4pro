#ifndef GRANITE_HPP
#define GRANITE_HPP
#include "Terrain.h"
class Granite : public Terrain
{
public:
	Granite();
	~Granite();
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);

private:

};

Granite::Granite()
{
}
void Granite::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{
	sf::RectangleShape shape(sf::Vector2f(10, 10));
	shape.setFillColor(sf::Color::Cyan);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);
}
Granite::~Granite()
{
}
#endif