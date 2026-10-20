#include <chrono>
#include <cstdint>
#include <iostream>

#include <raylib.h>

import rendering;
import constants;

import features.scene;
import features.player;

import resources.windows;

using SteadyClock = std::chrono::steady_clock;
using TimePoint = SteadyClock::time_point;

void rendering::initialize() {
	TimePoint lastRefresh = SteadyClock::now();

	InitWindow(constants::window::x, constants::window::y, constants::title.data());
	SetTargetFPS(60);

	Player player(100, 100);

	scene::initializeTreasures();

	while (!WindowShouldClose())
	{
		const auto now = SteadyClock::now();
		const float deltaTime = std::chrono::duration<float>(now - lastRefresh).count();

		if (IsKeyDown(KEY_W)) {
			player.addY(-constants::player_speed * deltaTime);
		}

		if (IsKeyDown(KEY_A)) {
			player.addX(-constants::player_speed * deltaTime);
		}

		if (IsKeyDown(KEY_S)) {
			player.addY(constants::player_speed * deltaTime);
		}

		if (IsKeyDown(KEY_D)) {
			player.addX(constants::player_speed * deltaTime);
		}

		const int treasureValue = scene::collectTreasure(player.getTile());

		if (treasureValue > 0) {
			player.addTreasure(treasureValue);
		}

		if (scene::getTreasureCount() <= 0 && player.getOxygen() >= 100) {
			scene::initializeTreasures();
		}

		if (player.getOxygen() <= 0) {
			windows::infoBox("Oxygen Depleted", "You died!");
			goto Over;
		}

		Vector2 mousePosition = GetMousePosition();

		int treasureHover = scene::getTreasureAtPosition(mousePosition.x, mousePosition.y);


		lastRefresh = now;

		BeginDrawing();

		scene::draw(deltaTime);
		player.draw(deltaTime);

		if (treasureHover != 0) {
			std::string text = "Treasure: $" + std::to_string(treasureHover);
			DrawText(text.data(), static_cast<int>(mousePosition.x + 8), static_cast<int>(mousePosition.y - 8), 19, BLACK);
		}

		EndDrawing();
	}

Over:

	CloseWindow();
}