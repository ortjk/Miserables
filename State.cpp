#include "State.h"
State::State()
{
	vis = new Visuals;
	snd = new Sounds;
	Player* p = new Player(vis, PLAYER, 300, 1);
	entities.push_back(p);
	p->setDirection(LEFT);
	vis->flipSprite(0);
}

State::~State()
{
	delete this->vis;
	delete this->snd;
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}

void State::removeEntity(int indexNum)
{
	vis->removeSprite(indexNum);
	delete this->entities[indexNum];
	entities.erase(entities.begin() + indexNum);
}

void State::moveEntity(EntityType type, Direction dir)
{
	switch (type)
	{
		case PLAYER:
			entities[0]->move(0, dir);
			vis->updateSprite(dir, entities[0]->getDirection());
			entities[0]->setDirection(dir);
			break;
		case COIN:
			for (unsigned int i = 1; i < entities.size(); i++)
			{
				if (entities[i]->getType() == COIN)
				{
					entities[i]->move(i, dir);
					if (entities[i]->getXPosition() < 1)
					{
						this->removeEntity(i);
					}
					if (this->checkCollisions(i))
					{
						this->removeEntity(i);
						coinsCollected++;
					}
				}
			}
			break;
		case OBSTACLE:
			for (unsigned int i = 1; i < entities.size(); i++)
			{
				if (entities[i]->getType() == OBSTACLE)
				{
					entities[i]->move(i, dir);
					if (entities[i]->getXPosition() < 1)
					{
						this->removeEntity(i);
					}
					if (this->checkCollisions(i))
					{
						this->died = true;
					}
				}
			}
			break;
		case POLICE:
			for (unsigned int i = 1; i < entities.size(); i++)
			{
				if (entities[i]->getType() == POLICE)
				{
					entities[i]->move(i, dir);
				}
			}
			break;
		default:
			break;
	}
}

void State::addCoin(int lane)
{
	Coin* c = new Coin(vis, COIN, 1200, lane);
	entities.push_back(c);
}

void State::addObstacle(int lane, int code)
{
	Obstacle* o = new Obstacle(vis, OBSTACLE, 1400, lane, code);
	entities.push_back(o);
}

void State::addPolice(int lane, int code)
{
	Police* p = new Police(vis, POLICE, 80, lane, code);
	entities.push_back(p);
}

void State::addEntity(EntityType type, int lane, int code)
{
	switch (type)
	{
		case COIN:
			this->addCoin(lane);
			break;
		case OBSTACLE:
			this->addObstacle(lane, code);
			break;
		case POLICE:
			this->addPolice(lane, code);
			break;
		default:
			break;
	}
}

void State::setEntitySpeed(int index, float speed)
{
	entities[index]->setSpeed(speed);
}

Entity* State::getEntity(int i)
{
	return this->entities[i];
}

unsigned int State::getNumOfEntities()
{
	return this->entities.size();
}

void State::increasesEntitySpeed(EntityType type)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getType() == type)
		{
			entities[i]->setSpeed(entities[i]->getSpeed() + 0.00005f);
		}
	}
}

void State::playDialogue(DialogueCode code)
{
	snd->playSound(code);
}

bool State::hasAudioFinished()
{
	if (this->snd->getSound().getStatus() == sf::Sound::Stopped)
	{
		return true;
	}
	return false;
}

bool State::checkCollisions(unsigned int& i)
{

	if (vis->hitboxIntersectsWithPlayer(i))
	{
		return true;
	}
	return false;
}

int State::getCoinsCollected()
{
	return this->coinsCollected;
}

void State::getVisuals(sf::RenderWindow* w)
{
	w->draw(vis->getBackground());
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		w->draw(vis->getSprite(i));
	}
}

void State::reset()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
	delete this->vis;
	vis = new Visuals;
	Player* p = new Player(vis, PLAYER);

	entities.push_back(p);
}

bool& State::hasDied()
{
	return this->died;
}