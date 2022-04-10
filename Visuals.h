#include "Sounds.h"

class Visuals
{
private:
	sf::Texture spriteSheet;
	sf::Texture backgroundTexture;

	std::vector<sf::Sprite> sprites;
	sf::Sprite background;

	std::vector<sf::IntRect> rects;

	int deltaFrames = 0;
	int bgDeltaFrames = 0;
	int currentFrame = 0;
	int bgCurrentFrame = 0;

	void addHitbox(int xpos, int ypos);
	void removeHitbox(int indexNum);
	void setHitboxPos(int indexNum, int xpos, int ypos);

public:
	Visuals();
	virtual ~Visuals();

	void addSprite(EntityType type, int xpos, int ypos, int code);
	void removeSprite(int indexNum);
	sf::Sprite& getSprite(int indexNum);
	sf::Sprite& getBackground();
	void setSpritePos(int indexNum, int xpos, int ypos);
	void flipSprite(int indexNum);
	void updateSprite(Direction ndir, Direction& odir);

	bool hitboxIntersectsWithPlayer(int indexNum);
};