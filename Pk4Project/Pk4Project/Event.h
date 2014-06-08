#ifndef EVENT_HPP
#define EVENT_HPP
#include "Object.h"
//#include "Map.h"
class Map;

class Event
{
public:
	Event(int iXPosition, int iYPosition, Object* oCaller);
	void handleEvent(Map* map);
	~Event();

private:
	int iEventTypeindex;
	int iXPosition;
	int iYPosition;
	Object* oCaller;
};

#endif