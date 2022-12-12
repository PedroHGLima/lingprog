#pragma once

#include "arvore.h"

class Paciente {
    public:
        Paciente();
        Paciente(string nome);
        string getNome();
        void setNome(string nome);
    private:
        string nome;    
};
