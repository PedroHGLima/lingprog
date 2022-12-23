#pragma once

#include "arvore.h"

class Paciente {
    friend ostream& operator<<(ostream& os, const Paciente& p);
    public:
        Paciente();
        Paciente(string nome);
        Paciente(const Paciente& p);
        virtual ~Paciente() = default;
        string getNome();
        void setNome(string nome);
        bool operator<(Paciente p);
        bool operator>(Paciente p);
        bool operator==(Paciente p);
        bool operator!=(Paciente p);
    private:
        string nome;    
};
