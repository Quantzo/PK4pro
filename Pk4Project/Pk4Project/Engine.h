#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Menu.h"
#include "ProfilesContainer.h"

class Engine
{
public:
	Engine();
	~Engine();
	void startGame();
	void startMenu(sf::RenderWindow &window);

private:
	bool bMenu;
	bool bGame;
	int iBombs;
	int iDynamites;
	ProfilesContainer* profiles;
	Profile* currentProfile;
};


#endif