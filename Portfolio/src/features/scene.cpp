#include <raylib.h>

import features.scene;

import rendering;
import constants;

constexpr int OceanOffset = constants::tile_size * 2;

constexpr Color TileColor = Color{ 0, 0, 0, 65 };
constexpr Color WaterColor = Color{ 112, 196, 255, 255 };
constexpr Color SkyColor = Color{ 220, 220, 255, 255 };

constexpr unsigned char waterColor(unsigned char color, int depth) {
	return static_cast<unsigned char>(color - depth / 3.5);
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
	drawTiles();
}