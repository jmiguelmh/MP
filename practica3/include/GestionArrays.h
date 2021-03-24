/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionArrays.h
 * Author: jmiguelmh
 *
 * Created on 20 de marzo de 2021, 15:25
 */

#ifndef GESTIONARRAYS_H
#define GESTIONARRAYS_H

const int MAX = 20;

void MaxMin(const int v[], const int n, int &pos_max, int &pos_min);

void MasFrecuente(const int v[], const int n, int &valor, int &frec);

bool EstaOrdenado(const int v[], const int n);

bool TodosDistintos(const int v[], const int n);

void MezclaOrdenada(const int v1[], const int n1, const int v2[], const int n2, int v3[], int &n3);

void CargaVector(int v[], int n, int min, int max);

void CargaVectorOrdenado(int v[], int n, int inicial, int incremento);

#endif /* GESTIONARRAYS_H */

