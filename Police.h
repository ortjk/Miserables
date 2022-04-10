#include "Obstacle.h"

class Police : public Entity
{
private:
public:
	Police(Visuals* v, EntityType type, int xpos = 0, int ypos = 0, int code = 0);
	virtual ~Police();
};