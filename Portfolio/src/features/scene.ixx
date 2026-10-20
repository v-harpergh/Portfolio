module;

#include <vector>

export module features.scene;

export namespace scene {

struct Tile {
	int x{};
	int y{};

	bool operator==(const Tile&) const = default;
};

struct Treasure {
	Tile tile;
	int value;
	bool collected = false;
};

void initializeTreasures();
void resetTreasures();

int collectTreasure(const Tile& tile);
size_t getTreasureCount();

int getTreasureAtPosition(float x, float y);

void draw(double deltaTime);

}