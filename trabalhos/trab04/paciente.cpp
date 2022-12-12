#include "paciente.h"

Paciente::Paciente() {
    nome = "";
}

Paciente::Paciente(string nome) {
    this->nome = nome;
}

string Paciente::getNome() {
    return nome;
}

void Paciente::setNome(string nome) {
    this->nome = nome;
}