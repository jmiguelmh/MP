#ifndef TIEMPO_H
#define TIEMPO_H

    struct Tiempo{
        int horas;
        int minutos;
        int segundos;
    };

    bool esPosterior(const Tiempo & t1, const Tiempo & t2);

    int tiempoEnSegundos(const Tiempo & t);

    void segundosEnTiempo(Tiempo & t, int s);

    Tiempo obtenerNuevoTiempo(const Tiempo & t, int s);

#endif