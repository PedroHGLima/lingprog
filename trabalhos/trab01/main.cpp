#include <iostream>

#include "nacional.h"

using namespace std;

int main() {

    Estadual estado;

    for (int i = 0; i < MESES; i++){
        cout << estado.getVotos(0)[i] << endl;
        cout << estado.getVotos(1)[i] << endl;
    }

    return 0;
}
