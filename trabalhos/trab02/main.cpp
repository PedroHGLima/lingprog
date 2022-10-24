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
#include <iomanip>

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
            // Adiciona os dados da linha ao vector de dados
            vector<string> aresta = split(linha);
            origens.push_back(stoi((aresta[0])));
            destinos.push_back(stoi((aresta[1])));
            pesos.push_back(stoi((aresta[2])));
            // Adiciona os dados na ordem inversa
            origens.push_back(stoi((aresta[1])));
            destinos.push_back(stoi((aresta[0])));
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

void imprimirEnlaces(Grafo &ref) {
    /// @brief Imprime os vertices do grafo.
    /// @param ref Referencia para o grafo.
    list<pair<int, int> > *adjacencias = ref.getAdj();
    vector<Vertice> vertices = ref.getVertices();

    cout << "Vertices" << setw(10) << "Enlaces" << endl;
    for (int i =0 ; i < ref.getTamanho(); i++) {
        cout << vertices[i].get_id() << setw(11) << adjacencias[i].size() << endl;
    }
}

int main () {
    int tamanho;
    vector <vector<int> > dados;
    
    // Cria o grafo
    dados = ler_arquivo("exemplo.csv");
    tamanho = dados.at(3).size();
    Grafo grafo(tamanho);

    // Adiciona as arestas
    for (size_t i = 0; i < dados[0].size(); i++) {
        grafo.addAresta(dados[0][i], dados[1][i], dados[2][i]);
    }

    // Adiciona os vertices
    for (size_t i = 0; i < dados[3].size(); i++) {
        grafo.addVertice(dados[3][i]);
    }

    // Imprime os vertices e o numero de enlaces
    imprimirEnlaces(grafo);

    //cout << grafo.dijkstra(0, 2) << endl;

    return 0;
}
