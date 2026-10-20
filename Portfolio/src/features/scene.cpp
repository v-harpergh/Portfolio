#include <vector>

#include <raylib.h>
#include <raymath.h>

import features.scene;

import rendering;
import constants;

constexpr int OceanOffset = constants::tile_size * 2;

constexpr Color TileColor = Color{ 0, 0, 0, 65 };
constexpr Color WaterColor = Color{ 112, 196, 255, 255 };
constexpr Color SkyColor = Color{ 220, 220, 255, 255 };

namespace {
std::vector<scene::Treasure> treasures;
}

constexpr unsigned char waterColor(unsigned char color, int depth) {
	return static_cast<unsigned char>(color - depth / 3.5);
}

void scene::initializeTreasures() {
	treasures = {
		{ { 4, 3 }, 100 },
		{ { 1, 6 }, 250 },
		{ { 12, 7 }, 400 }
	};
}

void scene::resetTreasures() {
	for (Treasure& treasure : treasures) {
		treasure.collected = false;
	}
}

int scene::collectTreasure(const Tile& tile) {
	for (Treasure& treasure : treasures) {
		if (treasure.collected) {
			continue;
		}

		if (treasure.tile == tile) {
			treasure.collected = true;
			return treasure.value;
		}
	}

	return 0;
}

int scene::getTreasureAtPosition(float x, float y) {
	for (Treasure& treasure : treasures) {
		if (treasure.collected) {
			continue;
		}

		Vector2 tPos = Vector2{ static_cast<float>(treasure.tile.x * constants::tile_size + constants::tile_size / 2), static_cast<float>(treasure.tile.y * constants::tile_size + constants::tile_size / 2) };
		Vector2 pos = Vector2{ x, y };

		float distance = Vector2Distance(tPos, pos);

		if (distance < constants::tile_size / 2) {
			return treasure.value;
		}
	}

	return 0;
}

size_t scene::getTreasureCount() {
	size_t count = 0;

	for (const auto& t : treasures) {
		if (t.collected != true) {
			++count;
		}
	}
	return count;
}

void drawOcean() {
	for (int i = 0; i < constants::window::y; i += constants::tile_size) {
		if (i < OceanOffset) {
			DrawRectangle(0, i, constants::window::x, constants::window::y - OceanOffset, SkyColor);
		}
		else {
			DrawRectangle(0, i, constants::window::x, constants::window::y - OceanOffset, Color{
				waterColor(WaterColor.r, i),
				waterColor(WaterColor.g, i),
				waterColor(WaterColor.b, i),
				255
				});
		}
	}
}

void drawTreasures() {
	for (const scene::Treasure& treasure : treasures) {
		if (treasure.collected) {
			continue;
		}

		const int x = treasure.tile.x * constants::tile_size + constants::tile_size / 2;
		const int y = treasure.tile.y * constants::tile_size + constants::tile_size / 2;

		DrawCircle(x, y, 10, BLACK);
		DrawCircle(x, y, 8, GOLD);
	}
}

void drawTiles() {
	for (int i = 0; i < constants::window::x; i += constants::tile_size) {
		DrawRectangle(i, 0, 2, constants::window::y, TileColor);
	}

	for (int i = 0; i < constants::window::y; i += constants::tile_size) {
		DrawRectangle(0, i, constants::window::x, 2, TileColor);
	}
}

void scene::draw(double) {
	ClearBackground(RAYWHITE);

	drawOcean();
	drawTreasures();
	drawTiles();
}