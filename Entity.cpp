#include "Entity.h"
Entity::Entity(Visuals* v, EntityType type, int xpos, int ypos, int code) :
	vis(v),
	etype(type),
	xposition(xpos),
	yposition(ypos)
{
	vis->addSprite(etype, xposition, ((yposition * 190) + 120), code);
}

Entity::~Entity()
{
}

void Entity::move(int indexNum, Direction dir)
{
	switch (dir)
	{
		case LEFT:
			if (xposition > 0)
			{
				xposition -= (speed);
			}
			break;
		case RIGHT:
			if (xposition < 1100)
			{
				xposition += (speed);
			}
			break;
		case UP:
			if (yposition > 0)
			{
				yposition--;
			}
			break;
		case DOWN:
			if (yposition < 2)
			{
				yposition++;
			}
			break;
		default:
			break;
	}
	vis->setSpritePos(indexNum, xposition, (yposition * 190) + 120);
}

void Entity::setSpeed(float nspeed)
{
	this->speed = nspeed;
}

float& Entity::getSpeed()
{
	return this->speed;
}

int& Entity::getXPosition()
{
	return xposition;
}

int& Entity::getYPosition()
{
	return xposition;
}

Direction& Entity::getDirection()
{
	return dir;
}

void Entity::setDirection(Direction direction)
{
	switch (direction)
	{
		case LEFT:
		case RIGHT:
			dir = direction;
			break;
		default:
			break;
	}
}

EntityType& Entity::getType()
{
	std::cout << etype << "\n";
	return etype;
}