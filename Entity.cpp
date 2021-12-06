#include "Entity.h"
Entity::Entity(Visuals* v, EntityType type, int xpos, int ypos) :
	vis(v),
	etype(type),
	xposition(xpos),
	yposition(ypos)
{
	vis->addSprite(etype, xposition, ((yposition * 240) + 120));
}

Entity::~Entity()
{
}

void Entity::move(int indexNum, Direction dir, float& dt)
{
	switch (dir)
	{
		case LEFT:
			if (xposition > 0)
			{
				xposition -= (dt * speed);
			}
			break;
		case RIGHT:
			if (xposition < 1248)
			{
				xposition += (dt * speed);
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
	vis->setSpritePos(indexNum, xposition, (yposition * 240) + 120);
}

int& Entity::getXPosition()
{
	return xposition;
}