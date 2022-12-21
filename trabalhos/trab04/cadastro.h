#pragma once

#include "phospitalar.h"

class Cadastro {
    friend ostream& operator<<(ostream& os, Cadastro& c);
    public:
        Cadastro();
        void insere(PacienteHospitalar *p);
        void insere(PacienteHospitalar *p, Arvore<PacienteHospitalar*> *arv);
        Cadastro operator+(PacienteHospitalar *p);
        PacienteHospitalar *busca(string nome);
        PacienteHospitalar* busca(string nome, Arvore<PacienteHospitalar*> *arv);
        PacienteHospitalar* operator[](string nome);
        void imprime();
        void imprime(Arvore<PacienteHospitalar*> *arv);
    private:
        Arvore<PacienteHospitalar*> *arvore;
};
