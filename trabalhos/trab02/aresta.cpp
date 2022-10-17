/**
 * @file aresta.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Arquivo com as funcionalidades da classe Aresta.
 * @version 2
 * @date 2022-10-17
 */

#include "aresta.h"

Aresta::Aresta(Vertice *origem, Vertice *destino, int peso) {
    this->origem = origem;
    this->destino = destino;
    this->peso = peso;
}

Vertice* Aresta::get_origem() {
    return this->origem;
}

Vertice* Aresta::get_destino() {
    return this->destino;
}

int Aresta::get_peso() {
    return this->peso;
}

void Aresta::set_origem(Vertice *origem) {
    this->origem = origem;
}

void Aresta::set_destino(Vertice *destino) {
    this->destino = destino;
}

void Aresta::set_peso(int peso) {
    this->peso = peso;
}
