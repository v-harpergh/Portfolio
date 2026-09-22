#include <iostream>

#include <raylib.h>

int main()
{
    InitWindow(750, 400, "Submarine Adventure");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("basic text", 200, 200, 25, BLACK);

        EndDrawing();
    }

    CloseWindow();
    std::cout << "Hello World!\n";
}