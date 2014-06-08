#ifndef MENU_HPP
#define MENU_HPP
#include "SFML\Graphics.hpp"
#include "SFML\Graphics\Font.hpp"
#include "ProfilesContainer.h"
class Menu
{
public:
	Menu(ProfilesContainer* profiles);
	~Menu();
	void Draw(sf::RenderWindow &window);
	void selectOption(int iDir);
	int useOption();
	
	
private:
	bool bRight;
	int iActualRightItem;
	int iMenuSize;
	int iActualItem;
	int iActualMenu;
	int iRightMenuSize;
	int iActualProfile;
	ProfilesContainer* profiles;
	sf::Font Font;
};



#endif