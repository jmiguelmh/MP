/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "matriz.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

void leerDatos(float m[][COLS_BASE])
{
    ifstream archivo;
    archivo.open("doc/datos.txt");
    for(int i = 0; i < FILAS_BASE; i++){
      for(int j = 0; j < COLS_BASE; j++){
           archivo >> m[i][j];
        }
    } 
    archivo.close();
}

void mostrarMenu()
{
    cout << "Seleccione la función que desee probar:" << endl;
    cout << "1. ValoresExtremosAnuales" << endl;
    cout << "2. ExtraeDatos" << endl;
    cout << "3. MediaMensualAjustada" << endl;
    cout << "4. ValoresExtremos" << endl;
    cout << "5. NumeroADiaMes" << endl;
    cout << "6. NumeroADiaSemana" << endl;
    cout << "7. DiaMesANumero" << endl;
    cout << endl << "Opcion: ";
}

void ValoresExtremosAnuales(float M[][COLS_BASE], float &maxima_temperatura, int &dia_maxima_temperatura, float &minima_temperatura, int &dia_minima_temperatura, float &maxima_amplitud_termica, int &dia_maxima_amplitud_termica)
{
    maxima_temperatura = M[0][2];
    minima_temperatura = M[0][3];
    maxima_amplitud_termica = M[0][2] - M[0][3];
    
    for(int i = 0; i < FILAS_BASE; i++)
    {
        if(maxima_temperatura < M[i][2])
        {
            maxima_temperatura = M[i][2];
            dia_maxima_temperatura = i + 1;
        }
        if(minima_temperatura > M[i][3])
        {
            minima_temperatura = M[i][3];
            dia_minima_temperatura = i + 1;
        }
        if(maxima_amplitud_termica < M[i][2] - M[i][3])
        {
            maxima_amplitud_termica = M[i][2] - M[i][3];
            dia_maxima_amplitud_termica = i + 1;
        }
    }
}

void ExtraeDatos(float M[][COLS_BASE], int k, float meses[][COLS_MES])
{
    assert(k == 2 || k == 3);
    int i, j, l = 0;
    
    for(i = 0; i < FILAS_MES; i++)
    {
        for(j = 0; j < COLS_MES; j++)
        {
            if(l == 59)
            {
                meses[i][j++] = M[l++][k];
                meses[i][j++] = MARCA_FIN;
                meses[i][j] = MARCA_FIN;
            }
            else if(l == 120 || l == 181 || l == 273 || l == 334)
            {
                meses[i][j++] = M[l++][k];
                meses[i][j] = MARCA_FIN;
            }
            else
            {
                meses[i][j] = M[l++][k];
            }
        }
    }
}

float MediaMensualAjustadaFila(float mes[], int util)
{
    float maxima_temperatura = mes[0], minima_temperatura = mes[0];
    float suma = 0.0;
    int contador = 0;
    
    for(int i = 0; i < util && mes[i] != MARCA_FIN; i++)
    {
        if(maxima_temperatura < mes[i])
            maxima_temperatura = mes[i];
        if(minima_temperatura > mes[i])
            minima_temperatura = mes[i];
        suma += mes[i];
        contador++;
    }
    
    suma -= maxima_temperatura;
    suma -= minima_temperatura;
    contador -= 2;
    
    return (suma / contador);
}

float MediaMensualAjustada(float meses[][COLS_MES], int mes)
{
    assert(0 <= mes && mes < COLS_MES);    
    return MediaMensualAjustadaFila(meses[mes],COLS_MES);
}

void ValoresExtremosMes(float maximas_mes[], float minimas_mes[], int util, float &maxima_temperatura, int &dia_maxima_temperatura, float &minima_temperatura, int &dia_minima_temperatura,  float &maxima_amplitud_termica, int &dia_maxima_amplitud_termica)
{
    maxima_temperatura = maximas_mes[0];
    minima_temperatura = minimas_mes[0];
    maxima_amplitud_termica = maxima_temperatura - minima_temperatura;
    
    for(int i = 0; i < util && maximas_mes[i] != MARCA_FIN; i++)
    {
        if(maxima_temperatura < maximas_mes[i])
        {
            maxima_temperatura = maximas_mes[i];  
            dia_maxima_temperatura = i + 1;
        }
            
        if(minima_temperatura > minimas_mes[i])
        {
            minima_temperatura = minimas_mes[i];
            dia_minima_temperatura = i + 1;
        }
        
        if(maxima_amplitud_termica < maximas_mes[i] - minimas_mes[i])
        {
            maxima_amplitud_termica = maximas_mes[i] - minimas_mes[i];
            dia_maxima_amplitud_termica = i + 1;
        }
    }
}


void ValoresExtremos(float maximas_mes[][COLS_MES], float minimas_mes[][COLS_MES], int mes, float &maxima_temperatura, int &dia_maxima_temperatura, float &minima_temperatura, int &dia_minima_temperatura, float &maxima_amplitud_termica, int &dia_maxima_amplitud_termica){
    assert(0 <= mes && mes < COLS_MES);    
    ValoresExtremosMes(maximas_mes[mes],minimas_mes[mes],COLS_MES,maxima_temperatura,dia_maxima_temperatura,minima_temperatura,dia_minima_temperatura,maxima_amplitud_termica,dia_maxima_amplitud_termica);
}

void NumeroADiaMes(int numero, int &dia, int &mes)
{
    assert(numero > 0 && numero <= FILAS_BASE);
    const int diasMes[FILAS_MES] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int i = 0;
    mes = 0;
    
    while(numero > diasMes[i])
    {
        numero -= diasMes[i];
        mes++;
        i++;
    }
    
    dia = numero;
}

string NumeroADiaSemana(int numero)
{
    assert(numero > 0 && numero <= FILAS_BASE);
    const string diasSemana[7] = {"Lunes","Martes","Miércoles","Jueves","Viernes","Sábado","Domingo"};
    int dia = 2; //Se inicializa al primer día del año 2020, Miércoles
    for(int i = 1; i < numero; i++)
    {
        dia++;
        dia %= 7;
    }
    
    return diasSemana[dia];
}

bool FechaValida(int dia, int mes)
{
    bool valido = false;
    const int diasMes[FILAS_MES] = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    if(mes >= 0 && mes < FILAS_MES && dia > 0 && dia <= diasMes[mes])
        valido = true;
    
    return valido;
}

int DiaMesANumero(int dia, int mes)
{
    assert(FechaValida(dia,mes));
    const int diasMes[FILAS_MES] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int numero = 0;
    
    for(int i = 0; i < mes; i++)
        numero += diasMes[i];
    
    numero += dia;
    return numero;
}