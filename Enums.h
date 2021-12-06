#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <random>
#include <vector>

enum EntityType
{
	PLAYER,
	COIN
};

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};