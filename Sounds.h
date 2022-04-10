#include "Enums.h"

class Sounds
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;

public:
	Sounds();
	virtual ~Sounds();

	void playSound(DialogueCode type);
	sf::Sound& getSound();
};