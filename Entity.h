#include "Visuals.h"

class Entity
{
private:
protected:
	//do not change order, you will have to change the orders in the constructors
	Visuals* vis;
	EntityType etype;
	int xposition;
	int yposition;

	float speed = 1.f;

public:
	Entity(Visuals* v, EntityType type, int xpos = 0, int ypos = 0);
	virtual ~Entity();
	void move(int indexNum, Direction dir, float& dt);
	int& getXPosition();
};