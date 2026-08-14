#include "raylib.h"

int main()
{
    int width = 800;
    int height = 600;

    InitWindow(width, height, "Cream-bellied Gnactcatcher");
    SetTargetFPS(60);

    Image brl_02 = LoadImage("leitosaria/STD_leitoso.png");
    Image brl_01 = LoadImage("leitosaria/LEITAR_leitoso.png");
    Image brl_03 = LoadImage("leitosaria/Winscreen.png");
    
    int leitaria = 0;
    
    Texture2D brlt_01 = LoadTextureFromImage(brl_01);
    Texture2D brlt_02 = LoadTextureFromImage(brl_02);
    Texture2D brlt_03 = LoadTextureFromImage(brl_03);

    UnloadImage(brl_01);
    UnloadImage(brl_02);
    UnloadImage(brl_03);

    while (!WindowShouldClose())
    {
        if (leitaria < 1000)
        {
            if (IsKeyDown(KEY_E))  
            {   
                leitaria = leitaria + 1;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (leitaria >= 1000)
        {
            ClearBackground(WHITE);
            int posX = (width - brlt_03.width) / 2;
            int posY = (height - brlt_03.height) / 2;
            DrawTexture(brlt_03, posX, posY, WHITE);
        }
        else
        {
            int posX = (width - brlt_01.width) / 2;
            int posY = (height - brlt_01.height) / 2;

            if (IsKeyDown(KEY_E))  
            {   
                DrawTexture(brlt_01, posX, posY, WHITE);
            }
            else
            {
                DrawTexture(brlt_02, posX, posY, WHITE);
            }
        }
        
        DrawText(TextFormat("Milk power, get to 1000 to win: %d", leitaria), 20, 20, 30, RED);

        EndDrawing();
    }

    UnloadTexture(brlt_01);
    UnloadTexture(brlt_02);
    UnloadTexture(brlt_03);

    CloseWindow();
    return 0;
}