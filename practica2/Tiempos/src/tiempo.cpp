#include "tiempo.h"

bool esPosterior(const Tiempo & t1, const Tiempo & t2)
{
    bool resultado = false;

    if(t2.horas > t1.horas)
    {
        resultado = true;
    }
    else if(t2.horas == t1.horas)
    {
        if(t2.minutos > t1.minutos)
        {
            resultado = true;
        }
        else if(t2.minutos == t1.minutos)
        {
            if(t2.segundos > t1.segundos)
                resultado = true;
        }
    }
    
    return resultado;
}

int tiempoEnSegundos(const Tiempo & t)
{
    return (t.horas*3600 + t.minutos*60 + t.segundos);
}

void segundosEnTiempo(Tiempo & t, int s)
{
    t.horas = s/3600;
    s %= 3600;
    t.minutos = s/60;
    t.segundos = s%60;
}

Tiempo obtenerNuevoTiempo(const Tiempo & t, int s)
{
    Tiempo aux;
    aux.horas = t.horas;
    aux.minutos = t.minutos;
    aux.segundos = t.segundos;

    if(s >= 86400 || s < 0)
    {
        aux.horas = 0;
        aux.minutos = 0;
        aux.segundos = 0;
    }
    else
    {
        Tiempo tmp;
        segundosEnTiempo(tmp, s);
        aux.segundos += tmp.segundos;
        if(aux.segundos > 59)
        {
            aux.segundos -= 60;
            aux.minutos += 1;
        }
        aux.minutos += tmp.minutos;
        if(aux.minutos > 59)
        {
            aux.minutos -= 60;
            aux.horas += 1;
        }
        aux.horas += tmp.horas;
        if(aux.horas > 23)
        {
            aux.horas = 0;
            aux.minutos = 0;
            aux.segundos = 0;
        }
    }

    return aux;
}