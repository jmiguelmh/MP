#include "Game.h"

int main(int argc, char **argv)
{
    Game juego("datos.txt");
    juego.Init();
    juego.Update();
}
