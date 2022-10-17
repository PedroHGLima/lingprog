#pragma once

#include <vector>

#include "aresta.h"

class Grafo {
    public:
        void addAresta(Aresta aresta);
    private:
        vector<Aresta> arestas;
};
