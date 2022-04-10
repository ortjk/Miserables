#include "Player.h"

class State
{
private:
	Visuals* vis;
	Sounds* snd;
	std::vector<Entity*> entities;

	int coinsCollected = 0;
	bool died = false;

	void addCoin(int lane);
	void addObstacle(int lane, int code);
	void addPolice(int lane, int code);

	bool checkCollisions(unsigned int& i);

public:
	State();
	virtual ~State();

	void removeEntity(int indexNum);
	void moveEntity(EntityType type, Direction dir);
	void addEntity(EntityType type, int lane, int code = 0);
	void setEntitySpeed(int index, float speed);
	Entity* getEntity(int i);
	unsigned int getNumOfEntities();
	void increasesEntitySpeed(EntityType type);

	void playDialogue(DialogueCode code);
	bool hasAudioFinished();

	int getCoinsCollected();
	void getVisuals(sf::RenderWindow* w);

	bool& hasDied();

	void reset();
};