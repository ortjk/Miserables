#include "Game.h"

void Game::initVariables()
{
	window.create(sf::VideoMode(1280, 720), "Game", sf::Style::Default);
}

Game::Game()
{
	this->initVariables();
}

Game::~Game()
{
}

void Game::run()
{
	while (this->window.isOpen())
	{
		//necessary because code is currently too fast otherwise, so delta time sometimes rounds to zero
		for (int i = 0; i < 100000; i++)
		{
			for (int x = 0; x < 100; x++)
			{
			}
		}

		float deltaTime = clock.restart().asMilliseconds();
		//std::cout << deltaTime << "\n";
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					this->window.close();
					break;
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							state.moveEntity(PLAYER, UP, deltaTime);
							break;
						case sf::Keyboard::Down:
							state.moveEntity(PLAYER, DOWN, deltaTime);
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			state.moveEntity(PLAYER, LEFT, deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			state.moveEntity(PLAYER, RIGHT, deltaTime);
		}

		state.moveEntity(COIN, LEFT, deltaTime);

		//add coin every 2 seconds
		if (lastTime - totalClock.getElapsedTime().asSeconds() <= 0)
		{
			lastTime += 2.f;
			state.addCoin();
		}

		//push frames
		this->window.clear();

		state.getVisuals(&this->window);
		//this->window.draw(state.getVisuals());

		this->window.display();
	}
}