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
    // evita as letras K, Y e W
    if (sigla[0] == 75 || sigla[0] == 89 || sigla[0] == 87)
        sigla[0] += 1;
    sigla[1] = 65 + ( rand() % ( 90 - 65 + 1 ) );
    // evita as letras K, Y e W
    if (sigla[1] == 75 || sigla[1] == 89 || sigla[1] == 87)
        sigla[1] += 1;
    sigla[2] = '\0';
}

void Estadual::gerarDados(unsigned int candidato) {
    /// @brief gera os votos para um candidato
    /// @param candidato candidato a ser gerado
    for (int i=0; i<MESES; i++)
        votos[candidato].push_back(rand() % 50);  // gera votos aleatorios para cada mes
    votos[candidato].resize(MESES); // garante que o vetor tenha exatamente MESES elementos
}

double Estadual::mediaMovel(unsigned int candidato, int mes) {
    /// @brief Calcula a media movel de um candidato num espaco de 3 meses
    /// @param candidato candidato a ser calculado
    /// @param mes mes para o qual a media movel sera calculada
    /// @return valor da media movel
    double soma=0, total=0;
    
    if (mes < 0 || mes >= MESES-3) {
        std::cout << "Mes invalido" << std::endl;
        return -1;
    }
    for (int i=mes; total<3; i++) {
        soma += votos[candidato][i];
        total++;
    }
    return soma / total;
}

double Estadual::avaliarEstabilidade(unsigned int candidato) {
    /// @brief Calcula a estabilidade de um candidato
    /// @param candidato candidato a ser calculado
    /// @return valor da variacao percentual
    double atual = mediaMovel(candidato, 0);              // media movel do mes atual
    double anterior = mediaMovel(candidato, 1);           // media movel do mes anterior
    anterior == 0 ? anterior = 1 : anterior = anterior;   // evita divisao por zero
    return atual/anterior*100;
}

std::vector<int> Estadual::getVotos(unsigned int candidato) {
    return votos[candidato];
}

std::string Estadual::getSigla() {
    return sigla;
}
