/**
 * @file main.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Arquivo principal para execucao do trabalho 2.
 * @version 2 (trabalho 02)
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "grafo.h"

vector<string> split(string str, char delimiter=',') {
    /// @brief Divide uma string em substrings, separadas por um delimitador.
    /// @param str String a ser dividida.
    /// @param delimiter Caractere delimitador.
    /// @return Vector de strings
    vector<string> saida;
    while (str.find(delimiter) != string::npos) {
        // Enquanto o delimitador estiver na string, divide a string em duas
        saida.push_back(str.substr(0, str.find(delimiter)));
        str.erase(0, str.find(delimiter) + 1);
    }
    saida.push_back(str);
    return saida;
}

vector<vector<int> > ler_arquivo(string nome_arquivo) {
    /// @brief Lê um arquivo CSV e retorna um vector de vetor de inteiros.
    /// @param nome_arquivo string com o nome do arquivo a ser lido.
    /// @return Vector com os dados do arquivo [origens, destinos, pesos, vertices].
    vector<vector<int> > dados;
    dados.resize(4);
    vector<int> origens, destinos, pesos, vertices;
    ifstream arquivo(nome_arquivo);
    string linha;

    if (arquivo.is_open()) {
        // Lê o arquivo linha por linha
        getline(arquivo, linha);
        while (getline(arquivo, linha)) {
            vector<string> aresta = split(linha);
            origens.push_back(stoi((aresta[0])));
            destinos.push_back(stoi((aresta[1])));
            pesos.push_back(stoi((aresta[2])));
        }
        arquivo.close();


        // Todos os vertices com conexoes devem aparecer na lista de origens e destinos
        vertices = origens;
        vertices.insert(vertices.end(), destinos.begin(), destinos.end());

        // Remove duplicatas
        sort(vertices.begin(), vertices.end());
        vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
    }
    else {
        cout << "Não foi possível abrir o arquivo";
    }

    dados[0] = origens;
    dados[1] = destinos;
    dados[2] = pesos;
    dados[3] = vertices;
    return dados;
}

int main () {
    int tamanho;
    vector <vector<int> > dados;
    
    // Cria o grafo
    dados = ler_arquivo("exemplo.csv");
    tamanho = dados.at(3).size();
    Grafo grafo(tamanho);
    for (size_t i = 0; i < dados[0].size(); i++) {
        grafo.add_aresta(dados[0][i], dados[1][i], dados[2][i]);
    }

    cout << grafo.dijkstra(0, 3) << endl;

    return 0;
}
