#include <iostream>

#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(double a, double b, double c) {
    setX(a);
    setY(b);
    setZ(c);
}

void Paralelepipedo::setX(double a) {
    if (a>0) x = a;
    else {
        std::cout << "Valor invalido para x" << std::endl;
        x = 1;
    }
}

void Paralelepipedo::setY(double b) {
    if (b>0) y = b;
    else {
        std::cout << "Valor invalido para y" << std::endl;
        y = 1;
    }
}

void Paralelepipedo::setZ(double c) {
    if (c>0) z = c;
    else {
        std::cout << "Valor invalido para z" << std::endl;
        z = 1;
    }
}

double Paralelepipedo::getVolume() {
    return computeVolume();
}

double Paralelepipedo::computeVolume() {
    return x * y * z;
}
