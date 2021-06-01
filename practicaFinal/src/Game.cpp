#include "Game.h"

void Game::pantallaVictoria(int N, string t)
{
    ClearBackground(RAYWHITE);
    DrawText("ESC para salir", 10, 10, 20, BLACK);
    DrawText("Has ganado", 10, 30, 20, BLACK);
    string resultado = "Eliminaste " + to_string(N) + " particulas en " + t + " segundos";
    DrawText(resultado.c_str(), 10, 50, 20, BLACK);
}

void Game::pantallaDerrota(int N, string t)
{
    ClearBackground(RAYWHITE);
    DrawText("ESC para salir", 10, 10, 20, BLACK);
    DrawText("Has perdido", 10, 30, 20, BLACK);
    string resultado = "Eliminaste " + to_string(N) + " particulas en " + t + " segundos";
    DrawText(resultado.c_str(), 10, 50, 20, BLACK);
}


char Game::Direccion()
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

Color stringToColor(string c) {
    Color color;
    if (c == "DARKGREY") {
        color = DARKGRAY;
        return color;
    } else if (c == "MAROON") {
        color = MAROON;
        return color;
    } else if (c == "ORANGE") {
        color = ORANGE;
        return color;
    } else if (c ==  "DARKGREEN") {
        color =  DARKGREEN;
        return color;
    }  else if (c ==  "DARKBLUE") {
        color =  DARKBLUE;
        return color;
    }  else if (c ==  "DARKPURPLE") {
        color = DARKPURPLE;
        return color;
    }  else if (c ==  "DARKBROWN") {
        color = DARKBROWN;
        return color;
    }  else if (c == "GRAY") {
        color = GRAY;
        return color;
    }  else if (c == "RED") {
        color = RED;
        return color;
    }   else if (c == "GOLD") {
        color = GOLD;
        return color;
    }   else if (c =="LIME") {
        color = LIME;
        return color;
    }    else if (c == "BLUE") {
        color = BLUE;
        return color;
    } else if (c == "VIOLET") {
        color = VIOLET;
        return color;
    } else if (c == "BROWN") {
        color = BROWN;
        return color;
    } else if (c == "LIGHTGRAY") {
        color = LIGHTGRAY;
        return color;
    } else if (c == "PINK") {
        color = PINK;
        return color;
    } else if (c == "YELLOW") {
        color = YELLOW;
        return color;
    } else if (c == "GREEN") {
        color = GREEN;
        return color;
    } else if (c == "SKYBLUE") {
        color = SKYBLUE;
        return color;
    } else if (c == "PURPLE") {
        color = PURPLE;
        return color;
    } else if (c == "BEIGE") {
        color = BEIGE;
        return color;
    } else {
        color = BLACK;
        return color;
    }
}

Game::Game()
{
    ancho = 800;
    alto = 450;
    numeroOvnis = 10;
    colores[0] = "RED";
    colores[1] = "BLUE";
    colores[2] = "BLACK";
    FPS = 60;
    vidas = 3;
}

Game::Game(const char *nombreFichero) {
    ifstream fichero;
    cout << nombreFichero << endl;
    fichero.open(nombreFichero);
    if(fichero.is_open()){
        fichero >> ancho;
        fichero >> alto;
        fichero >> numeroOvnis;
        fichero >> colores[0];
        fichero >> colores[1];
        fichero >> colores[2];
        fichero >> FPS;
        fichero >> vidas;
    }else{
        cout << "No se pudo abrir el archivo" << endl;
        exit(-1);
    }
    fichero.close();
}

void Game::Init()
{
    ConjuntoParticulas auxOvnis(0), auxProyectiles(0);
    ovnis = auxOvnis;
    proyectiles = auxProyectiles;
    pausa = false;
    gameOver = false;
    ganador = false;
    invencible = false;
    framesInvencibilidad = 0;
    tiempoInvencibilidad = 3 * FPS;
    cooldownDisparoEspecial = 5 * FPS;
    framesCooldown = 0;

    srand(time(NULL));
    float x, y, dx, dy, radio;

    for (int i = 0; i < numeroOvnis; i++)
    {
        x = rand() % ancho;
        y = rand() % (alto / 2);
        dx = rand() % MAX_VEL + 1;
        dy = rand() % MAX_VEL / 2.0 + 1;
        radio = 7;
        Particula p(x, y, dx, dy, radio);
        ovnis.AgregaParticula(p);
    }

    nave.SetXY(ancho / 2.0, alto - 20.0);
    nave.SetDX(5.0);
    nave.SetDY(5.0);

    InitWindow(ancho, alto, "Minijuego");

    SetTargetFPS(FPS);
}

void Game::Update()
{
    while (!WindowShouldClose())
    {
        if (!gameOver)
        {
            // actualizar estado de los objetos

            if (IsKeyPressed(KEY_P))
                pausa = !pausa;

            if (!pausa)
            {
                if (IsKeyPressed(KEY_SPACE))
                {
                    Particula disparo(nave.GetX(), nave.GetY(), 0.0, -4.0, 3.0);
                    proyectiles.AgregaParticula(disparo);
                }

                if (IsKeyPressed(KEY_LEFT_ALT) && framesCooldown > cooldownDisparoEspecial)
                {
                    Particula disparo1(nave.GetX(), nave.GetY(), -cos(PI/4), -4.0 * sin(PI/4), 3.0);
                    Particula disparo2(nave.GetX(), nave.GetY(), -cos(3*PI/8), -3.25 * sin(3*PI/8), 3.0);
                    Particula disparo3(nave.GetX(), nave.GetY(), cos(PI/2), -3.15 * sin(PI/2), 3.0);
                    Particula disparo4(nave.GetX(), nave.GetY(), cos(3*PI/8), -3.25 * sin(3*PI/8), 3.0);
                    Particula disparo5(nave.GetX(), nave.GetY(), cos(PI/4), -4.0 * sin(PI/4), 3.0);
                    proyectiles.AgregaParticula(disparo1);
                    proyectiles.AgregaParticula(disparo2);
                    proyectiles.AgregaParticula(disparo3);
                    proyectiles.AgregaParticula(disparo4);
                    proyectiles.AgregaParticula(disparo5);
                    framesCooldown = 0;
                }

                for (int i = proyectiles.getUtiles() - 1; i >= 0; i--)
                {
                    for (int j = ovnis.getUtiles() - 1; j >= 0; j--)
                    {
                        if (proyectiles.ObtieneParticula(i).Colision(ovnis.ObtieneParticula(j)))
                        {
                            proyectiles.BorraParticula(i);
                            ovnis.BorraParticula(j);
                        }
                    }

                    if (proyectiles.ObtieneParticula(i).GetY() <= proyectiles.ObtieneParticula(i).GetRadio())
                        proyectiles.BorraParticula(i);
                }

                ovnis.Mover(ancho, alto);
                ovnis.Rebotar(ancho, alto);

                proyectiles.Mover(ancho, alto);

                char dir = Direccion();
                nave.MoverGrid(dir, ancho, alto);

                for (int i = 0; i <= ovnis.getUtiles(); i++)
                    if (nave.Colision(ovnis.ObtieneParticula(i)))
                    {
                        tiempo = (int)GetTime();
                        if(!invencible) {
                            vidas--;
                            invencible = true;
                        }
                        if(framesInvencibilidad > tiempoInvencibilidad) {
                            invencible = false;
                            framesInvencibilidad = 0;
                        }
                    }
            }

            framesInvencibilidad++;
            framesCooldown++;

            if (ovnis.getUtiles() == 0 || vidas == 0)
            {
                gameOver = true;
                tiempo = (int)GetTime();
                if(vidas > 0)
                    ganador = true;
            }
              
        
            //-----------------------------------------------------
            // pintar los objetos
            //-----------------------------------------------------
            BeginDrawing();

            ClearBackground(RAYWHITE);

            pintarConjunto(ovnis, stringToColor(colores[0]));
            pintarConjunto(proyectiles,stringToColor(colores[1]));
            pintarParticula(nave, stringToColor(colores[2]));

            DrawText("ESC para salir", 10, 10, 20, BLACK);
            DrawFPS(10, 30);
            score = "Particulas: " + to_string(ovnis.getUtiles());
            tiempo = "tiempo: " + to_string((int)GetTime());
            string vidasString = "vidas: " + to_string(vidas);
            string tiempoCooldown = "Disparo Cargado: " + to_string((int) (5.0 - framesCooldown/FPS));
            DrawText(score.c_str(), 10, 50, 20, BLACK);
            DrawText("Alt para Disparo Cargado", 10, 90, 20, BLACK);
            DrawText(tiempo.c_str(), 600, 10, 20, BLACK);
            DrawText(vidasString.c_str(), 600, 30, 20, BLACK);
            DrawText(tiempoCooldown.c_str(), 600, 50, 20, BLACK);
            DrawText("P para pausar", 10, 70, 20, BLACK);
        }
        else if (ganador)
        {
            pantallaVictoria(numeroOvnis, tiempo);
        }
        else
        {
            pantallaDerrota(numeroOvnis, tiempo);
        }
        EndDrawing();
        //-----------------------------------------------------
    }
}