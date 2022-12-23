#include "phospitalar.h"

PacienteHospitalar::PacienteHospitalar() : Paciente() {
    quadroClinico = "";
    diasInternado = 0;
}

PacienteHospitalar::PacienteHospitalar(string nome) : Paciente(nome) {
    quadroClinico = "";
    diasInternado = 0;
}

PacienteHospitalar::PacienteHospitalar(string nome, string s, int n) : Paciente(nome) {
    quadroClinico = s;
    diasInternado = n;
}

PacienteHospitalar::PacienteHospitalar(const Paciente& p) : Paciente(p) {
    quadroClinico = "";
    diasInternado = 0;
}

void PacienteHospitalar::setQuadroClinico(string s) {
    quadroClinico = s;
}

string PacienteHospitalar::getQuadroClinico() {
    return quadroClinico;
}

void PacienteHospitalar::setDiasInternado(int d) {
    diasInternado += d;
}

int PacienteHospitalar::getDiasInternado() {
    return diasInternado;
}

ostream& operator<<(ostream& os, PacienteHospitalar& p) {
    os << p << " - " << p.quadroClinico << endl << "Dias internado: " << p.diasInternado;
    return os;
}

PacienteClinico::PacienteClinico() : Paciente() {
    sintomas = "";
    horario = 0;
}

PacienteClinico::PacienteClinico(string nome) : Paciente(nome) {
    sintomas = "";
    horario = 0;
}

PacienteClinico::PacienteClinico(string nome, string s, int h) : Paciente(nome) {
    sintomas = s;
    horario = h;
}

PacienteClinico::PacienteClinico(const Paciente& p) : Paciente(p) {
    sintomas = "";
    horario = 0;
}

void PacienteClinico::setSintomas(string s) {
    sintomas = s;
}

string PacienteClinico::getSintomas() {
    return sintomas;
}

void PacienteClinico::setHorario(int h) {
    horario = h;
}

int PacienteClinico::getHorario() {
    return horario;
}

ostream& operator<<(ostream& os, PacienteClinico& p) {
    string horas = to_string(p.horario);
    if (horas.length() == 3) {
        horas = "0" + horas;
    }
    horas.insert(2, ":");
    os << p << " - " << p.sintomas << endl << "Consulta agendada para " << horas;
    return os;
}
