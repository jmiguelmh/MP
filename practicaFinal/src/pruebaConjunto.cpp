#include "Particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>

const int ANCHO = 800;
const int ALTO = 600;

using namespace std;

int main(void)
{
    int N = 10;

    // creación de objetos
    //---------------------------------------------------------
    ConjuntoParticulas nube(N);

    for (int i = 0; i < 100; i++)
    {

        if ((random() % 10) > 5)
            for (int j = 0; j < 7; j++)
            {
                Particula nueva;
                nube.AgregaParticula(nueva);
            }

        else
        {
            for (int j = 0; j < 7; j++)
            {
                int nro = nube.getUtiles();
                if (nro > 0)
                    nube.BorraParticula((random() % nro));
            }
        }
        nube.Mover(ANCHO, ALTO);
        nube.Rebotar(ANCHO, ALTO);
        //nube.Mostrar();
        //cout << endl;
    }

    //cout << "Test pasado" << endl;

    // liberar memoria si la hubiera
    return 0;
}