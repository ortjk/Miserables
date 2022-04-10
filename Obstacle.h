#include "Entity.h"

class Obstacle : public Entity
{
private:
public:
	Obstacle(Visuals* v, EntityType type, int xpos = 0, int ypos = 0, int code = 0);
	virtual ~Obstacle();
};