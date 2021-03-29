/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matriz.h
 * Author: jmiguelmh
 *
 * Created on 24 de marzo de 2021, 13:10
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

const int FILAS_BASE = 366;
const int COLS_BASE = 4;
const int FILAS_MES = 12;
const int COLS_MES = 31;
const int MARCA_FIN = -1000;

void leerDatos(float m[][COLS_BASE]);

void mostrarMenu();

void ValoresExtremosAnuales(float M[][COLS_BASE], float &maxima_temperatura, int &dia_maxima_temperatura, float &minima_temperatura, int &dia_minima_temperatura, float &maxima_amplitud_termica, int &dia_maxima_amplitud_termica);

void ExtraeDatos(float M[][COLS_BASE], int k, float meses[][COLS_MES]);

float MediaMensualAjustada(float meses[][COLS_MES], int mes);

void ValoresExtremos(float maximas_mes[][COLS_MES], float minimas_mes[][COLS_MES], int mes, float &maxima_temperatura, int &dia_maxima_temperatura, float &minima_temperatura, int &dia_minima_temperatura, float &maxima_amplitud_termica, int &dia_maxima_amplitud_termica);

void NumeroADiaMes(int numero, int &dia, int &mes);

string NumeroADiaSemana(int numero);

int DiaMesANumero(int dia, int mes);

#endif /* MATRIZ_H */

