/**
 * @file grafo.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Arquivo com as funcionalidades da classe Grafo.
 * @version 2
 * @date 2022-10-17
 */

#include <iostream>
#include <fstream>
#include <queue>
#include <iostream>

#include "grafo.h"

#define INFINITO 10000000

Grafo::Grafo(int tamanho) {
    this->tamanho = tamanho;
    adj = new list<pair<int, int> >[tamanho];
}

void Grafo::addVertice(Vertice *vertice) {
    this->vertices.push_back(*vertice);
}

void Grafo::addVertice(int id) {
    Vertice *vertice = new Vertice(id);
    this->vertices.push_back(*vertice);
}

void Grafo::addAresta(Aresta *aresta) {
    this->arestas.push_back(*aresta);
    this->adj[aresta->get_origem()->get_id()].push_back(make_pair(aresta->get_destino()->get_id(), aresta->get_peso()));
}

void Grafo::addAresta(int origem, int destino, int peso) {
    Aresta *aresta = new Aresta(new Vertice(origem), new Vertice(destino), peso);
    this->arestas.push_back(*aresta);
    adj[origem].push_back(make_pair(destino, peso));
}

vector<int> Grafo::dijkstra(int origem, int destino) {
    /// @brief Calcula o menor caminho entre dois vértices, usando o algoritmo de Dijkstra.
    /// @param origem Vertice de origem.
    /// @param destino Vertice de destino.
    /// @return Caminho ate o destino, o ultimo elemento do vetor eh o peso do caminho.
    int distancias[tamanho], visitados[tamanho];
    vector <vector<int> > caminho(tamanho);

    // fila de prioridades de pair (distancia, vértice)
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // inicia o vetor de distâncias e visitados
    for(int i = 0; i < tamanho; i++) {
        distancias[i] = INFINITO;
        visitados[i] = false;
        caminho[i] = {i};
    }

    // a distância de origem para origem é 0
    distancias[origem] = 0;
    caminho[origem] = {origem};

    // insere na fila
    pq.push(make_pair(0, origem));

    // loop do algoritmo
    while(!pq.empty())
    {
        pair<int, int> p = pq.top(); // extrai o pair do topo
        int u = p.second; // obtém o vértice do pair
        pq.pop(); // remove da fila

        // verifica se o vértice não foi expandido
        if(visitados[u] == false)
        {
            // marca como visitado
            visitados[u] = true;

            list<pair<int, int> >::iterator it;

            // percorre os vértices "v" adjacentes de "u"
            for(it = adj[u].begin(); it != adj[u].end(); it++)
            {
                // obtém o vértice adjacente e o custo da aresta
                int v = it->first;
                int custo_aresta = it->second;

                // relaxamento (u, v)
                if(distancias[v] > (distancias[u] + custo_aresta))
                {
                    // atualiza a distância de "v" e insere na fila
                    distancias[v] = distancias[u] + custo_aresta;
                    caminho[v].insert(caminho[v].begin(), caminho[u].begin(), caminho[u].end());
                    pq.push(make_pair(distancias[v], v));
                }
            }
        }
    }

    caminho[destino].push_back(distancias[destino]);
    // retorna o caminho minimo ate o destino
    return caminho[destino];
}

vector<int> Grafo::dijkstra(char origem, char destino) {
    return dijkstra(int(origem) - 'A', int(destino) - 'A');
}

bool Grafo::isConexo() {
    /// @brief Verifica se o grafo é conexo.
    /// @return True se o grafo for conexo, false caso contrario.
    int visitados[tamanho];
    queue<int> fila;

    // inicia o vetor de visitados
    for(int i = 0; i < tamanho; i++) {
        visitados[i] = false;
    }

    // marca o primeiro vertice como visitado
    visitados[0] = true;
    fila.push(0);

    // loop do algoritmo
    while(!fila.empty())
    {
        int u = fila.front(); // extrai o vértice do topo
        fila.pop(); // remove da fila

        list<pair<int, int> >::iterator it;

        // percorre os vértices "v" adjacentes de "u"
        for(it = adj[u].begin(); it != adj[u].end(); it++)
        {
            // obtém o vértice adjacente
            int v = it->first;

            // verifica se o vértice não foi visitado
            if(visitados[v] == false)
            {
                // marca como visitado
                visitados[v] = true;
                fila.push(v);
            }
        }
    }

    // verifica se todos os vertices foram visitados
    for(int i = 0; i < tamanho; i++) {
        if(visitados[i] == false) {
            return false;
        }
    }

    return true;
}

Vertice Grafo::maisCentral() {
    /// @brief Calcula o vertice com maior centralidade do grafo
    /// @return Vertice mais central
    int i_central = 0, ligacoes, maior = adj[0].size();
    // Inicia os valores considerando que o primeiro vertice eh o mais central

    for (int i = 0; i < tamanho; i++) {
        // Percorre todos os vertices do grafo, exceto o primeiro
        ligacoes = adj[i].size();
        cout << "Vertice " << i << " tem " << ligacoes << " ligacoes" << endl;
        // O numero de conexoes de um vertice eh o tamanho da lista de adjacencia
        if (ligacoes > maior) {
            maior = ligacoes;
            i_central = i;
        }
    }
    
    return vertices[i_central];
}

list<pair<int, int> >* Grafo::getAdj() {
    return this->adj;
}

vector<Vertice> Grafo::getVertices() {
    return this->vertices;
}

vector<Aresta> Grafo::getArestas() {
    return this->arestas;
}

int Grafo::getTamanho() {
    return this->tamanho;
}

void Grafo::setTamanho(int tamanho) {
    this->tamanho = tamanho;
    adj = new list<pair<int, int> >[tamanho];
}
