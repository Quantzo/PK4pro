#ifndef Blank_HPP
#define Blank_HPP
#include "Terrain.h"
class Blank : public Terrain
{
public:
	Blank();
	~Blank();
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);

private:

};

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
#endif