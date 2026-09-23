#include <chrono>
#include <cstdint>

#include <raylib.h>

import rendering;
import constants;

using SteadyClock = std::chrono::steady_clock;
using TimePoint = SteadyClock::time_point;

void rendering::initialize() {
	TimePoint lastRefresh = SteadyClock::now();

	InitWindow(constants::window::x, constants::window::y, "Submarine Adventure");
	SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        const auto now = SteadyClock::now();
        const double deltaTime = std::chrono::duration<double>(now - lastRefresh).count();

        lastRefresh = now;

        BeginDrawing();

        onRender.Fire(deltaTime);

        EndDrawing();
    }

	CloseWindow();
}