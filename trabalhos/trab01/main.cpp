#include <ctime>

#include "nacional.h"

using namespace std;

int main() {
    Estadual estado;
    Nacional brasil;

    for (int i = 0; i < MESES; i++){
        cout << brasil.getEstado(0).getVotos(1)[i] << endl;
        //cout << brasil.getEstado(0).avaliarEstabilidade(0) << endl;
    }

    brasil.avaliarEstabilidade();

    return 0;
}
