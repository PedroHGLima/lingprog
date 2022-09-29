/**
 * @file estadual.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Arquivo de implementacao da classe Estadual
 * @version 1
 * @date 2022-09-29
 */

#include "estadual.h"

Estadual::Estadual() {
    /// @brief Construtor da classe Estadual
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
    /// @brief gera os votos para um candidato
    /// @param candidato candidato a ser gerado
    for (int i=0; i<MESES; i++)
        votos[candidato].push_back(rand() % 50);  // gera votos aleatorios para cada mes
    votos[candidato].resize(MESES); // garante que o vetor tenha exatamente MESES elementos
}

double Estadual::mediaMovel(unsigned int candidato, int numMeses) {
    /// @brief Calcula a media movel de um candidato
    /// @param candidato candidato a ser calculado
    /// @param numMeses numero de meses a serem considerados [3,7]
    /// @return valor da media movel
    if (numMeses < 3 || numMeses > MESES) {
        std::cout << "Numero de meses invalido" << std::endl;
        return -1;
    }
    int soma = 0;
    for (int i=0; i<numMeses; i++) {
        soma += votos.at(candidato).at(i);
    }
    return soma / numMeses;
}

double Estadual::avaliarEstabilidade(unsigned int candidato) {
    /// @brief Calcula a estabilidade de um candidato
    /// @param candidato candidato a ser calculado
    /// @return valor da variacao percentual
    double atual = mediaMovel(candidato, MESES);               // media movel do mes atual
    double anterior = mediaMovel(candidato, MESES - 1);        // media movel do mes anterior
    return atual/anterior*100;
}

std::vector<int> Estadual::getVotos(unsigned int candidato) {
    return votos[candidato];
}

std::string Estadual::getSigla() {
    return sigla;
}
