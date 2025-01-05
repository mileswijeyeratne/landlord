#include "../common/main.h"
#include "raylib.h"

int main() {
    // Initialize the window
    InitWindow(800, 600, "Raylib Client Example");

    say_hello();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    // Close the window
    CloseWindow();

    return 0;
}
