#include "nacional.h"
#include "estadual.h"

Nacional::Nacional() {
    gerarEstados();
}

void Nacional::gerarEstados() {
    for (int i = 0; i < ESTADOS; i++) {
        estados.push_back(Estadual());
    }
}