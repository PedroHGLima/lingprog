#pragma once

#include "paciente.h"

class PacienteHospitalar : public Paciente {
    friend ostream& operator<<(ostream& os, PacienteHospitalar& p);
    public:
        PacienteHospitalar();
        PacienteHospitalar(string nome);
        PacienteHospitalar(string nome, string s, int n);
        PacienteHospitalar(const Paciente& p);
        void setQuadroClinico(string s);
        string getQuadroClinico();
        void setDiasInternado(int d);
        int getDiasInternado();
    private:
        int diasInternado;
        string quadroClinico;
};

class PacienteClinico : public Paciente {
    friend ostream& operator<<(ostream& os, PacienteClinico& p);
    public:
        PacienteClinico();
        PacienteClinico(string nome);
        PacienteClinico(string nome, string s, int h);
        PacienteClinico(const Paciente& p);
        void setSintomas(string s);
        string getSintomas();
        void setHorario(int h);
        int getHorario();
    private:
        string sintomas;
        int horario; // Horário da consulta por exemplo, 8:00 = 800, 13:30 = 1330
};