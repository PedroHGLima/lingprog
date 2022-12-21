#include "cadastro.h"

Cadastro::Cadastro() {
    arvore = NULL;
}

void Cadastro::insere(PacienteHospitalar *p) {
    insere(p, arvore);
}

void Cadastro::insere(PacienteHospitalar *p, Arvore<PacienteHospitalar*> *arv) {
    /// @brief Insere um paciente na árvore
    /// @param p PacienteHospitalar a ser inserido
    /// @param arv Árvore onde o paciente será inserido
    if (arvore == NULL) {
        arvore = new Arvore<PacienteHospitalar*> (p);
    } else {
        if (*p < *(arv->valor)) {
            if (arv->esquerda == NULL) {
                arv->esquerda = new Arvore<PacienteHospitalar*> (p);
            } else {
                insere(p, arv->esquerda);
            }
        } else if (*p > *(arv->valor)) {
            if (arv->direita == NULL) {
                arv->direita = new Arvore<PacienteHospitalar*> (p);
            } else {
                insere(p, arv->direita);
            }
        } else {
            cout << "Paciente ja cadastrado" << endl;
        }
    }
}

Cadastro Cadastro::operator+(PacienteHospitalar *p) {
    insere(p);
    return *this;
}

PacienteHospitalar* Cadastro::busca(string nome) {
    return busca(nome, arvore);
}

PacienteHospitalar* Cadastro::operator[](string nome) {
    return busca(nome);
}

PacienteHospitalar* Cadastro::busca(string nome, Arvore<PacienteHospitalar*> *arv) {
    /// @brief Busca um paciente na árvore
    /// @param nome Nome do paciente a ser buscado
    /// @param arv Árvore onde o paciente será buscado
    /// @return PacienteHospitalar encontrado
    if (arv == NULL) {
        cout << "Nenhum paciente cadastrado" << endl;
        return NULL;
    } else {
        if (*(arv->valor) == nome) {
            return arv->valor;
        } else if (*(arv->valor) > nome) {
            if (arv->esquerda == NULL) {
                return NULL;
            } else {
                return busca(nome, arv->esquerda);
            }
        } else {
            if (arv->direita == NULL) {
                return NULL;
            } else {
                return busca(nome, arv->direita);
            }
        }
    }
}

void Cadastro::imprime() {
    imprime(arvore);
}

void Cadastro::imprime(Arvore<PacienteHospitalar*> *arvore) {
    /// @brief Impressão da árvore em ordem infixa
    /// @param arvore arvore a ser impressa
    if (arvore == NULL) {
        cout << "Nenhum paciente cadastrado" << endl;
        return;
    } else {
        if (arvore->esquerda != NULL)
            imprime(arvore->esquerda);
        cout << "Paciente: " << *(arvore->valor) << endl;
        if (arvore->direita != NULL) {
            imprime(arvore->direita);
        }
    }

}

ostream& operator<<(ostream& os, Cadastro& c) {
    c.imprime();
    return os;
}
