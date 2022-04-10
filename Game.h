#include "State.h"

class Game
{
private:
	//variables
	sf::RenderWindow window;

	sf::Font gameFont;
	sf::Font cutsceneFont;

	sf::Text scoreText;
	sf::Text timeText;
	sf::Text cutsceneText1;
	sf::Text cutsceneText2;
	sf::Text cutsceneText3;
	sf::Text skipText;

	sf::Clock clock;
	sf::Clock totalClock;
	float lastTimeC = 2.f;
	float lastTimeO = 1.f;

	State* state;
	int stage = 0;
	//initializers
	void initVariables();

public:
	Game();
	virtual ~Game();

	void run();
};