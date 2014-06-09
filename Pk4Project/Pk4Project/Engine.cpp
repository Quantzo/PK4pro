#include "Engine.h"

Engine::Engine()
{
	this->currentProfile = NULL;
	this->bMenu = true;
	this->bGame = false;
	this->brun = true;
	this->profiles = new ProfilesContainer();
	this->profiles->Load("save.xml");
}
void Engine::startGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	
	srand(time(0));	
	window.setFramerateLimit(60);

	while (this->brun)
	{
		if (bMenu)
		{
			this->startMenu(window);
		}
		if (bGame)
		{
			Map Mapa(this->iBombs, this->iDynamites, this->currentProfile);
			Mapa.generateMap();
			sf::Clock clock;
			sf::Time time = clock.getElapsedTime();
			while (window.isOpen() && (int)time.asSeconds() < 30)
			{
				time = clock.getElapsedTime();
				sf::Event event;
				sf::Text Timer;
				sf::Font font;
				font.loadFromFile("C:\\Users\\Quantzo\\Source\\Repos\\ProjektPK4\\Pk4Project\\Pk4Project\\Cinta Adalah Perhatian.ttf");
				Timer.setFont(font);
				Timer.setCharacterSize(15);
				Timer.setString(std::to_string(120 - (int)time.asSeconds()));
				Timer.setPosition(470, 0);
				Timer.setColor(sf::Color::Black);

				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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
				window.draw(Timer);
				window.display();
			}
			this->bGame = false;
			this->bMenu = true;
		}
	}
}


void Engine::startMenu(sf::RenderWindow &window)
{
	Menu menu(profiles);
	while (bMenu)
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
				int request = menu.useOption(this->iBombs, this->iDynamites, this->currentProfile);
				if (request == 1)//save profiles
				{
					this->profiles->Save();
				}
				else if (request == 2) //exit
				{
					window.close();
					this->brun = false;
					return;
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
				else if (request == 4)
				{
					this->bGame = true;
					this->bMenu = false;
					return;
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