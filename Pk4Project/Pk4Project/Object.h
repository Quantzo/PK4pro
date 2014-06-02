#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML\Graphics.hpp>
class Object
{
public:
	Object(){};
	virtual ~Object(){};
	virtual void draw(int iXpos, int iYpos, sf::RenderWindow &window) = 0;
private:

};
#endif