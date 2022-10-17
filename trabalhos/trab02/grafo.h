#pragma once

#include <list>
#include <vector>
#include <string>

#include "aresta.h"

class Grafo {
    public:
        Grafo (int tamanho);
        int get_tamanho ();
        void set_tamanho (int tamanho);
        void add_aresta (Aresta *aresta);
        void add_aresta(int origem, int destino, int peso);
        int dijkstra (int origem, int destino);
    private:
        int tamanho;
        list<pair<int, int> > * adj;
        vector<Aresta> arestas;
};
