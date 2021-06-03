#include "Particula.h"
#include <cmath>
#include <iostream>



using namespace std;

// constructor sin parametros.
// Suponemos un tamaño minimo del mundo
// y una velocidad máxima permitida

Particula::Particula() {
    x = rand() % MIN_DIM + 1;
    y = rand() % MIN_DIM + 1;

    dx = rand() % MAX_VEL + 1;
    dy = rand() % MAX_VEL + 1;
    radio = RADIO;
}

float Particula::Distancia(const Particula & otra) const {
    float xx = otra.x - this->x;
    float yy = otra.y - this->y;

    return (sqrt(xx * xx + yy * yy));
}

bool Particula::Colision(const Particula & otra) const {
    float d = this->Distancia(otra);

    return (d < (this->radio + otra.radio));
}

float Particula::GetX() const {
    return (x);
}

float Particula::GetY() const {
    return (y);
}

float Particula::GetDX() const {
    return (dx);
}

float Particula::GetDY() const {
    return (dy);
}

float Particula::GetRadio() const {
    return (radio);
}

void Particula::SetXY(float _x, float _y){
    x = _x;
    y = _y;
}

void Particula::SetDX(float _dx) {
    dx = _dx;
}

void Particula::SetDY(float _dy) {
    dy = _dy;
}

void Particula::AjustarPosicion(int ancho, int alto) {
    
    if (x >= ancho - radio) 
        x = ancho - radio;
    else if (x <= radio) 
        x = radio;
    
    
    if (y >= alto - radio) 
        y = alto - radio;
    else if (y <= radio) 
        y = radio;
    
}

void Particula::MoverGrid(char dir, int ancho, int alto) {
    if (dir == 'U')
        y -= dy;

    if (dir == 'D')
        y += dy;

    if (dir == 'L')
        x -= dx;

    if (dir == 'R')
        x += dx;


    this->AjustarPosicion(ancho, alto);

}

void Particula::Mover(int ancho, int alto) {
    x += dx;
    y += dy;
    this->AjustarPosicion(ancho, alto);
}

void Particula::RebotaBordes(int ancho, int alto) {
    
    if ((x >= (ancho - radio)) || (x <= radio))
        dx *= -1.0f;

    if ((y >= (alto - radio)) || (y <= radio))
        dy *= -1.0f;

}

void Particula::Rotar(float posX, float posY, double rads) {
    float deltaX = x - posX;
    float deltaY = y - posY;

    x = posX + deltaX * cos(rads) - deltaY * sin(rads);
    y = posY + deltaX * sin(rads) + deltaY * cos(rads);

}  

std::string Particula::ToString() const{
    string s = "";
    s = "(x: " + to_string(x) + ", y: " + to_string(y) + ", ";
    s += " dx: " + to_string(dx) + ", dy: " + to_string(dy) + " R: " + to_string(radio) + ")";
    
    return s;
}

ostream& operator<<(ostream &flujo, const Particula &p) {
    flujo << p.ToString();
    flujo << endl;
    return flujo;
}

istream& operator>>(istream &flujo, Particula &p) {
    float x, y, dx, dy, radio;
    flujo >> x;
    flujo >> y;
    flujo >> dx;
    flujo >> dy;
    flujo >> radio;

    Particula aux(x,y,dx,dy,radio);
    p = aux;
    
    return flujo;
}

bool Particula::operator==(const Particula &p) const {
    bool iguales = false;

    if(Distancia(p) < ErrorMin)
        iguales = true;

    return iguales;
}