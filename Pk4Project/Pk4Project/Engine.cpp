#include "Engine.h"
Engine::Engine()
{
}
void Engine::startGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	Map Mapa;
	srand(time(0));
	Mapa.generateMap();
	window.setFramerateLimit(60);
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
Engine::~Engine()
{
}