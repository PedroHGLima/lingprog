#pragma once

#include "arvore.h"

class Paciente {
    public:
        Paciente();
        Paciente(string nome);
        string getNome();
        void setNome(string nome);
        bool operator<(Paciente p);
        bool operator>(Paciente p);
        bool operator==(Paciente p);
    private:
        string nome;    
};
