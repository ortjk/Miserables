#include "Visuals.h"

class Entity
{
private:
protected:
	//do not change order, you will have to change the orders in the constructors
	Visuals* vis;
	EntityType etype;
	Direction dir = RIGHT;

	int xposition;
	int yposition;

	float speed = 1.f;

public:
	Entity(Visuals* v, EntityType type, int xpos = 80, int ypos = 0, int code = 0);
	virtual ~Entity();

	void move(int indexNum, Direction dir);

	void setSpeed(float nspeed);
	float& getSpeed();

	int& getXPosition();
	int& getYPosition();

	Direction& getDirection();
	void setDirection(Direction direction);

	EntityType& getType();
};