
#include "contenedor.h"

// funci�n para devolver los datos de un paquete como un string
string paqueteToString(Paquete a)
{
    string rta;
    rta = "Orig: " + to_string(a.origen) + "\t Dest: " + to_string(a.destino) + "\tPeso:" + to_string(a.peso);
    return rta;
}

// PARA COMPLETAR
// crea una variable de tipo Paquete y la devuelve
Paquete creaPaquete(int ori, int des, int peso)
{
    Paquete p;
    p.origen = ori;
    p.destino = des;
    p.peso = peso;
    return p;
}


// PARA COMPLETAR
// ordena el contenedor en funci�n del campo peso de cada paquete
void ordenar(Contenedor & c)
{
    for (int i = c.utiles - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (c.lista[j - 1].peso > c.lista[j].peso) {
                Paquete aux = c.lista[j];
                c.lista[j] = c.lista[j - 1];
                c.lista[j - 1] = aux;
            }
        }
    }
}


// PARA COMPLETAR
// muestra el listado de paquetes
void mostrarContenedor(const Contenedor & c)
{
    for(int i = 0; i < c.utiles; i++)
    {
        cout << "Paq: " << i + 1 << "\tOrig: " << c.lista[i].origen << "\tDest: " << c.lista[i].destino << "\tPeso: " << c.lista[i].peso << endl;
    }
}


// PARA COMPLETAR
// construye un nuevo contenedor con los paquetes que tienen como destino "dest"
Contenedor seleccionaPaquetes(const Contenedor & c, int dest)
{
    Contenedor aux;
    int utiles = 0;
    for(int i = 0; i < c.utiles; i++)
    {
        if(c.lista[i].destino == dest)
        {
            aux.lista[utiles] = c.lista[i];
            utiles++;
        }
    }
    aux.utiles = utiles;
    return aux;
}

//PARA COMPLETAR
// devuelve el nro de paquetes y la suma de sus pesos que tienen como destino "dest"
void contarPaquetesPeso(const Contenedor & c, int dest, int & nro, int & peso)
{
    int suma = 0, numero_paquetes = 0;
    for(int i = 0; i < c.utiles; i++)
    {
        if(c.lista[i].destino == dest)
        {
            suma += c.lista[i].peso;
            numero_paquetes++;
        }
    }
    nro = numero_paquetes;
    peso = suma;
}