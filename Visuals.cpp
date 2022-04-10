#include "Visuals.h"
Visuals::Visuals()
{
	if (!this->spriteSheet.loadFromFile("Untitled.png"))
	{
		std::cout << "ERROR COULD NOT LOAD TEXTURE\n";
	}
	if (!this->backgroundTexture.loadFromFile("background.png"))
	{
		std::cout << "ERROR COULD NOT LOAD BACKGROUND TEXTURE\n";
	}
	background.setTexture(backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, 128, 72));
	background.setScale(sf::Vector2f(10, 10));
}

Visuals::~Visuals()
{
}

void Visuals::addSprite(EntityType type, int xpos, int ypos, int code)
{
	sf::Sprite sprite;
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(sf::IntRect(32 * code, 32 * EntityType(type), 32, 32));
	sprite.setOrigin(sf::Vector2f(16.f, 0.f));
	sprite.setPosition(sf::Vector2f(xpos, ypos));
	sprite.setScale(sf::Vector2f(8, 8));

	sprites.push_back(sprite);

	this->addHitbox(xpos, ypos);
}

void Visuals::removeSprite(int indexNum)
{
	sprites.erase(sprites.begin() + indexNum);
	this->removeHitbox(indexNum);
}

sf::Sprite& Visuals::getSprite(int indexNum)
{
	return sprites[indexNum];
}

sf::Sprite& Visuals::getBackground()
{
	if (bgDeltaFrames >= 6)
	{
		background.setTextureRect(sf::IntRect(bgCurrentFrame, 0, 128, 72));
		if (bgCurrentFrame <= 256)
		{
			bgCurrentFrame++;
		}
		else
		{
			bgCurrentFrame = 0;
		}
		bgDeltaFrames = 0;
	}
	else
	{
		bgDeltaFrames++;
	}
	return background;
}

void Visuals::setSpritePos(int indexNum, int xpos, int ypos)
{
	sprites[indexNum].setPosition(sf::Vector2f(xpos, ypos));

	this->setHitboxPos(indexNum, xpos, ypos);
}

void Visuals::flipSprite(int indexNum)
{
	sprites[indexNum].scale(-1.f, 1.f);
}

void Visuals::updateSprite(Direction ndir, Direction& odir)
{

	switch (ndir)
	{
		case LEFT:
		case RIGHT:
			if (deltaFrames >= 64)
			{
				//sprites[0].setScale(sf::Vector2f(0.125f, 0.125f));
				sprites[0].setTextureRect(sf::IntRect(32 * currentFrame, 32 * 4, 32, 32));
				//sprites[0].setScale(sf::Vector2f(8.f, 8.f));
				if (currentFrame == 3)
				{
					currentFrame = 0;
				}
				else
				{
					currentFrame++;
				}
				deltaFrames = 0;
			}
			else
			{
				deltaFrames++;
			}

			if (ndir != odir)
			{
				this->flipSprite(0);
			}
			break;

		case UP:
		case DOWN:
		default:
			break;
	}
}

bool Visuals::hitboxIntersectsWithPlayer(int indexNum)
{
	if (rects[0].intersects(rects[indexNum]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Visuals::addHitbox(int xpos, int ypos)
{
	sf::IntRect r = sf::Rect(xpos, ypos, 128, 32);
	rects.push_back(r);
}

void Visuals::removeHitbox(int indexNum)
{
	rects.erase(rects.begin() + indexNum);
}

void Visuals::setHitboxPos(int indexNum, int xpos, int ypos)
{
	rects[indexNum].left = xpos;
	rects[indexNum].top = ypos;
}