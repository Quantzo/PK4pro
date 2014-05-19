#ifndef CLAY_HPP
#define CLAY_HPP
#include "Terrain.h"
class Clay : public Terrain
{
public:
	Clay();
	~Clay();
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);

private:

};

Clay::Clay()
{
}
void Clay::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{
	sf::RectangleShape shape(sf::Vector2f(10, 10));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(10 * iXpos, 10 * iYpos);
	window.draw(shape);
}
Clay::~Clay()
{
}
#endif