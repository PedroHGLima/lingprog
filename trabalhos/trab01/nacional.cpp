/**
 * @file nacional.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Arquivo de implementacao da classe Nacional
 * @version 1
 * @date 2022-09-29
 */

#include <ctime>

#include "nacional.h"

Nacional::Nacional(int nEstados) {
    /// @brief Contrutor da classe Nacional
    /// @param nEstados numero de estados a serem criados
    srand(time(NULL));          // inicializa gerador de numeros aleatorios
    gerarEstados(nEstados);     // gera nEstados estados
}

double Nacional::mediaMovel(unsigned int candidato, int mes) {
    /// @brief Calcula a media movel de um candidato num espaco de 3 meses
    /// @param candidato candidato a ser calculado
    /// @param mes mes para o qual a media movel sera calculada
    /// @return valor da media movel
    double soma=0, total=0;
    
    if (mes < 0 || mes >= MESES-3) {
        std::cout << "Mes invalido" << std::endl;
        return -1;
    }
    for (unsigned int i=0; i<estados.size(); i++) {
        soma += estados[i].mediaMovel(candidato, mes);
        total++;
    }
    return soma / total;
}

void Nacional::gerarEstados(int nEstados) {
    /// @brief controi os estados
    /// @param nEstados numero de estados a serem criados
    for (int i = 0; i < ESTADOS; i++) {
        estados.push_back(Estadual());
    }
    estados.resize(nEstados);
}

double Nacional::avaliarEstabilidade(unsigned int candidato) {
    /// @brief avalia a estabilidade de um candidato considerando todos os estados
    /// @param candidato candidato a ser avaliado
    int soma=0, total=(int)estados.size();

    for (size_t i = 0; i < estados.size(); i++){
        soma += estados[i].avaliarEstabilidade(candidato);
    }

    return soma/total;
}

Estadual Nacional::encontrarAlta(unsigned int candidato){
    /// @brief encontra o estado com maior estabilidade
    /// @param candidato candidato a ser avaliado
    /// @return estado com maior estabilidade
    Estadual estado = estados[0];
    double valor, maior = estado.avaliarEstabilidade(candidato);

    for (size_t i = 1; i < estados.size(); i++) {
        valor = estados[i].avaliarEstabilidade(candidato);
        if (valor > maior) {
        // Se o valor for maior do que o registrado, atualiza o maior valor
            maior = valor;
            estado = estados[i];
        }
    }

    return estado;
}

int Nacional::calcularVantagem() {
    /// @brief calcula a vantagem de um candidato
    /// @return numero de estados em que o candidato tem vantagem
    /// @bug em caso de empate, o candidato que alcanca a vantagem primeiro eh considerado o vencedor
    unsigned int vantagem = 0;      // o candidato que esta na vantagem
    int maior=0, atual;             // votos dos candidatos com vantagem e sendo analizado

    for (unsigned int i = 0; i < CANDIDATOS; i++) {
        atual = 0;
        for (size_t j = 0; j < estados.size(); j++)
        // Soma os votos do ultimo mes de cada estado
            atual += estados.at(j).getVotos(i).front();
        
        if (atual > maior) {
        // Se o valor for maior do que o registrado, atualiza o maior valor
            maior = atual;
            vantagem = i;
        }
    }

    return vantagem;
}

Estadual Nacional::getEstado(int i) {
    return estados[i];
}
