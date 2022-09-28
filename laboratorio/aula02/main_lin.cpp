#include <iostream>

#include "linha.h"

using namespace std;

void printCoordenadas(Ponto p) {
    static int count = 1;
    cout << "[Impressao no. " << count;
    cout << ": Coordenadas do ponto: (" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")]" << endl;
    count++;
}

int main() {
    double a, b, c;

    cout << "Entre com as coordenadas do ponto 1" << endl;
    cout << "x: "; cin >> a;
    cout << "y: "; cin >> b;
    cout << "z: "; cin >> c;
    Ponto p1(a, b, c);

    cout << "Entre com as coordenadas do ponto 2" << endl;
    cout << "x: "; cin >> a;
    cout << "y: "; cin >> b;
    cout << "z: "; cin >> c;
    Ponto p2(a, b, c);

    Linha l(p1, p2);

    cout << "Comprimento: " << l.getComprimento() << endl;
    
    printCoordenadas(p1);
    printCoordenadas(p2);

    return 0;
}
