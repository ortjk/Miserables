#include "Enums.h"

class Visuals
{
private:
	sf::Texture spriteSheet;

	std::vector<sf::Sprite> sprites;

	std::vector<sf::IntRect> rects;
	void addHitbox(int xpos, int ypos);
	void removeHitbox(int indexNum);
	void setHitboxPos(int indexNum, int xpos, int ypos);

public:
	Visuals();
	virtual ~Visuals();

	void addSprite(EntityType type, int xpos, int ypos);
	void removeSprite(int indexNum);
	sf::Sprite& getSprite(int indexNum);
	void setSpritePos(int indexNum, int xpos, int ypos);

	bool hitboxIntersectionWithPlayer(int indexNum);
};