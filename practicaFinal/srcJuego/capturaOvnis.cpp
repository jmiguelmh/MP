#include "Game.h"

int main(int argc, char **argv)
{
    Game juego("datosJuego.txt");
    juego.Init();
    juego.Update();
}
