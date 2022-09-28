#include "estadual.h"

Estadual::Estadual() {
    votos.resize(CANDIDATOS);   // inicializa vetor de candidatos
    for (unsigned int i=0; i<CANDIDATOS; i++)
        gerarDados(i);          // gera votos para cada candidato

    // gera sigla aleatoria para o estado
    sigla.resize(3);
    sigla[0] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    sigla[1] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    sigla[2] = '\0';
}

void Estadual::gerarDados(unsigned int candidato) {
    for (int i=0; i<MESES; i++)
        votos[candidato].push_back(rand() % 50);  // gera votos aleatorios para cada mes
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
    return atual/anterior*100;
}

std::vector<int> Estadual::getVotos(unsigned int candidato) {
    return votos[candidato];
}

std::string Estadual::getSigla() {
    return sigla;
}
