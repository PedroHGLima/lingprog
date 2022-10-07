/**
 * @file main.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Arquivo principal do trabalho avaliado 1
 * @version 1 (trabalho 1)
 * @date 2022-09-29
 */

#include <iomanip>

#include "nacional.h"

using namespace std;

void evolucaoMedia(Nacional &ref) {
    /// @brief imprime a evolucao da media movel de cada candidato
    /// @param ref referencia para o objeto Nacional
    char nome;
    cout.precision(2);

    cout << "Evolucao da media movel de cada candidato:" << endl;
    cout << "Mes atual ===> Mes mais antigo" << fixed << endl;
    for (unsigned int i = 0; i < CANDIDATOS; i++) {
        // Percorre todos os candidatos
        nome = 'A' + i;
        cout << "Candidato " << nome << ": " << endl;
        for (int j = 0; j < ESTADOS; j++) {
            // Percorre todos os estados
            cout << "Estado " << ref.getEstado(j).getSigla() << ": ";
            for (int k = 0; k < MESES-3; k++) {
                // Percorre todos os meses, 3 eh o espaco de tempo da media movel
                cout << ref.getEstado(j).mediaMovel(i, k) << " ";
            }
            cout << endl;
        }
        cout << "Media movel nacional: " << endl;
        for (int k = 0; k < MESES-3; k++) {
            // Percorre todos os meses, 3 eh o espaco de tempo da media movel
            cout << ref.mediaMovel(i, k) << " ";
        }
        cout << endl;
    }
}

void avaliacaoDeAlta(Nacional &ref) {
    /// @brief Percorre todos os estados, printando em forma de tabela se o estado apresenta uma alta para tal candidato.
    /// @param ref referencia para objeto Nacional

    double taxa;
    vector<vector<string>> tabela;
    tabela.resize(3); // Uma linha para alta, estavel e baixa

    for (int i = 0; i < CANDIDATOS; i++) {
        for (int j = 0; j < ESTADOS; j++){
            taxa = ref.getEstado(j).avaliarEstabilidade(i);
            if (taxa > 102) {
                tabela[0].push_back(ref.getEstado(j).getSigla());
            }
            else if (taxa >= 98) {
                tabela[1].push_back(ref.getEstado(j).getSigla());
            }
            else {
                tabela[2].push_back(ref.getEstado(j).getSigla());
            }
        }
        cout << "Candidato " << (char)('A' + i) << ": " << endl;
        cout << "Estados em alta: ";
        for (unsigned int j = 0; j < tabela[0].size(); j++) {
            cout << tabela[0][j] << " ";
        }
        cout << endl;
        cout << "Estados em estabilidade: ";
        for (unsigned int j = 0; j < tabela[1].size(); j++) {
            cout << tabela[1][j] << " ";
        }
        cout << endl;
        cout << "Estados em baixa: ";
        for (unsigned int j = 0; j < tabela[2].size(); j++) {
            cout << tabela[2][j] << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++)
            tabela.at(i).clear();
    }
}

void avaliacaoNacional(Nacional &ref) {
    /// @brief Avalia a estabilidade de cada candidato, considerando todos os estados
    /// @param ref referencia para objeto Nacional
    cout << "Taxa de crescimento nacional:" << endl;
    cout << "Candidato A: " << ref.avaliarEstabilidade(0) << "%" << endl;
    cout << "Candidato B: " << ref.avaliarEstabilidade(1) << "%" << endl;
}

void acharAlta(Nacional &ref) {
    /// @brief Encontra o estado com maior alta para cada candidato
    /// @param ref referencia para objeto Nacional
    cout << "Estado com maior alta:" << endl;
    cout << "Candidato A: " << ref.encontrarAlta(0).getSigla() << endl;
    cout << "Candidato B: " << ref.encontrarAlta(1).getSigla() << endl;
}

void acharVantagem(Nacional &ref) {
    /// @brief Calcula a vantagem de um candidato sobre o outro
    /// @param ref referencia para objeto Nacional
    int x = ref.calcularVantagem()+'A'; // Converte o inteiro para char
    cout << "O candidato " << (char) x << " esta na vantagem" << endl;
}

int main() {
    Nacional brasil; Nacional &br = brasil;
    //Estadual estado; Estadual &es = estado;

    int comando;
    cout << "Para ajuda, use o comando 9" << endl;

    for (;;) {
        cout << "Digite o numero do comando desejado: ";cin >> comando;
        switch (comando) {
            case 1:
                evolucaoMedia(br);
                break;
            case 2:
                avaliacaoDeAlta(br);
                break;
            case 3:
                avaliacaoNacional(br);
                break;
            case 4:
                acharAlta(br);
                break;
            case 5:
                acharVantagem(br);
                break;
            case 9:
                cout << "Este programa se refere aos estados usando suas siglas, geradas automaticamente." << endl;
                cout << "1 - Evolucao da media movel de cada candidato" << endl;
                cout << "2 - Avaliar estados em alta" << endl;
                cout << "3 - Avaliar crescimento em escala nacional" << endl;
                cout << "4 - Achar estado com maior alta" << endl;
                cout << "5 - Calcular o candidato que esta na vantagem" << endl;
                cout << "9 - Ajuda" << endl;
                cout << "0 - Sair" << endl;
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                return 0;
            default:
                cout << "Comando invalido" << endl;
                break;
        }
    cout << endl;
    }

    return 0;
}
