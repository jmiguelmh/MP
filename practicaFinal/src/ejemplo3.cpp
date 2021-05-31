
#include "raylib.h"
#include "Particula.h"

const int screenWidth = 800;
const int screenHeight = 450;
//const int tamNave = 15;
const float DESP = 4.0;

void pintarParticula(const Particula &p, Color c)
{
    Vector2 pos = {p.GetX(), p.GetY()};
    DrawCircleV(pos, p.GetRadio(), c);
}

char Direccion()
{
    char dir = ' ';
    if (IsKeyDown(KEY_UP))
        dir = 'U';

    if (IsKeyDown(KEY_DOWN))
        dir = 'D';

    if (IsKeyDown(KEY_LEFT))
        dir = 'L';

    if (IsKeyDown(KEY_RIGHT))
        dir = 'R';

    return dir;
}

int main(void)
{
    // Initialization
    //---------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Modulo de prueba");

    Particula bola(GetScreenWidth() / 3.0f, GetScreenHeight() / 2.0f, 5.0, 4.0, 20);

    Particula manual(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, DESP, DESP, 15);

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    char dir;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
        dir = Direccion();

        manual.MoverGrid(dir, screenWidth, screenHeight);

        bola.Mover(screenWidth, screenHeight);
        bola.RebotaBordes(screenWidth, screenHeight);

        //-----------------------------------------------------
        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        pintarParticula(bola, RED);
        pintarParticula(manual, BLACK);
        DrawText("ESC para salir", 10, 10, 20, BLACK);

        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}
