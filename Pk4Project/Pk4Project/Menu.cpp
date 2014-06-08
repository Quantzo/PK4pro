#include "Menu.h"
#include "SFML\Graphics.hpp"
Menu::Menu(ProfilesContainer* profiles)
{
	this->iBombs = 0;
	this->iDynamites = 0;
	this->profiles = profiles;
	this->bRight = false;
	this->iActualMenu = 1;
	this->iActualItem = 1;
	this->iActualRightItem = 1;
	this->iRightMenuSize = 2;
	this->iMenuSize = 3;
	this->Font.loadFromFile("C:\\Users\\Quantzo\\Source\\Repos\\ProjektPK4\\Pk4Project\\Pk4Project\\Cinta Adalah Perhatian.ttf");
}
void Menu::selectOption(int iDir)
{
	if (this->bRight)
	{
		if (iDir == 1)//up
		{
			if (this->iActualRightItem> 1)
			{
				this->iActualRightItem--;
			}
		}
		else if (iDir == 2)//down
		{
			if (this->iActualRightItem < this->iRightMenuSize)
			{
				this->iActualRightItem++;
			}
		}
	}
	else
	{
		if (iDir == 1)//up
		{
			if (this->iActualItem > 1)
			{
				this->iActualItem--;
			}
		}
		else if (iDir == 2)//down
		{
			if (this->iActualItem < this->iMenuSize)
			{
				this->iActualItem++;
			}
		}
	}
	if (this->iActualMenu != 1)
	{
		if (iDir == 3)//right
		{
			this->bRight = true;
		}
		if (iDir == 4)//left
		{
			this->bRight = false;
		}
	}

}

int Menu::useOption(int &iBombs, int &iDynamites,Profile* &currentProfile)
{
	if (this->iActualMenu == 1)
	{
		if (this->iActualItem == 1)
		{
			this->iActualMenu = 2;
			this->iActualItem = 1;
			this->iMenuSize = this->profiles->getSize();
			this->iRightMenuSize = 2;
			return 0;
		}
		else if (this->iActualItem == 2)
		{
			return 1;
		}
		else if (this->iActualItem == 3)
		{
			return 2;
		}

	}
	else if (this->iActualMenu == 2)
	{
		if (bRight)
		{
			if (this->iActualRightItem == 1)
			{
				this->iActualMenu = 3;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 3;
				this->iMenuSize = this->profiles->getSize();
				this->iActualItem = 1;
				this->bRight = false;
				return 0;
			}
			else if (this->iActualRightItem == 2)
			{
				this->iActualMenu = 1;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 0;
				this->iMenuSize = 3;
				this->iActualItem = 1;
				this->bRight = false;
				return 0;
			}
		}
		else
		{
			if (this->iActualItem == 1)
			{
				this->iActualProfile = 0;
				this->iActualItem = 1;
				this->bRight = false;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 1;
				this->iActualMenu = 4;
				return 0;
			}
			else if (this->iActualItem == 2)
			{
				this->iActualProfile = 1;
				this->iActualItem = 1;
				this->bRight = false;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 1;
				this->iActualMenu = 4;
				return 0;
			}
			else if (this->iActualItem == 3)
			{
				this->iActualProfile = 2;
				this->iActualItem = 1;
				this->bRight = false;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 1;
				this->iActualMenu = 4;
				return 0;
			}
			else if (this->iActualItem == 4)
			{
				this->iActualProfile = 3;
				this->iActualItem = 1;
				this->bRight = false;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 1;
				this->iActualMenu = 4;
				return 0;
			}
			else if (this->iActualItem == 5)
			{
				this->iActualProfile = 4;
				this->iActualItem = 1;
				this->bRight = false;
				this->iActualRightItem = 1;
				this->iRightMenuSize = 1;
				this->iActualMenu = 4;
				return 0;
			}
		}

	}
	else if (this->iActualMenu == 3)
	{
		if (bRight)
		{
			if (this->iActualRightItem == 1)//delete
			{
				this->profiles->removeProfile(this->iActualItem - 1);
				return 0;
			}
			else if (this->iActualRightItem == 2)//new
			{
				if (this->profiles->getSize() < 5)
				{
					return 3;
				}
				else
				{
					return 0;
				}
			}
			else if (this->iActualRightItem == 3)
			{
				this->iActualMenu = 2;
				this->iActualItem = 1;
				this->iActualRightItem = 1;
				this->bRight = false;
				this->iMenuSize = this->profiles->getSize();
				this->iRightMenuSize = 2;
				return 0;

			}
		}
	}
	else if (this->iActualMenu == 4)
	{
		if (bRight)
		{
			if (this->iActualRightItem == 1)//play
			{
				iDynamites = this->iDynamites;
				iBombs = this->iBombs;
				currentProfile = this->profiles->getProfile(this->iActualProfile);
				return 4;
			}
		}
		else
		{
			
			if (this->iActualItem == 1)
			{
				if (this->profiles->getProfile(this->iActualProfile)->getTechTree()[1])
				{

					return 0;
				}
				else
				{
					if (this->profiles->getProfile(this->iActualProfile)->getPoints() >= 200)
					{
						this->profiles->getProfile(this->iActualProfile)->getTechTree()[1] = true;
						this->profiles->getProfile(this->iActualProfile)->setPoints(this->profiles->getProfile(this->iActualProfile)->getPoints() - 200);
						return 0;
					}
				}
			}
			else if (this->iActualItem == 2)
			{
				if (this->profiles->getProfile(this->iActualProfile)->getTechTree()[2])
				{
					if (this->profiles->getProfile(this->iActualProfile)->getPoints() >= 20)
					{
						this->profiles->getProfile(this->iActualProfile)->setPoints(this->profiles->getProfile(this->iActualProfile)->getPoints() - 20);
						this->iBombs++;
						return 0;
					}
				}
				else
				{
					if (this->profiles->getProfile(this->iActualProfile)->getPoints() >= 400)
					{
						this->profiles->getProfile(this->iActualProfile)->getTechTree()[2] = true;
						this->profiles->getProfile(this->iActualProfile)->setPoints(this->profiles->getProfile(this->iActualProfile)->getPoints() - 400);
						return 0;
					}
				}
			}
			else if (this->iActualItem == 3)
			{
				if (this->profiles->getProfile(this->iActualProfile)->getTechTree()[3])
				{
					if (this->profiles->getProfile(this->iActualProfile)->getPoints() >= 40)
					{
						this->profiles->getProfile(this->iActualProfile)->setPoints(this->profiles->getProfile(this->iActualProfile)->getPoints() - 40);
						this->iDynamites++;
						return 0;
					}
					
				}
				else
				{
					if (this->profiles->getProfile(this->iActualProfile)->getPoints() >= 800)
					{
						this->profiles->getProfile(this->iActualProfile)->getTechTree()[3] = true;
						this->profiles->getProfile(this->iActualProfile)->setPoints(this->profiles->getProfile(this->iActualProfile)->getPoints() - 800);
						return 0;
					}
				}
			}
		}
	}
}

void Menu::Draw(sf::RenderWindow &window)
{
	if (this->iActualMenu == 1)
	{
		sf::Text Play;
		sf::Text Save;
		sf::Text Exit;
		Play.setFont(Font);
		Play.setCharacterSize(50);
		Play.setString("Play");
		Play.setPosition(20, 200);
		Save.setFont(Font);
		Save.setCharacterSize(50);
		Save.setString("Save");
		Save.setPosition(20, 300);
		Exit.setFont(Font);
		Exit.setCharacterSize(50);
		Exit.setString("Exit");
		Exit.setPosition(20, 400);
		if (this->iActualItem == 1)
		{
			Play.setColor(sf::Color::Red);
			Save.setColor(sf::Color::Green);
			Exit.setColor(sf::Color::Green);
		}
		else if (this->iActualItem == 2)
		{
			Play.setColor(sf::Color::Green);
			Save.setColor(sf::Color::Red);
			Exit.setColor(sf::Color::Green);
		}
		else if (this->iActualItem == 3)
		{
			Play.setColor(sf::Color::Green);
			Save.setColor(sf::Color::Green);
			Exit.setColor(sf::Color::Red);
		}
		window.draw(Play);
		window.draw(Save);
		window.draw(Exit);
	}
	else if (this->iActualMenu == 2)
	{
		sf::Text Profile[5];
		sf::Text Edit;
		sf::Text Back;
		Back.setFont(this->Font);
		Back.setCharacterSize(50);
		Back.setString("Back");
		Back.setPosition(350, 400);
		Edit.setFont(this->Font);
		Edit.setCharacterSize(50);
		Edit.setString("Edit");
		Edit.setPosition(350, 300);
		if (this->bRight)
		{
			if (this->iActualRightItem == 1)
			{
				Edit.setColor(sf::Color::Red);
			}
			else if (this->iActualRightItem == 2)
			{
				Back.setColor(sf::Color::Red);
			}
		}
		for (int i = 0; i < this->profiles->getSize(); i++)
		{
			Profile[i].setFont(this->Font);
			Profile[i].setCharacterSize(50);
			Profile[i].setString(this->profiles->getProfile(i)->getName());
			Profile[i].setPosition(20, 100 * i);
			if (this->iActualItem == i + 1)
			{
				Profile[i].setColor(sf::Color::Red);
			}
			else
			{
				Profile[i].setColor(sf::Color::Green);
			}

			window.draw(Profile[i]);
			
		}
		window.draw(Edit);
		window.draw(Back);

	}
	else if (this->iActualMenu == 3)
	{
		sf::Text Back;
		Back.setFont(this->Font);
		Back.setCharacterSize(50);
		Back.setString("Back");
		sf::Text Delete;
		Delete.setFont(this->Font);
		Delete.setCharacterSize(50);
		Delete.setString("Delete");
		sf::Text New;
		New.setFont(this->Font);
		New.setCharacterSize(50);
		New.setString("New");
		Back.setPosition(350, 400);
		New.setPosition(350, 300);
		Delete.setPosition(350, 200);


		if (this->bRight)
		{
			if (this->iActualRightItem == 1)
			{
				Delete.setColor(sf::Color::Red);
			}
			else if (this->iActualRightItem == 2)
			{
				New.setColor(sf::Color::Red);
			}
			else if (this->iActualRightItem == 3)
			{
				Back.setColor(sf::Color::Red);
			}
		}
		sf::Text Profile[5];
		for (int i = 0; i < this->profiles->getSize(); i++)
		{
			Profile[i].setFont(this->Font);
			Profile[i].setCharacterSize(50);
			Profile[i].setString(this->profiles->getProfile(i)->getName());
			Profile[i].setPosition(20, 100 * i);
			if (this->iActualItem == i + 1)
			{
				Profile[i].setColor(sf::Color::Red);
			}
			else
			{
				Profile[i].setColor(sf::Color::Green);
			}

			window.draw(Profile[i]);

		}
		window.draw(New);
		window.draw(Back);
		window.draw(Delete);
	}
	else if (this->iActualMenu == 4)
	{
		sf::Text Points;
		Points.setFont(this->Font);
		Points.setCharacterSize(30);
		Points.setString("Points: " + std::to_string(this->profiles->getProfile(this->iActualProfile)->getPoints()));
		Points.setPosition(300, 30);
		sf::Text Play;
		Play.setFont(this->Font);
		Play.setCharacterSize(30);
		Play.setString("Play");
		Play.setPosition(400, 60);
		sf::Text Pickaxe;
		Pickaxe.setFont(this->Font);
		Pickaxe.setCharacterSize(30);
		Pickaxe.setString("Pickaxe");
		Pickaxe.setPosition(0, 90);
		sf::Text SuperPickaxe;
		SuperPickaxe.setFont(this->Font); 
		SuperPickaxe.setCharacterSize(30);
		SuperPickaxe.setString("SuperPickaxe");
		SuperPickaxe.setPosition(0, 120);
		sf::Text Bomb;
		Bomb.setFont(this->Font);
		Bomb.setCharacterSize(30);
		Bomb.setString("Bomb");
		Bomb.setPosition(0, 150);
		sf::Text Dynamite;
		Dynamite.setFont(this->Font);
		Dynamite.setCharacterSize(30);
		Dynamite.setString("Dynamite");
		Dynamite.setPosition(0, 180);
		bool* currentTechTree = this->profiles->getProfile(this->iActualProfile)->getTechTree();
		if (this->bRight)
		{
			Play.setColor(sf::Color::Red);
		}
		if (!(currentTechTree[1]))
		{
			sf::Text Unlock;
			Unlock.setFont(this->Font);
			Unlock.setCharacterSize(30);
			Unlock.setString("Unlock (200)");
			Unlock.setPosition(250, 120);
			if (this->iActualItem == 1)
			{
				Unlock.setColor(sf::Color::Red);
			}
			window.draw(Unlock);
		}
		else
		{
			sf::Text Unlocked;
			Unlocked.setFont(this->Font);
			Unlocked.setCharacterSize(30);
			Unlocked.setString("Unlocked :D");
			Unlocked.setPosition(250, 120);
			if (this->iActualItem == 1)
			{
				Unlocked.setColor(sf::Color::Red);
			}
			window.draw(Unlocked);
		}
		if (currentTechTree[2])
		{
			sf::Text Buy;
			Buy.setFont(this->Font);
			Buy.setCharacterSize(30);
			Buy.setString("Buy (20)  "+std::to_string(this->iBombs));
			Buy.setPosition(250, 150);
			if (this->iActualItem == 2)
			{
				Buy.setColor(sf::Color::Red);
			}
			window.draw(Buy);
		}
		else
		{
			sf::Text Unlock;
			Unlock.setFont(this->Font);
			Unlock.setCharacterSize(30);
			Unlock.setString("Unlock (400)");
			Unlock.setPosition(250, 150);
			if (this->iActualItem == 2)
			{
				Unlock.setColor(sf::Color::Red);
			}
			window.draw(Unlock);
		}
		if (currentTechTree[3])
		{
			sf::Text Buy;
			Buy.setFont(this->Font);
			Buy.setCharacterSize(30);
			Buy.setString("Buy (40)   " + std::to_string(this->iDynamites));
			Buy.setPosition(250, 180);
			if (this->iActualItem == 3)
			{
				Buy.setColor(sf::Color::Red);
			}
			window.draw(Buy);
		}
		else
		{
			sf::Text Unlock;
			Unlock.setFont(this->Font);
			Unlock.setCharacterSize(30);
			Unlock.setString("Unlock (800)");
			Unlock.setPosition(250, 180);
			if (this->iActualItem == 3)
			{
				Unlock.setColor(sf::Color::Red);
			}
			window.draw(Unlock);
		}
		window.draw(Play);
		window.draw(Points);
		window.draw(Pickaxe);
		window.draw(SuperPickaxe);
		window.draw(Bomb);
		window.draw(Dynamite);


	}


}
Menu::~Menu()
{
}
