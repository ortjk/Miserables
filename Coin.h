#include "Police.h"

class Coin : public Entity
{
private:
public:
	Coin(Visuals* v, EntityType type, int xpos = 0, int ypos = 0);
	virtual ~Coin();
};