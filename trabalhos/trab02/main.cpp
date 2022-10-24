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
        }
        arquivo.close();

        // Adiciona as arestas na ordem inversa
        // Isso é necessário para que o algoritmo de Dijkstra funcione corretamente
        // Implica que a lista de arestas na verdade sera metade do tamanho da lista aqui presente
        size_t tamanho = origens.size();
        for (size_t i =0; i<tamanho; i++) {
            origens.push_back(destinos[i]);
            destinos.push_back(origens[i]);
            pesos.push_back(pesos[i]);
        }


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
    char sigla = 'A';
    list<pair<int, int> > *adjacencias = ref.getAdj();
    vector<Vertice> vertices = ref.getVertices();

    cout << "Vertices" << setw(10) << "Enlaces" << endl;
    for (int i =0 ; i < ref.getTamanho(); i++) {
        sigla += (char)vertices[i].get_id();
        cout << sigla << setw(11) << adjacencias[i].size() << endl;
        sigla = 'A';
    }
}

void imprimirArestas(Grafo &ref) {
    /// @brief Imprime os vertices do grafo, seguido de suas arestas e respectivos pesos
    /// @param ref referencia para o grafo
    char sigla = 'A';
    cout << "Vertices: ";
    for (int i =0 ; i < ref.getTamanho(); i++) {
        // Imprime os vertices
        sigla += (char)ref.getVertices()[i].get_id();
        cout << sigla << " ";
        sigla = 'A';
    }

    cout << endl << "Arestas" << setw(8) << "Peso" << endl;
    vector<Aresta> arestas = ref.getArestas();
    for (size_t i=0; i<arestas.size()/2; i++) {
        // Imprime as arestas
        sigla += (char)arestas[i].get_origem()->get_id();
        cout << sigla << (char)(arestas[i].get_destino()->get_id() + 'A') << setw(10) << arestas[i].get_peso() << endl;
        sigla = 'A';
    }
}

void mostrarCaminho(Grafo &ref) {
    char sigla = 'A';
    char origem, destino;
    vector<int> caminho;

    for(;;){
        cout << "Digite o vertice de origem: "; cin >> origem;
        if (origem >= 'A' && origem <= 'Z') {
            // Entrada correta da origem
            break;
        }
        else if (origem >= 'a' && origem <= 'z') {
            // Entrada minuscula da origem, converte para maiuscula
            origem -= 32;
            break;
        }
        else {
            // Caso invalido
            cout << "Entrada invalida" << endl;
        }
        cout << "Vertice invalido" << endl;
    }

    for (;;) {
        cout << "Digite o vertice de destino: "; cin >> destino;
        if (destino >= 'A' && destino <= 'Z') {
            // Entrada correta do destino
            break;
        }
        else if (destino >= 'a' && destino <= 'z') {
            // Entrada minuscula do destino, converte para maiuscula
            destino -= 32;
            break;
        }
        else {
            // Caso invalido
            cout << "Entrada invalida" << endl;
        }
    }

    if ((origem > (char)ref.getTamanho()+'@' || origem < 'A') || (destino > (char)ref.getTamanho()+'@' || destino < 'A')) {
        // Caso um dos vertices nao exista
        cout << "Vertice invalido" << endl;
        return;
    }

    caminho = ref.dijkstra(origem, destino);

    cout << "Caminho: ";
    for (size_t i=0; i<caminho.size()-2; i++) {
        sigla += (char)caminho[i];
        cout << sigla << " -> ";
        sigla = 'A';
    }
    cout << destino << endl;

    cout << "Custo: " << caminho.back();
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
    cout << endl;

    // Imprime as arestas e seus pesos
    imprimirArestas(grafo);
    cout << endl;

    // Imprime o caminho mais curto entre dois vertices
    mostrarCaminho(grafo);
    cout << endl;

    return 0;
}
