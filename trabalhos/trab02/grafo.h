#pragma once

#include <list>
#include <string>

#include "aresta.h"

class Grafo {
    public:
        Grafo (int tamanho);
        int getTamanho ();
        void setTamanho (int tamanho);
        void addAresta (Aresta *aresta);
        void addAresta(int origem, int destino, int peso);
        void addVertice (Vertice *vertice);
        void addVertice (int id);
        vector<Vertice> getVertices();
        list<pair<int, int> >* getAdj();
        int dijkstra (int origem, int destino);
    private:
        int tamanho;
        list<pair<int, int> > * adj;
        vector<Aresta> arestas;
        vector<Vertice> vertices;
};
