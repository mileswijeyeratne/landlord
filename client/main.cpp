#include "raylib.h"

#include "card.h"
#include <iostream>

int main() {
    // Initialize the window
	
	card::Card c = card::Card(1, card::clubs);
	std::cout << c << std::endl;

    InitWindow(800, 600, "Raylib Client Example");

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
