#pragma once

#include "paciente.h"

class PacienteHospitalar : public Paciente {
    friend ostream& operator<<(ostream& os, PacienteHospitalar& p);
    public:
        PacienteHospitalar();
        PacienteHospitalar(string nome);
        PacienteHospitalar(string nome, string s);
        void setSintomas(string s);
        string getSintomas();
    private:
        string sintomas;
};