#pragma once

#include "paciente.h"

class Cadastro {
    friend ostream& operator<<(ostream& os, Cadastro& c);
    public:
        Cadastro();
        void insere(Paciente *p);
        void insere(Paciente *p, Arvore<Paciente*> *arv);
        Cadastro operator+(Paciente *p);
        Paciente *busca(string nome);
        Paciente* busca(string nome, Arvore<Paciente*> *arv);
        Paciente* operator[](string nome);
        void imprime();
        void imprime(Arvore<Paciente*> *arv);
    private:
        Arvore<Paciente*> *arvore;
};
