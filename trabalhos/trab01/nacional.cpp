#include "nacional.h"

Nacional::Nacional(int nEstados) {
    gerarEstados(nEstados);
}

void Nacional::gerarEstados(int nEstados) {
    for (int i = 0; i < ESTADOS; i++) {
        estados.push_back(Estadual());
    }
    estados.resize(nEstados);
}

void Nacional::avaliarEstabilidade() {
    std::vector<std::string> altasA, altasB;
    for (size_t i = 0; i < estados.size(); i++) {
        if (estados[i].avaliarEstabilidade(0) > 102) {
            altasA.push_back(estados[i].getSigla());
        }
        if (estados[i].avaliarEstabilidade(1) > 102) {
            altasB.push_back(estados[i].getSigla());
        }
    }

    // Imprime os estados que o candidato A esta em alta
    std::cout << "Estados em que o candidato A esta em alta:" << std::endl;
    for (size_t i = 0; i < altasA.size(); i++) {
        std::cout << altasA[i] << " ";
    }
    std::cout << std::endl;

    // Imprime os estados que o candidato B esta em alta
    std::cout << "Estados em que o candidato B esta em alta:" << std::endl;
    for (size_t i = 0; i < altasB.size(); i++) {
        std::cout << altasB[i] << " ";
    }
    std::cout << std::endl;

}

void Nacional::avaliarEstabilidadeNacional() {
    // TODO
}

Estadual Nacional::getEstado(int i) {
    return estados[i];
}
