#ifndef _GAME_
#define _GAME_

#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include "ConjuntoParticulas.h"
#include "Particula.h"
#include "Pintar.h"
#include "raylib.h"

using namespace std;

class Game {
private:
    int ancho,alto;
    int numeroOvnis;
    char direccion;
    string score,tiempo,resultado;
    bool pausa, gameOver, ganador;
    ConjuntoParticulas ovnis, proyectiles;
    Particula nave;
    int FPS;
    string colores[3];
    int vidas;
    int tiempoInvencibilidad; // frames invencible se calcula en el init para ser 3 segundos
    bool invencible;
    int framesInvencibilidad;
    int cooldownDisparoEspecial; // frames cooldown se calcula en el init para ser 5 segundos
    int framesCooldown;
    int rondaActual;
    int numeroRondas;
    int puntuacion;

    void pantallaVictoria(int N, string t);
    void pantallaDerrota(int N, string t);
    char Direccion();

public:
    Game();
    Game(const char *nombreNichero);
    void Init();
    void Update();
};

#endif