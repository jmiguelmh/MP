#include <iostream>
#include "tiempo.h"

using namespace std;

int main()
{
    Tiempo t1, t2;
    t1.horas = 5;
    t1.minutos = 15;
    t1.segundos = 45;
    t2.horas = 7;
    t2.minutos = 35;
    t2.segundos = 5;

    cout << "t1: " << t1.horas << " horas " << t1.minutos << " minutos " << t1.segundos << " segundos" << endl;
    cout << "t2: " << t2.horas << " horas " << t2.minutos << " minutos " << t2.segundos << " segundos" << endl;

    cout << endl;

    cout << "Prueba de la funcion esPosterior" << endl;
    bool posterior = esPosterior(t1,t2);
    if(posterior)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << endl;
    
    cout << "Prueba de la funcion tiempoEnSegundos" << endl;
    cout << "t1 en segundos: " << tiempoEnSegundos(t1) << endl;

    cout << endl;

    cout << "Prueba de la funcion segundosEnTiempo" << endl;
    segundosEnTiempo(t1,10000);
    cout << "10.000 segundos en tiempo: " << t1.horas << " horas " << t1.minutos << " minutos " << t1.segundos << " segundos" << endl;

    cout << endl;

    cout << "Prueba de la funcion obtenerNuevoTiempo" << endl;
    Tiempo t3 = obtenerNuevoTiempo(t2, 10000);
    cout << "Si sumamos 10.000 segundos a t1 obtenemos: " << t3.horas << " horas " << t3.minutos << " minutos " << t3.segundos << " segundos" << endl;

    return 0;
}