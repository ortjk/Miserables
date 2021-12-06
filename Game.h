#include "State.h"

class Game
{
private:
	//variables
	sf::RenderWindow window;

	sf::Clock clock;
	sf::Clock totalClock;
	float lastTime = 2.f;

	State state;
	//initializers
	void initVariables();

public:
	Game();
	virtual ~Game();

	void run();
};