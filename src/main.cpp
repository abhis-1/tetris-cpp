/*
    Name: Abhishek Pandey
    Date: 20/04/2024
    Steps to develop tetris
        1. Set up the game loop
        2. Creating the grid
        3. Create the Block (L, J, I, O, S, T, Z) - use inheritance
        4. Move the blocks
        5. Rotate the blocks
        6. Checking for collisions
        7. Check for completed rows
        8. Game Over
        9. Create User Interface
        10. Add Score
        11. Add Next Block
        12. Add Sounds
*/
#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>
#include <cstdio>
#include <stdio.h>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf",64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggered(0.5))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE); // function which will write to the screen
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
            DrawTextEx(font, "press any key\nto play again", {320, 550}, 19, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}

