#include "Entity.h"

class Pickup : public Entity
{
private:
public:
	Pickup(Visuals* v, EntityType type, int xpos = 0, int ypos = 0);
	virtual ~Pickup();
};