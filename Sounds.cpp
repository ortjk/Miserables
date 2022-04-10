#include "Sounds.h"

Sounds::Sounds()
{
}

Sounds::~Sounds()
{
}

void Sounds::playSound(DialogueCode code)
{
	switch (code)
	{
		case INTRO_1:
			if (!this->buffer.loadFromFile("Les_miserables_intro.wav"))
			{
				std::cout << "ERROR COULD NOT LOAD SOUND\n";
			}
			sound.setBuffer(buffer);
			sound.setVolume(50.f);
			sound.play();
			break;
		case CAUGHT_1:
			if (!this->buffer.loadFromFile("Les_miserables_caught1.wav"))
			{
				std::cout << "ERROR COULD NOT LOAD SOUND\n";
			}
			sound.setBuffer(buffer);
			sound.setVolume(50.f);
			sound.play();
			break;
		case MID_CUTSCENE:
			if (!this->buffer.loadFromFile("Les_miserables_mmadeleine.wav"))
			{
				std::cout << "ERROR COULD NOT LOAD SOUND\n";
			}
			sound.setBuffer(buffer);
			sound.setVolume(50.f);
			sound.play();
			break;
		case INTRO_2:
			if (!this->buffer.loadFromFile("Les_miserables_run_start_2.wav"))
			{
				std::cout << "ERROR COULD NOT LOAD SOUND\n";
			}
			sound.setBuffer(buffer);
			sound.setVolume(50.f);
			sound.play();
			break;
		case BAD_ENDING:
			if (!this->buffer.loadFromFile("Les_miserables_bad_end.wav"))
			{
				std::cout << "ERROR COULD NOT LOAD SOUND\n";
			}
			sound.setBuffer(buffer);
			sound.setVolume(50.f);
			sound.play();
			break;
		case GOOD_ENDING:
			if (!this->buffer.loadFromFile("Les_miserables_good_end.wav"))
			{
				std::cout << "ERROR COULD NOT LOAD SOUND\n";
			}
			sound.setBuffer(buffer);
			sound.setVolume(50.f);
			sound.play();
			break;
		default:
			break;
	}
}

sf::Sound& Sounds::getSound()
{
	return this->sound;
}