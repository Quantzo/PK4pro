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
#endif