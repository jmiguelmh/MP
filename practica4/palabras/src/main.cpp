
#include <iostream>
#include "palabras.h"
#include <cstring>

using namespace std;


void test(const char frase[]){
    char palabra[MAX_SIZE];
    
    cout << "\nLA FRASE LEIDA ES: " <<  frase << endl;
    int n = tamanio(frase);
    int pals = cuentaPalabras(frase);
    cout << "Tiene " << n << " caracteres y " << pals << " palabras " << endl;

    cout << "\nDESCOMPOSICION EN PALABRAS nro -> palabra (long.)" << endl;
    int nro = 1;
    extraePalabra(frase, nro, palabra);
    while(tamanio(palabra) > 0){
           cout << nro << " -> " << palabra << " (" << tamanio(palabra) << ")\n";
           nro++;
           extraePalabra(frase, nro, palabra);
    }


    char reves[MAX_SIZE];
    cout << "\nFRASE INVERSA " << endl;
    delReves(frase, reves);
    cout << "Frase Original: " << frase;
    cout << "\nFrase al Reves: " << reves << endl;

    
}

int main() {
    char t1[] = "el 1er caso de    prueba\0";
    char t2[] = "LA PRUEBA!  en EL      MA-IN()\0";
    char t3[] = "    Granada   club de  futbol  \0";
    char t4[] = " una frase de prueba\0";
    char t5[] = "   una, frase de prueba..\0";
    char t6[] = "A B C D E\0";
    char t7[] = " .practicas. de MP se ,complican.\0";
    char t8[] = "inmediatamente \0";
    

    test(t1);
    test(t2);
    test(t3);
    test(t4);
    test(t5);
    test(t6);
    test(t7);
    test(t8);
    
    return (0);
}
