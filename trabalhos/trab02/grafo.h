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
        vector<Aresta> getArestas ();
        void addVertice (Vertice *vertice);
        void addVertice (int id);
        vector<Vertice> getVertices();
        list<pair<int, int> >* getAdj();
        vector<int> dijkstra (int origem, int destino);
        vector<int> dijkstra (char origem, char destino);
    private:
        int tamanho;
        list<pair<int, int> > * adj;
        vector<Aresta> arestas;
        vector<Vertice> vertices;
};
