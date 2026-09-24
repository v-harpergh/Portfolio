#include <chrono>
#include <cstdint>

#include <raylib.h>

import rendering;
import constants;

import features.scene;
import features.character;

using SteadyClock = std::chrono::steady_clock;
using TimePoint = SteadyClock::time_point;

void rendering::initialize() {
	TimePoint lastRefresh = SteadyClock::now();

	InitWindow(constants::window::x, constants::window::y, constants::title.data());
	SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        const auto now = SteadyClock::now();
        const double deltaTime = std::chrono::duration<double>(now - lastRefresh).count();

        lastRefresh = now;

        BeginDrawing();

        scene::draw(deltaTime);

        EndDrawing();
    }

	CloseWindow();
}