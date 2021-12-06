#include "Player.h"

class State
{
private:
	Visuals* vis;
	Player* p;
	std::vector<Coin*> coins;

	int coinsCollected = 0;

public:
	State();
	virtual ~State();

	void removeCoin(int indexNum);

	void moveEntity(EntityType type, Direction dir, float& dt);
	void addCoin();
	void checkCollisions();

	int getCoinsCollected();
	void getVisuals(sf::RenderWindow* w);
};