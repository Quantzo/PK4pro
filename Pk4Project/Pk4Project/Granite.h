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
#endif