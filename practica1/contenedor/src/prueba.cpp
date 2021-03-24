#include <iostream>
#include "contenedor.h"

using namespace std;

int main()
{
    Paquete actual;
    Contenedor c1, otro;
    int origen, destino, peso, cant;

    // lectura de datos
    cin >> cant;

    for (int i = 0; i < cant; i++) {
        cin >> origen >> destino >> peso;
        c1.lista[i] = creaPaquete(origen, destino, peso);
    }

    c1.utiles = cant;

    // se muestra la lista de productos.
    cout << "\n ******** Prueba de funcion mostrarContenedor ******** \n";
    mostrarContenedor(c1);

    // ordena
    cout << "\n ******** Prueba de funcion ordenarContenedor ******** \n";
    ordenar(c1);
    cout << "\n ******** Muestra contenido ordenado por peso ******** \n";
    mostrarContenedor(c1);

    cout << "\n ******** Prueba de funcion contarPaquetesPeso ******** \n";
    cout << "para cada destino muestro el nro de paquetes que se envian y su peso\n";
    int nro;
    for(int dest=0; dest < 10; dest++){
        contarPaquetesPeso(c1, dest, nro, peso);
        if (nro > 0)
            cout << "Destino: " << dest << " Paquetes: " << nro << " Peso: " << peso << endl;
    }
    
    cout << "\n ******** Prueba de funcion seleccionaPaquetes ******** \n";
    cout << "Paquetes enviados a destino=2\n";
    otro = seleccionaPaquetes(c1, 2);

    //    cout << "\n ******** y mostrar nuevo Contenedor \t\t********\n\n";
    mostrarContenedor(otro);

    return (0);
}
