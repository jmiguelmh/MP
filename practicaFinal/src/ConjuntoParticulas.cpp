#include "ConjuntoParticulas.h"
#include <iostream>
#include <cassert>

using namespace std;

void ConjuntoParticulas::reservarMemoria(int c)
{
    if (set != 0)
        liberarMemoria();

    set = new Particula[c];
}

void ConjuntoParticulas::liberarMemoria()
{
    if (set != 0)
        delete[] set;
}

void ConjuntoParticulas::redimensionar(int tam)
{
    
    Particula *nuevoSet = new Particula[capacidad + tam];

    for(int i = 0; i < utiles; i++)
        nuevoSet[i] = set[i];
    
    capacidad += tam;
    liberarMemoria();
    set = nuevoSet;
}

void ConjuntoParticulas::copiar(const ConjuntoParticulas &c) {
    set = 0;
    liberarMemoria();
    reservarMemoria(c.capacidad);

    for(int i = 0; i < c.utiles; i++)
        set[i] = c.set[i];
    
    capacidad = c.capacidad;
    utiles = c.utiles;
}

ConjuntoParticulas & ConjuntoParticulas::operator=(const ConjuntoParticulas& original){
    copiar(original);

    return *this;
}

ConjuntoParticulas ConjuntoParticulas::operator+(const ConjuntoParticulas& otro){
    ConjuntoParticulas aux;
  
    aux.utiles = utiles + otro.utiles;
    aux.capacidad = capacidad + otro.capacidad;    
    aux.reservarMemoria(aux.capacidad);


    for(int i = 0; i < utiles; i++)
        aux.set[i] = set[i];
    
    for(int i=0; i < otro.utiles ; i++)
        aux.set[utiles+i] = otro.set[i];
    
    return aux;
}

bool ConjuntoParticulas::operator<(const ConjuntoParticulas& otro) const{

    return this->Area() < otro.Area();
    
}

ConjuntoParticulas::ConjuntoParticulas()
{
    set = 0;
    reservarMemoria(MIN_SIZE);
    capacidad = MIN_SIZE;
    utiles = MIN_SIZE;

    for (int i = 0; i < MIN_SIZE; i++)
    {
        Particula p;
        set[i] = p;
    }
}

ConjuntoParticulas::ConjuntoParticulas(int c)
{
    assert(c >= 0);
    set = 0;
    reservarMemoria(c);
    capacidad = c;
    utiles = c;

    for (int i = 0; i < c; i++)
    {
        Particula p;
        set[i] = p;
    }
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &c) {
    copiar(c);
}

ConjuntoParticulas::~ConjuntoParticulas()
{
    liberarMemoria();
}

int ConjuntoParticulas::getCapacidad() const
{
    return capacidad;
}

int ConjuntoParticulas::getUtiles() const
{
    return utiles;
}

void ConjuntoParticulas::AgregaParticula(const Particula &p)
{
    if (utiles + 1 > capacidad)
        redimensionar(TAM_BLOQUE);

    set[utiles++] = p;
}

void ConjuntoParticulas::BorraParticula(int pos)
{
    if (pos >= 0 && pos < utiles)
        for (int i = pos; i < utiles - 1; i++)
            set[i] = set[i + 1];

    utiles--;

    if ((capacidad - utiles) > TAM_BLOQUE)
    {
        redimensionar(-TAM_BLOQUE);
        capacidad -= TAM_BLOQUE;
    }
}

const Particula &ConjuntoParticulas::ObtieneParticula(int pos) const
{
    if (pos >= 0 && pos < utiles)
        return set[pos];

    return set[0];
}

void ConjuntoParticulas::ReemplazaParticula(const Particula &otra, int pos)
{
    if (pos >= 0 && pos < utiles)
        set[pos] = otra;
}

void ConjuntoParticulas::Mover(int ancho, int alto)
{
    for (int i = 0; i < utiles; i++)
        set[i].Mover(ancho, alto);
}

void ConjuntoParticulas::Rebotar(int ancho, int alto)
{
    for (int i = 0; i < utiles; i++)
        set[i].RebotaBordes(ancho, alto);
}

void ConjuntoParticulas::Mostrar()
{
    cout << "Capacidad: " << capacidad << endl;
    cout << "Utiles: " << utiles << endl;

    for (int i = 0; i < utiles; i++)
        cout << "Particula" << i << ": " << set[i] << endl;
}

float ConjuntoParticulas::Area() const{
    float min_x, min_y, max_x, max_y;
    float area = 0.0;

    if(utiles > 0) {
        min_x = max_x = set[0].GetX();
        min_y = max_y = set[0].GetY();

        for(int i = 0; i < utiles; i++) {
            if(set[i].GetX() < min_x)
                min_x = set[i].GetX();

            if(set[i].GetY() < min_y)
                min_y = set[i].GetY();

            if(set[i].GetX() > max_x)
                max_x = set[i].GetX();

            if(set[i].GetY() > max_y)
                max_y = set[i].GetY();
        }

        area = (max_x - min_x) * (max_y - min_y);
    }

    return area;
}

ostream& operator<<(ostream &flujo, const ConjuntoParticulas &c) {
    cout << "Capacidad: " << c.getCapacidad() << endl;
    cout << "Utiles: " << c.getUtiles() << endl;

    for (int i = 0; i < c.getUtiles(); i++)
        cout << "Particula" << i << ": " << c.ObtieneParticula(i);
    
    return flujo;
}