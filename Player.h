#include "Coin.h"

class Player : public Entity
{
private:
public:
	Player(Visuals* v, EntityType type, int xpos = 0, int ypos = 0);
	virtual ~Player();
};