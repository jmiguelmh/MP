#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <string>
using namespace std;

struct Paquete
{
    int origen;
    int destino;
    int peso;
};

struct Contenedor
{
    static const int MAX = 50;
    Paquete lista[MAX];
    int utiles;
};

string paqueteToString(Paquete a);

Paquete creaPaquete(int ori, int des, int peso);

void ordenar(Contenedor & c);

void mostrarContenedor(const Contenedor & c);

Contenedor seleccionaPaquetes(const Contenedor & c, int dest);

void contarPaquetesPeso(const Contenedor & c, int dest, int & nro, int & peso);

#endif