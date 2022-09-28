#include "ponto.h"

Ponto::Ponto(double a, double b, double c) {
    setX(a); setY(b); setZ(c);
}

void Ponto::setX(double a) {
    x = a;
}

void Ponto::setY(double b) {
    y = b;
}

void Ponto::setZ(double c) {
    z = c;
}

double Ponto::getX() {
    return x;
}

double Ponto::getY() {
    return y;
}

double Ponto::getZ() {
    return z;
}
