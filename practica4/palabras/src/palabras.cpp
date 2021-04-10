
/* 
 * File:   palabras.cpp
 * Author: David Pelta
 * 
 * Created on 1 de abril de 2021,
 */

/*  Mi programa produce la salida esperada con todos los ejemplos del guión */

#include "palabras.h"

int tamanio(const char s[]) {
    int cont = 0;

    while (s[cont] != TERMINADOR)
        cont++;

    return cont;
}

// funcion "privada". 
// PRE: j siempre esta en el rango correcto
bool empiezaPalabra(const char s[], int j) {
       
    bool es_letra_actual;
    bool hay_sep_previo = true;
    
    es_letra_actual = s[j] != SEP;
    if ( j > 0)
       hay_sep_previo = (s[j - 1] == SEP);
    
    
    return (es_letra_actual && hay_sep_previo);
}

// funcion "privada". 
// PRE: j siempre esta en el rango correcto
bool terminaPalabra(const char s[], int j) {
    
    bool es_letra_actual = (s[j] != SEP);
    bool hay_sep_sig = (s[j + 1] == SEP) || (s[j + 1] == TERMINADOR);

    return (es_letra_actual && hay_sep_sig);
}


int posPalabra(const char msg[], int nroPal) {
    int resultado = -1, posicion = 0;
    int numeroPalabra = 0;
    
    while(msg[posicion] != TERMINADOR && numeroPalabra != nroPal)
    {
        if(posicion == 0 && msg[posicion] != SEP)
            numeroPalabra++;
        
        else
            if(empiezaPalabra(msg,posicion))
                numeroPalabra++;
        
        if(numeroPalabra == nroPal)
            resultado = posicion;
        
        posicion++;
    }
    
    return resultado;
}

int longPalabra(const char s[], int nroPal) {
    int posicionPalabra = posPalabra(s,nroPal);
    int contador = 0;
    
    if(posicionPalabra != -1)  
        while(s[posicionPalabra + contador] != SEP && s[posicionPalabra + contador] != TERMINADOR)
            contador++;
    
    return contador;
}


int cuentaPalabras(const char msg[]) {
    int posicion = 0;
    int numeroPalabras = 0;
    
    while(msg[posicion] != TERMINADOR)
    {
        if(terminaPalabra(msg,posicion))
            numeroPalabras++;
        
        posicion++;
    }
    
    return numeroPalabras;
}

void extraePalabra(const char msg[], int nroPal, char salida[]) {
    int posicionPalabra = posPalabra(msg,nroPal);
    int longitudPalabra = longPalabra(msg,nroPal);
    
    for(int i = 0; i < longitudPalabra; i++)
        salida[i] = msg[posicionPalabra + i];
    
    salida[longitudPalabra] = TERMINADOR;
}

void delReves(const char msg[], char msg_reves[]) {
    int numeroPalabras = cuentaPalabras(msg);
    int longitudMsg = tamanio(msg);
    int posicionPalabra, contadorPalabra = 0, contadorMsgReves = 0;
    char palabra[MAX_SIZE];
    
    for(int i = longitudMsg - 1; i >= 0; i--)
    {
        if(empiezaPalabra(msg,i))
        {
            extraePalabra(msg,numeroPalabras,palabra);
            numeroPalabras--;
            
            while(palabra[contadorPalabra] != TERMINADOR)
            {
                msg_reves[contadorMsgReves] = palabra[contadorPalabra];
                contadorPalabra++;
                contadorMsgReves++;
            }
            
            contadorPalabra = 0;
            
            if(numeroPalabras != 0)
                msg_reves[contadorMsgReves++] = '-';
        }
    }
    
    msg_reves[contadorMsgReves++] = TERMINADOR;
}

void agregaPalabra(char msg[], const char pal[]) {
    int longitudPalabra = tamanio(pal);
    int longitudMsg = tamanio(msg);
    
    if((longitudPalabra + longitudMsg) < MAX_SIZE)
    {
        for(int i = 0; i < longitudPalabra; i++)
        {
            msg[longitudMsg + i] = pal[i];
        }
    }
    
    msg[longitudPalabra + longitudMsg - 1] = TERMINADOR;
}