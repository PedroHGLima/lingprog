#include "linha.h"
#include <iostream>

Linha::Linha(Ponto pa, Ponto pb) {
    p1 = pa; p2 = pb;
}

void Linha::setP1(Ponto p) {
    p1 = p;
}

void Linha::setP2(Ponto p) {
    p2 = p;
}

double Linha::getComprimento() {
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();
    double dz = p1.getZ() - p2.getZ();
    return sqrt(dx*dx + dy*dy + dz*dz);
}
