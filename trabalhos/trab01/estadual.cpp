#include <ctime>

#include "estadual.h"

Estadual::Estadual() {
    srand(time(0));
    gerarDados();
    sigla[0] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    sigla[1] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    sigla[2] = '\0';
}

void Estadual::gerarDados() {
    for (int i=0; i<MESES; i++) {
        votosPorMes.push_back(rand() % 1000);
    }
}

double Estadual::mediaMovel(int numMeses) {
    int soma = 0;
    for (int i=0; i<numMeses; i++) {
        soma += votosPorMes[i];
    }
    std::cout << "Media movel de " << numMeses << " meses: " << soma / numMeses << std::endl;
    return soma / numMeses;
}

void Estadual::avaliarEstabilidade() {
    double atual = mediaMovel(MESES);               // media movel do mes atual
    double anterior = mediaMovel(MESES - 1);        // media movel do mes anterior
    double varPercentual = atual/anterior*100;      // variacao percentual


    if (varPercentual <= 98) {
        // Variacao indica queda de 2% ou mais
        std::cout << "Em queda" << std::endl;
    } else if (varPercentual >= 102) {
        // Variacao indica alta de 2% ou mais
        std::cout << "Em alta" << std::endl;
    } else {
        // Variacao indica estabilidade
        std::cout << "Estavel" << std::endl;
    }
}

std::vector<int> Estadual::getVotosPorMes() {
    return votosPorMes;
}

char* Estadual::getSigla() {
    return sigla;
}
