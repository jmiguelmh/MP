#include <iostream>
#include <ctime>
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"
#include "raylib.h"

using namespace std;

void pantallaVictoria(string tiempo, int N) {
    ClearBackground(RAYWHITE);
    DrawText("ESC para salir" , 10, 10, 20, BLACK);
    DrawText("Has ganado" , 10, 30, 20, BLACK);
    string resultado = "Eliminaste " + to_string(N) + " particulas en " + tiempo + " segundos";
    DrawText(resultado.c_str(), 10, 50, 20, BLACK);
}

void pantallaDerrota(string tiempo, int N) {
    ClearBackground(RAYWHITE);
    DrawText("ESC para salir" , 10, 10, 20, BLACK);
    DrawText("Has perdido" , 10, 30, 20, BLACK);
    string resultado = "Eliminaste " + to_string(N) + " particulas en " + tiempo + " segundos";
    DrawText(resultado.c_str(), 10, 50, 20, BLACK);
}

char Direccion(){
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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Error en el número de argumentos" << endl;
        return -1;
    } 
     
    const int screenWidth = 800;
    const int screenHeight = 450;
    int N = atoi(argv[1]);

    if(N <= 0) {
        cout << "El argumento debe ser positivo distinto de cero" << endl;
        return -1;
    }

    char dir;
    string score;
    string tiempo;
    string resultado;
    bool pausa = false;
    bool gameOver = false;
    bool ganador = false;

    ConjuntoParticulas ovnis(0), proyectiles(0);

    srand(time(NULL));
    float x, y, dx, dy, radio;

    for(int i = 0; i < N; i++) {
        x = rand() % screenWidth;
        y = rand() % (screenHeight / 2);
        dx = rand() % MAX_VEL + 1;
        dy = rand() % MAX_VEL / 2.0 + 1;
        radio = 7;
        Particula p(x,y,dx,dy,radio);
        ovnis.AgregaParticula(p);
    }

    Particula nave(screenWidth / 2.0, screenHeight - 20.0, 5.0, 0.0, 15.0);

    InitWindow(screenWidth, screenHeight, "Minijuego");
    
    SetTargetFPS(60);  

    while (!WindowShouldClose())
    {
        if(!gameOver) {
            // actualizar estado de los objetos
            
            if (IsKeyPressed(KEY_P)) pausa = !pausa;

            if(!pausa) {
                if(IsKeyPressed(KEY_SPACE)) {
                    Particula disparo(nave.GetX(), nave.GetY(), 0.0, -4.0, 3.0);
                    proyectiles.AgregaParticula(disparo);
                }

                
                
                for(int i = proyectiles.getUtiles() - 1; i >= 0; i--){
                    for(int j = ovnis.getUtiles() - 1; j >= 0; j--){
                        if(proyectiles.ObtieneParticula(i).Colision(ovnis.ObtieneParticula(j))) {
                            proyectiles.BorraParticula(i);
                            ovnis.BorraParticula(j);
                        }

                    }

                    if(proyectiles.ObtieneParticula(i).GetY() <= proyectiles.ObtieneParticula(i).GetRadio())
                        proyectiles.BorraParticula(i);
                }

                ovnis.Mover(screenWidth, screenHeight);
                ovnis.Rebotar(screenWidth, screenHeight);

                proyectiles.Mover(screenWidth, screenHeight);

                dir = Direccion();
                nave.MoverGrid(dir, screenWidth, screenHeight);

                for(int i = 0; i <= ovnis.getUtiles(); i++)
                    if(nave.Colision(ovnis.ObtieneParticula(i))) {
                        gameOver = true;
                        tiempo = (int) GetTime();
                    }
                        
            }
            
            if(ovnis.getUtiles() == 0 ) {
                gameOver = true;
                tiempo = (int) GetTime();
                ganador = true;
            }
            //-----------------------------------------------------
            // pintar los objetos
            //-----------------------------------------------------
            BeginDrawing();

            ClearBackground(RAYWHITE);

            pintarConjunto(ovnis, RED);
            pintarConjunto(proyectiles, BLUE);
            pintarParticula(nave, BLACK);
            
            DrawText("ESC para salir", 10, 10, 20, BLACK);
            DrawFPS(10, 30);
            score = "Particulas: " + to_string(ovnis.getUtiles());
            tiempo = "tiempo: " + to_string((int)GetTime());
            DrawText(score.c_str(), 10, 50, 20, BLACK);
            DrawText(tiempo.c_str(), 690, 10, 20, BLACK);
            DrawText("P para pausar", 10, 70, 20, BLACK);
        }
        else if (ganador) {
            pantallaVictoria(tiempo, N);
        } else {
            pantallaDerrota(tiempo, N);
        }
        EndDrawing();
        //-----------------------------------------------------
    }

    CloseWindow();
    return 0;
}
