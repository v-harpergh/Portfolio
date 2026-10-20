module;

#include <raylib.h>

export module features.player;

import features.scene;

export class Player {
public:
	explicit Player(int x, int y) : position_(static_cast<float>(x), static_cast<float>(y)) {};
	explicit Player(float x, float y) : position_(x, y) {};

	void draw(float deltaTime);

	void addX(float x);
	void addY(float y);

	scene::Tile getTile();

	void addTreasure(int value);

	int getTreasure();
	float getOxygen();

private:
	int treasure_ = 0;
	float oxygen_ = 100;

	Vector2 position_{};
};