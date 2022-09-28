#include <iostream>

#include "nacional.h"

using namespace std;

int main() {

    Estadual u;
    cout << "Votos por mes: ";
    for (int i=0; i<MESES; i++) {
        cout << u.getVotosPorMes()[i] << " ";
    }

    cout << endl << "Sigla: " << u.getSigla() << endl;

    u.mediaMovel(3);
    u.mediaMovel(7);

    return 0;
}
