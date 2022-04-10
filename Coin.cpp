#include "Coin.h"
Coin::Coin(Visuals* v, EntityType type, int xpos, int ypos) :
	Entity(v, type, xpos, ypos)
{
	speed = 0.5f;
}

Coin::~Coin()
{
}
