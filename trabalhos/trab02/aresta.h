#pragma once

#include "vertice.h"

class Aresta {
    public:
        Aresta (Vertice* origem, Vertice* destino, int peso);
        Vertice* get_origem ();
        Vertice* get_destino ();
        int get_peso ();
        void set_origem (Vertice* origem);
        void set_destino (Vertice* destino);
        void set_peso (int peso);
    private:
        Vertice* origem;
        Vertice* destino;
        int peso;
};
