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
#endif