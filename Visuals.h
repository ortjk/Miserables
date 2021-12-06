#include "Enums.h"

class Visuals
{
private:
	sf::Texture spriteSheet;

	sf::Sprite emptySprite;
	std::vector<sf::Sprite> sprites;

public:
	Visuals();
	virtual ~Visuals();

	void addSprite(EntityType type, int xpos, int ypos);
	void removeSprite(int indexNum);
	sf::Sprite& getSprite(int indexNum);
	void setSpritePos(int indexNum, int xpos, int ypos);
};