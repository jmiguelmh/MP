/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matriz.h"
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{    
    float M[FILAS_BASE][COLS_BASE];
    leerDatos(M);
    
    const string nombreMeses[FILAS_MES] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    float maxima_temperatura, minima_temperatura, maxima_amplitud_termica;
    int dia_maxima_temperatura, dia_minima_temperatura, dia_maxima_amplitud_termica;
    int numero, dia, mes;
    float tempMaximas[FILAS_MES][COLS_MES], tempMinimas[FILAS_MES][COLS_MES];
    ExtraeDatos(M,2,tempMaximas);
    ExtraeDatos(M,3,tempMinimas);
    
    int opcion;
    do
    {
        mostrarMenu();
        cout << endl;
        cin >> opcion;
    } while(opcion < 1 || opcion > 7);
    
    cout << endl;
    
    switch(opcion)
    {
        case 1:
            ValoresExtremosAnuales(M,maxima_temperatura,dia_maxima_temperatura,minima_temperatura,dia_minima_temperatura,maxima_amplitud_termica,dia_maxima_amplitud_termica);
            NumeroADiaMes(dia_maxima_temperatura,dia,mes);
            cout << "La temperatura más alta registrada en todo el año es " << maxima_temperatura << ", se alcanzó el día " << dia << " de " << nombreMeses[mes] << endl;
            NumeroADiaMes(dia_minima_temperatura,dia,mes);
            cout << "La temperatura más baja registrada en todo el año es " << minima_temperatura << ", se alcanzó el día " << dia << " de " << nombreMeses[mes] << endl;
            NumeroADiaMes(dia_maxima_amplitud_termica,dia,mes);
            cout << "La amplitud termica más alta registrada en todo el año es " << maxima_amplitud_termica << ", se alcanzó el día " << dia << " de " << nombreMeses[mes] << endl;
            break;
            
        case 2:
            cout << "Temperaturas máximas:" << endl;
            for(int i = 0; i < FILAS_MES; i++)
            {
                for(int j = 0; j < COLS_MES; j++)
                {
                    cout << tempMaximas[i][j] << "\t";
                }
                cout << endl;
            }
            
            cout << endl <<  "Temperaturas minimas:" << endl;
            for(int i = 0; i < FILAS_MES; i++)
            {
                for(int j = 0; j < COLS_MES; j++)
                {
                    cout << tempMinimas[i][j] << "\t";
                }
                cout << endl;
            }
            break;
        
        case 3:
            cout << "Medias mensuales ajustadas de las temperaturas máximas" << endl;
            for(int i = 0; i < FILAS_MES; i++)
            {
                ValoresExtremos(tempMaximas,tempMinimas,i,maxima_temperatura,dia_maxima_temperatura,minima_temperatura,dia_minima_temperatura,maxima_amplitud_termica,dia_maxima_amplitud_termica);
                cout << nombreMeses[i] << ": " << MediaMensualAjustada(tempMaximas,i) << endl;
            }
            cout << endl; 
        
            cout << "Medias mensuales ajustadas de las temperaturas mínimas" << endl;
            for(int i = 0; i < FILAS_MES; i++)
            {
                ValoresExtremos(tempMaximas,tempMinimas,i,maxima_temperatura,dia_maxima_temperatura,minima_temperatura,dia_minima_temperatura,maxima_amplitud_termica,dia_maxima_amplitud_termica);
                cout << nombreMeses[i] << ": " << MediaMensualAjustada(tempMinimas,i) << endl;
            }
            break;
        
        case 4:
            for(int i = 0; i < FILAS_MES; i++)
            {
                cout << "En el mes de " << nombreMeses[i] << ":" << endl;
                ValoresExtremos(tempMaximas,tempMinimas,i,maxima_temperatura,dia_maxima_temperatura,minima_temperatura,dia_minima_temperatura,maxima_amplitud_termica,dia_maxima_amplitud_termica);
                cout << "La temperatura más alta fue " << maxima_temperatura << ", se alcanzó el día " << dia_maxima_temperatura << endl;
                cout << "La temperatura más baja fue " << minima_temperatura << ", se alcanzó el día " << dia_minima_temperatura << endl;
                cout << "La amplitud térmica más alta fue " << maxima_amplitud_termica << ", se alcanzó el día " << dia_maxima_amplitud_termica << endl;
                cout << endl;
            }
            break;
            
        case 5:
            cout << "Introduzca un número: ";
            cin >> numero;
            NumeroADiaMes(numero,dia,mes);
            cout << "El día número " << numero << " del 2020 fue " << dia << " de " << nombreMeses[mes] << endl;
            break;
            
        case 6:
            cout << "Introduzca un día: ";
            cin >> dia;
            cout << "Introduzca un mes: ";
            cin >> mes;
            numero = DiaMesANumero(dia,mes-1);
            cout << "El día " << dia << " de " << nombreMeses[mes-1] << " del 2020 fue un " << NumeroADiaSemana(numero) << endl;
            break;
            
        case 7:
            cout << "Introduzca un día: ";
            cin >> dia;
            cout << "Introduzca un mes: ";
            cin >> mes;
            cout << "El día " << dia << " de " << nombreMeses[mes-1] << " del 2020 fue el día número " << DiaMesANumero(dia,mes-1) << " del año" << endl;
            break;
    }
    
    return 0;
}