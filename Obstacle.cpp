#include "Obstacle.h"
Obstacle::Obstacle(Visuals* v, EntityType type, int xpos, int ypos, int code) :
	Entity(v, type, xpos, ypos, code)
{
	speed = 0.8f;
}

Obstacle::~Obstacle()
{
}
