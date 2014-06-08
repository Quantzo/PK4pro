#ifndef DYNAMITE_HPP
#define DYNAMITE_HPP
#include "Blank.h"
#include <iostream>
#include "Tool.h"
#include "EventQueue.h"
#include "Event.h"
#include "SFML\System\Clock.hpp"
#include "Clay.h"
#include "Granite.h"

class Dynamite : public Tool
{
public:
	Dynamite(int iDetonateTime);
	~Dynamite();
	bool use(Object* oUsedOn);
	bool tryDestroy(Object* oTestedObject);
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);
	void setUp(EventQueue* qEventQueue, int iXPosition, int iYPosition);

private:
	static int iAmount;
	int iDetonateTime;

};

#endif