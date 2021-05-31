#include "Pintar.h"

void pintarParticula(const Particula & p, Color c){
// funcion de raylib
    DrawCircle( p.GetX(), p.GetY(), p.GetRadio(), c);
}

void pintarConjunto(const ConjuntoParticulas & cp, Color c){
    int N = cp.getUtiles();

    for(int i = 0; i < N ; i++)
        pintarParticula(cp.ObtieneParticula(i), c);
}