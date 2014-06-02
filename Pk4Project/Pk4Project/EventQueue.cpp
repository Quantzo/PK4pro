#include "EventQueue.h"
#include "Map.h"


void EventQueue::addEvent(int iXPosition, int iYPosition, Object* oCaller)
{
	this->qEventQueue.push(Event(iXPosition, iYPosition, oCaller));
}
void EventQueue::handleEvents(Map* map)
{
	while (!(this->qEventQueue.empty()))
	{
		this->qEventQueue.front().handleEvent(map);
		this->qEventQueue.pop();
	}
}
EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
}