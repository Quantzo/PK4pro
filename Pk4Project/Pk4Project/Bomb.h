#ifndef BOMB_HPP
#define BOMB_HPP
#include "Blank.h"
#include <iostream>
#include "Tool.h"
#include "EventQueue.h"
#include "Event.h"
#include "SFML\System\Clock.hpp"
#include "Clay.h"

class Bomb: public Tool
{
public:
	Bomb(int iDetonateTime);
	~Bomb(); 
	bool use(Object* oUsedOn);
	bool tryDestroy(Object* oTestedObject);
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);
	void setUp(EventQueue* qEventQueue,int iXPosition,int iYPosition);

private:
	static int iAmount;
	int iDetonateTime;
	
};
#endif