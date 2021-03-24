/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* Auto-evaluacion de funciones
 * MaxMin: bien, 3, TEST OK
 * MasFrecuente: bien, 3, TEST OK
 * EstaOrdenado: bien, 3, TEST OK
 * TodosDistintos: bien, 3, TEST OK
 * MezclaOrdenada: bien, 3, TEST OK
 * 
 * Nota Autoevaluación: mal - regular - bien (deja la correcta)
 * 1 -> Función no implementada
 * 2 -> Función implementada pero con dudas
 * 3 -> Función implementada correctamente
 */ 

#include "GestionArrays.h"
#include <iostream>
using namespace std;

void MaxMin(const int v[], const int n, int &pos_max, int &pos_min)
{
    pos_max = pos_min = v[0];
    for(int i = 0; i < n; i++)
    {
        if(v[i] > v[pos_max])
            pos_max = i;
        if(v[i] < v[pos_min])
            pos_min = i;
    }
}

void MasFrecuente(const int v[], const int n, int &valor, int &frec)
{
    int contador, auxiliar, contador_mas_repetido = 0;

    for(int i = 0; i < n; i++)
    {
        auxiliar = v[i];
        contador = 0;
        for(int j = 0; j < n; j++)
        {
            if(v[j] == auxiliar)
                contador++;
        }

        if(contador_mas_repetido < contador)
        {
            contador_mas_repetido = contador;
            valor = v[i];
            frec = contador;
        }
    }
}

bool EstaOrdenado(const int v[], const int n)
{
    bool ordenado = true;
    for(int i = 0; i < n-1 && ordenado; i++)
    {
        if(v[i] > v[i+1])
            ordenado = false;
    }
    
    return ordenado;
}

bool TodosDistintos(const int v[], const int n)
{
    bool distintos = true;
    
    for(int i = 0; i < n && distintos; i++)
    {
        for(int j = i+1; j < n && distintos; j++)
        {
            if(v[i] == v[j])
                distintos = false;
        }
    }
    
    return distintos;
}

void MezclaOrdenada(const int v1[], const int n1, const int v2[], const int n2, int v3[], int &n3)
{
    int i = 0, j = 0, k = 0;
    
    if(EstaOrdenado(v1,n1) && EstaOrdenado(v2,n2))
    {
        while(i <  n1 && j < n2 && k < MAX)
        {
            if(v1[i] < v2[j])
                v3[k++] = v1[i++];
            else
                v3[k++] = v2[j++];
        }

        while(i < n1 && k < MAX)
        {
            v3[k++] = v1[i++];
        }

        while(j < n2 && k < MAX)
        {
            v3[k++] = v2[j++];
        }

        n3 = k;
    }
    
    else
    {
        n3 = 0;
    }
    
}

void CargaVector(int v[], int n, int min, int max){
    int rango = max - min;
    for(int i = 0; i < n; i++)
        v[i] = random()% rango + min;
}

void CargaVectorOrdenado(int v[], int n, int inicial, int incremento){

    v[0] = inicial;
    for(int i = 1; i < n; i++)
        v[i] = v[i-1] + random() % incremento;
}