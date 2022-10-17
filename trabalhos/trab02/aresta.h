#pragma once

#include "vertice.h"

class Aresta {
    public:
        Aresta(Vertice origem, Vertice destino, int peso);
        int getOrigem();
        int getDestino();
        int getPeso();
        void setOrigem(Vertice origem);
        void setDestino(Vertice destino);
        void setPeso(Vertice peso);
    private:
        Vertice origem;
        Vertice destino;
        Vertice peso;
};
