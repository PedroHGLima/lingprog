#pragma once

#include "paciente.h"

class Cadastro {
    public:
        Cadastro();
        void inserir(Paciente *p);
        void inserir(Paciente *p, Arvore<Paciente> *arv);
        void imprime();
        void imprime(Arvore<Paciente> *arv);
    private:
        Arvore<Paciente> *arvore;
};
