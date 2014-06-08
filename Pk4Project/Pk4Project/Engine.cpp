#include "Engine.h"

Engine::Engine()
{
	this->bMenu = true;
	this->bGame = false;
	this->profiles = new ProfilesContainer();
	this->profiles->Load("C:\\Users\\Quantzo\\Source\\Repos\\ProjektPK4\\Pk4Project\\Pk4Project\\save2.txt");
}
void Engine::startGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	
	srand(time(0));	
	window.setFramerateLimit(60);

	if (bMenu)
	{
		this->startMenu(window);
	}
	else if (bGame)
	{
		Map Mapa;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				Mapa.movePlayer(1);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				Mapa.movePlayer(2);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				Mapa.movePlayer(3);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				Mapa.movePlayer(4);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				Mapa.changeTool(1);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				Mapa.changeTool(2);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				Mapa.changeTool(3);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				Mapa.changeTool(4);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				Mapa.useTool();
			}
			Mapa.handleEvents();
			window.clear();
			Mapa.draw(window);
			window.display();
		}
	}
}


void Engine::startMenu(sf::RenderWindow &window)
{
	Menu menu(profiles);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
			{
				menu.selectOption(1);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
			{
				menu.selectOption(2);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
			{
				menu.selectOption(3);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
			{
				menu.selectOption(4);
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				int request = menu.useOption();
				if (request == 1)//save profiles
				{
					this->profiles->Save();
				}
				else if (request == 2) //exit
				{
					window.close();
				}
				else if (request == 3)
				{
					bool bResult = true;
					sf::String profileName;
					while (bResult)
					{
						while (window.pollEvent(event))
						{
							if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
							{
								bResult = false;
							}
							else if (event.type == sf::Event::TextEntered)
							{
								if (event.text.unicode > 47 && event.text.unicode < 123)
								{
									profileName += event.text.unicode;
								}
							}
							
						}
						sf::Text Player;
						sf::Font font;
						font.loadFromFile("C:\\Users\\Quantzo\\Source\\Repos\\ProjektPK4\\Pk4Project\\Pk4Project\\Cinta Adalah Perhatian.ttf");
						Player.setFont(font);
						Player.setCharacterSize(50);
						Player.setString(profileName);
						Player.setPosition(20, 200);
						window.clear();
						window.draw(Player);						
						window.display();
					}
					Profile tmp;
					tmp.setName(profileName);
					this->profiles->addProfile(tmp);
				}
			}
		}
		window.clear();
		menu.Draw(window);
		window.display();
	}
}

Engine::~Engine()
{
	delete this->profiles;
}