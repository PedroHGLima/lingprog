#pragma once

#include "paciente.h"

class Cadastro {
    public:
        Cadastro();
        void insere(Paciente *p);
        void insere(Paciente *p, Arvore<Paciente> *arv);
        Paciente *busca(string nome);
        void imprime();
        void imprime(Arvore<Paciente> *arv);
    private:
        Arvore<Paciente> *arvore;
};
