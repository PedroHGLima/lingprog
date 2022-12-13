#include "cadastro.h"

Cadastro::Cadastro() {
    arvore = NULL;
}

void Cadastro::insere(Paciente *p) {
    insere(p, arvore);
}

void Cadastro::insere(Paciente *p, Arvore<Paciente> *arv) {
    /// @brief Insere um paciente na árvore
    /// @param p Paciente a ser inserido
    /// @param arv Árvore onde o paciente será inserido
    if (arvore == NULL) {
        arvore = new Arvore<Paciente> (*p);
    } else {
        if (*p < arv->valor) {
            if (arv->esquerda == NULL) {
                arv->esquerda = new Arvore<Paciente> (*p);
            } else {
                insere(p, arv->esquerda);
            }
        } else if (*p > arv->valor) {
            if (arv->direita == NULL) {
                arv->direita = new Arvore<Paciente> (*p);
            } else {
                insere(p, arv->direita);
            }
        } else {
            cout << "Paciente ja cadastrado" << endl;
        }
    }
}

Cadastro Cadastro::operator+(Paciente *p) {
    insere(p);
    return *this;
}

Paciente* Cadastro::busca(string nome) {
    Paciente *p = new Paciente(nome);
    Paciente *ret = NULL;
    ret = arvore->busca(*p);
    return ret;
}

void Cadastro::imprime() {
    imprime(arvore);
}

void Cadastro::imprime(Arvore<Paciente> *arvore) {
    /// @brief Impressão da árvore em ordem infixa
    /// @param arvore arvore a ser impressa
    if (arvore == NULL) {
        cout << "Nenhum paciente cadastrado" << endl;
        return;
    } else {
        if (arvore->esquerda != NULL)
            imprime(arvore->esquerda);
        cout << "Paciente: " << arvore->valor << endl;
        if (arvore->direita != NULL) {
            imprime(arvore->direita);
        }
    }

}
