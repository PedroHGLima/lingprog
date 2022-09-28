#include <ctime>

#include "estadual.h"

Estadual::Estadual(unsigned int candidatos) {
    srand(time(0));             // inicializa gerador de numeros aleatorios
    votos.resize(candidatos);   // inicializa vetor de candidatos
    for (unsigned int i=0; i<candidatos; i++)
        gerarDados(i);          // gera votos para cada candidato

    // gera sigla aleatoria para o estado
    sigla[0] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    sigla[1] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    sigla[2] = '\0';
}

void Estadual::gerarDados(unsigned int candidato) {
    for (int i=0; i<MESES; i++)
        votos[candidato].push_back(rand() % 1000);  // gera votos aleatorios para cada mes
    votos[candidato].resize(MESES); // garante que o vetor tenha exatamente MESES elementos
}

double Estadual::mediaMovel(int numMeses, unsigned int candidato) {
    int soma = 0;
    for (int i=0; i<numMeses; i++) {
        soma += votos[candidato][i];
    }
    return soma / numMeses;
}

double Estadual::avaliarEstabilidade(unsigned int candidato) {
    double atual = mediaMovel(MESES, candidato);               // media movel do mes atual
    double anterior = mediaMovel(MESES - 1, candidato);        // media movel do mes anterior

/*
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
*/
    return atual/anterior*100;
}

std::vector<int> Estadual::getVotos(unsigned int candidato) {
    return votos[candidato];
}

char* Estadual::getSigla() {
    return sigla;
}
