#include "State.h"
State::State()
{
	vis = new Visuals;
	p = new Player(vis, PLAYER);
}

State::~State()
{
	delete this->vis;
	delete this->p;
	if (coins.size() != 0)
	{
		for (unsigned int i = 0; i < coins.size(); i++)
		{
			delete coins[i];
		}
	}
}

void State::removeCoin(int indexNum)
{
	std::cout << "a coin was deleted\n";
	vis->removeSprite(indexNum + 1);
	delete this->coins[indexNum];
	coins.erase(coins.begin() + indexNum);
}

void State::moveEntity(EntityType type, Direction dir, float& dt)
{
	switch (type)
	{
		case PLAYER:
			p->move(0, dir, dt);
			break;
		case COIN:
			for (unsigned int i = 0; i < coins.size(); i++)
			{
				coins[i]->move(i + 1, dir, dt);
				if (coins[i]->getXPosition() < 1)
				{
					this->removeCoin(i);
				}
			}
		default:
			break;
	}
}

void State::addCoin()
{
	int r = rand() % 3;
	Coin* c = new Coin(vis, PLAYER, 1200, r);

	coins.push_back(c);
}

void State::checkCollisions()
{
}

void State::getVisuals(sf::RenderWindow* w)
{
	w->draw(vis->getSprite(0));
	if (coins.size() != 0)
	{
		for (unsigned int i = 1; i <= coins.size(); i++)
		{
			w->draw(vis->getSprite(i));
		}
	}
}