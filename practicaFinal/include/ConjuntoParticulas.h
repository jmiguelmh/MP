#ifndef _CONJUNTO_PARTICULAS_
#define _CONJUNTO_PARTICULAS_

#include "Particula.h"

const int TAM_BLOQUE = 3;
const int MIN_SIZE = 5;

class ConjuntoParticulas {
private:
    Particula *set;
    int capacidad;
    int utiles;

    void reservarMemoria(int c);
    void liberarMemoria();
    void redimensionar(int tam);
    void copiar(const ConjuntoParticulas &c);

public:
    ConjuntoParticulas();
    ConjuntoParticulas(int c);
    ConjuntoParticulas(const ConjuntoParticulas &c);
    ~ConjuntoParticulas();
    int getCapacidad() const;
    int getUtiles() const;
    void AgregaParticula(const Particula & p);
    void BorraParticula(int pos);
    const Particula & ObtieneParticula(int pos) const;
    void ReemplazaParticula(const Particula & otra, int pos);
    void Mover(int ancho, int alto);
    void Rebotar(int ancho , int alto);
    void Mostrar();
    float Area() const;
    ConjuntoParticulas& operator=(const ConjuntoParticulas& original);
    ConjuntoParticulas operator+(const ConjuntoParticulas& otro);
    bool operator<(const ConjuntoParticulas& otro) const;
};

ostream& operator<<(ostream &flujo, const ConjuntoParticulas &c);

#endif