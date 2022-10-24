/**
 * @file vertice.cpp
 * @author Pedro Lima (pedrolima@poli.ufrj.br) (DRE: 120019143)
 * @brief Funcionalidades da classe Vertice.
 * @version 2
 * @date 2022-10-17
 */

#include "vertice.h"

Vertice::Vertice(int id) {
    this->id = id;
}

int Vertice::get_id() {
    return this->id;
}

void Vertice::set_id(int id) {
    this->id = id;
}
