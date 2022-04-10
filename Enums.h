#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

enum EntityType
{
	PLAYER,
	COIN,
	OBSTACLE,
	POLICE
};

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum DialogueCode
{
	INTRO_1,
	CAUGHT_1,
	MID_CUTSCENE,
	INTRO_2,
	BAD_ENDING,
	GOOD_ENDING
};
