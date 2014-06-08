#ifndef MAP_HPP
#define MAP_HPP
#include "Bomb.h"
#include "Dynamite.h"
#include "Event.h"
#include "Player.h"

#include "EventQueue.h"

#include "Object.h"
#include "Blank.h"
#include "Clay.h"
#include "Granite.h"
#include "Profile.h"

#include <thread>

class Map
{
public:
	Map(int iBomb, int iDynamites,Profile* &currentProfile);
	Map(int iXrange, int iYrange);
	void generateMap();
	void handleEvents();
	void draw(sf::RenderWindow &window);
	void movePlayer(int iDirIndex);
	void changeTool(int iToolIndex);
	void useTool();
	void useCurrentTool(int iXPosition, int iYPosition);
	void usePickaxe(int iXPosition, int iYPosition);
	void useSuperPickaxe(int iXPosition, int iYPosition);
	void useBomb(int iXPosition, int iYPosition);
	void useDynamite(int iXPosition, int iYPosition);
	void explodeBomb(Bomb* oBomb, int iXPosition, int iYPosition);
	void explodeDynamite(Dynamite* oDynamite, int iXPosition, int iYPosition);
	~Map();

private:
	int iXrange;
	int iYrange;
	Object*** oMap;
	int iXplayerPosition;
	int iYplayerPosition;
	int iCurrentDirection;
	int iDynamites;
	int iBomb;
	Profile* CurrentProfile;
	Player* pPlayer;
	EventQueue* qEventQueue;

};


#endif