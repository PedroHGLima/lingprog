#include <iostream>

#include "paralelepipedo.h"

using namespace std;

int main() {
    double a, b, c;

    cout << "Entre com as dimensoes do paralelepipedo" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;

    Paralelepipedo p(a, b, c);

    cout << "Volume: " << p.getVolume() << endl;

    cout << endl << "Entre com as novas dimensoes do paralelepipedo" << endl;
    cout << "a: "; cin >> a; p.setX(a);
    cout << "b: "; cin >> b; p.setY(b);
    cout << "c: "; cin >> c; p.setZ(c);

    cout << "Novo volume: " << p.getVolume() << endl;

    return 0;
}
