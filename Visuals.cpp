#include "Visuals.h"
Visuals::Visuals()
{
	if (!this->spriteSheet.loadFromFile("C:/Users/tgpor/Pictures/Saved Pictures/Sprite-0001.png"))
	{
		std::cout << "ERROR COULD NOT LOAD TEXTURE\n";
	}
}

Visuals::~Visuals()
{
}

void Visuals::addSprite(EntityType type, int xpos, int ypos)
{
	sf::Sprite sprite;
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(sf::IntRect(0, 32 * EntityType(type), 32, 32));
	sprite.setPosition(sf::Vector2f(xpos, ypos));

	sprites.push_back(sprite);
}

void Visuals::removeSprite(int indexNum)
{
	sprites.erase(sprites.begin() + indexNum);
}

sf::Sprite& Visuals::getSprite(int indexNum)
{
	return sprites[indexNum];
}

void Visuals::setSpritePos(int indexNum, int xpos, int ypos)
{
	sprites[indexNum].setPosition(sf::Vector2f(xpos, ypos));
}