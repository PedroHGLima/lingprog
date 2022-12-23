#include "paciente.h"

Paciente::Paciente() {
    nome = "";
}

Paciente::Paciente(string nome) {
    this->nome = nome;
}

Paciente::Paciente(const Paciente& p) {
    nome = p.nome;
}

string Paciente::getNome() {
    return nome;
}

void Paciente::setNome(string nome) {
    this->nome = nome;
}

bool Paciente::operator<(Paciente p) {
    return nome < p.nome;
}

bool Paciente::operator>(Paciente p) {
    return nome > p.nome;
}

bool Paciente::operator==(Paciente p) {
    return nome == p.nome;
}

bool Paciente::operator!=(Paciente p) {
    return nome != p.nome;
}

ostream& operator<<(ostream& os, const Paciente& p) {
    os << p.nome;
    return os;
}

template <>
Arvore<Paciente*> Arvore<Paciente*>::operator+(Paciente *valor) {
    Arvore<Paciente*> *arv = new Arvore<Paciente*>(*(this));
    if (arv == NULL) {
        arv = new Arvore<Paciente*>(valor);
    } else if (*valor != *(arv->valor)) {
        if (valor->getNome() < arv->valor->getNome()) {
            if (arv->esquerda == NULL) {
                arv->esquerda = new Arvore<Paciente*>(valor);
            } else {
                *(arv->esquerda) = *(arv->esquerda) + valor;
            }
        } else {
            if (arv->direita == NULL) {
                arv->direita = new Arvore<Paciente*>(valor);
            } else {
                *(arv->direita) = *(arv->direita) + valor;
            }
        }
    }
    else {
        cout << "Paciente já cadastrado" << endl;
    }
    return *arv;
}
