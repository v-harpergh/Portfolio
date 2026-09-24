module;

#include <raylib.h>

export module features.character;

export class Player {
public:
	explicit Player(int x, int y) : position(static_cast<float>(x), static_cast<float>(y)) {};
	explicit Player(float x, float y): position(x, y) {};

private:
	Vector2 position{};
};