#include "raylib.h"

// g++ hw4.cpp -o Program.exe -IC:\raylib\raylib\src -lraylib -lgdi32 -lwinmm -Wall

/*
Author: Uku-Laur Jagomägi

Part 1:
Experiment with 3 functions from the raylib cheat sheet that seem interesting to you. Report about your experiment, what did you discover?
How do you think you can use these functions in a game?
Add a feature to your program: make objects (rectangles or other shapes) move by themselves and bounce back when they hit the edge of the window.

Implementation:
I have added the following functions from the RayLib cheat sheet:
    SetTargetFPS - This function sets the targeted/maximum fps for the game. This can be used by the players to limit their FPS in the game.
    DrawFPS - This function displays the FPS of the game. This function can be used to display the current FPS to the players.
    DrawText - This function displays some text on the screen. This can be used to give input to players.
    DrawTexture - This function is used to draw textures. Can be used to display a background image to the players.
    DrawRectangleV - This function is used to draw rectangles. Can be used to draw rectangle shaped objects in the game.
    DrawCircleV - This function is used to draw circles. Can be used to draw circle shaped objects in the game.
    DrawRectangleLinesEx - This function is used to draw lines of a rectangle. Can be used to define game area in a game.

I discovered that there are a lot of different functions that can be used and they can be 2D or 3D. I was amused how many of different functions have been prebuilt.
For instance I thought that DrawFPS or SetTargetFPS are functions that will be written by gamedevelopers themselves. However this seems to be a rather easy implementation.
I also discovered that while using IsKeyDown function for the "WASD" keys - they have to be with uppercase letters in single quotes '' not in lowercase and double quotes "".
For example IsKeyDown('A').

Part 2:
* Bonus: Add another feature of your choice. If you have more ideas than time to implement them, share your extra ideas with students who need ideas.
  Different students should NOT implement the same ideas that have been shared between them.
    Implementation: I have created a rectangle that can be moved by either arrow keys or with "WASD" keys.
        I have added a blue circle around player's cursor which moves along with the cursor while the player moves it.
        The program is displaying FPS and the screen size to the player.
* Bonus: Load and display a background image.
    Implementation: I have added a background image.
* Bonus (easy): have 2 keys for each control. For example, move up with either the Up arrow or W.
    Implementation: I have added an option to move the rectangle around with arrow keys or "WASD" keys.
*/

int main() // Main function.
{
    const int screenWidth = 1920 / 1.5; // Program's screen width.
    const int screenHeight = 1080 / 1.5; // Program's Screen height.

    InitWindow(screenWidth, screenHeight, "My homework 4."); // Give name to the program.

    SetTargetFPS(240); // Set the target FPS for the game.

    Texture2D background = LoadTexture("F:\\Development\\development\\CPP04\\game_background.png");
    // Texture2D background = LoadTexture("F:/Development/development/CPP04/game_background.png");

    Vector2 rectanglePosition = { (float)screenWidth / 2, (float)screenHeight / 2 }; // Variable to define the rectangle's position.
    Vector2 rectangleSize = { 20, 20 }; // Variable to define the rectangle's size.

    Vector2 ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }; // Variable to define the red circle's position.
    Vector2 ballSpeed = { 5.0f, 4.0f }; // Variable to define the red circle's velocity.
    float ballRadius = 20; // Variable to define the circle's radius.



    while (!WindowShouldClose()) // When the game has not been closed.
    {

        // If clauses what to do when certain keys are pressed. These are used for controlling the green rectangle.
        if (IsKeyDown(KEY_RIGHT)) rectanglePosition.x += 2.0f; // This line updates the X dimension of the green rectangle when the right arrow key is pressed.
        if (IsKeyDown(KEY_LEFT)) rectanglePosition.x -= 2.0f; // This line updates the X dimension of the green rectangle when the left arrow key is pressed.
        if (IsKeyDown(KEY_UP)) rectanglePosition.y -= 2.0f; // This line updates the Y dimension of the green rectangle when the up arrow key is pressed.
        if (IsKeyDown(KEY_DOWN)) rectanglePosition.y += 2.0f; // This line updates the Y dimension of the green rectangle when the down arrow key is pressed.
        if (IsKeyDown('D')) rectanglePosition.x += 2.0f; // This line updates the X dimension of the green rectangle when the 'D' key is pressed.
        if (IsKeyDown('A')) rectanglePosition.x -= 2.0f; // This line updates the X dimension of the green rectangle when the 'A' key is pressed.
        if (IsKeyDown('W')) rectanglePosition.y -= 2.0f; // This line updates the Y dimension of the green rectangle when the 'W' key is pressed.
        if (IsKeyDown('S')) rectanglePosition.y += 2.0f; // This line updates the Y dimension of the green rectangle when the 'S' key is pressed.

        // Bouncing ball logic 
        ballPosition.x += ballSpeed.x; // This line updates the X dimension of the red circle.
        ballPosition.y += ballSpeed.y; // This line updates the Y dimension of the red circle.
        // Check whether the ball has hit the X dimensional border. If yes then move away from the border to another direction.
        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) ballSpeed.x *= -1.0f;
        // Check whether the ball has hit the Y dimensional border. If yes then move away from the border to another direction.
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

        BeginDrawing(); // Start drawing.

        ClearBackground(RAYWHITE); // Create a background for the game area. It has to be different from the color which is being used for the background image.
        DrawTexture(background, 0, 0, WHITE); // Draw the background image.

        DrawText("Move the rectangle with arrow keys or with wasd.", 10, 10, 20, BLACK); // Display some hints about this game.

        DrawRectangleV(rectanglePosition, rectangleSize, DARKGREEN); // Create the rectangle which user can move.

        DrawCircleV(ballPosition, ballRadius, MAROON); // Create the randomly bouncing circle.
        //DrawRectangleLinesEx((Rectangle) { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() }, 4, BLACK); // Draw the area where the circle is bouncing.
        DrawCircleV(GetMousePosition(), 10, DARKBLUE); // Draw a circle around the mouse cursor.
        DrawFPS(30, 40); // Show FPS of the game.
        DrawText(TextFormat("Screen Size: [%i, %i]", GetScreenWidth(), GetScreenHeight()), 10, 70, 10, BLACK); // Display the Screen Size of the game.

        EndDrawing(); // End drawing.
    }
    UnloadTexture(background); // Unload the texture when done.

    CloseWindow(); // Close the game window.
}
