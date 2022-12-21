#include "phospitalar.h"

PacienteHospitalar::PacienteHospitalar() : Paciente() {
    sintomas = "";
}

PacienteHospitalar::PacienteHospitalar(string nome) : Paciente(nome) {
    sintomas = "";
}

PacienteHospitalar::PacienteHospitalar(string nome, string s) : Paciente(nome) {
    sintomas = s;
}

void PacienteHospitalar::setSintomas(string s) {
    sintomas += s;
}

string PacienteHospitalar::getSintomas() {
    return sintomas;
}

ostream& operator<<(ostream& os, PacienteHospitalar& p) {
    os << p.getNome() << " - " << p.sintomas;
    return os;
}
