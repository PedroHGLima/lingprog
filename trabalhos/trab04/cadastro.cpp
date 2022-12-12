#include "cadastro.h"

Cadastro::Cadastro() {
    cout << "Construindo cadastro" << endl;
    arvore = NULL;
}

void Cadastro::inserir(Paciente *p) {
    inserir(p, arvore);
}

void Cadastro::inserir(Paciente *p, Arvore<Paciente> *arv) {
    if (arv == NULL) {
        arvore = new Arvore<Paciente>(*p);
    } else {
        if (p->getNome() < arv->valor.getNome()) {
            if (arv->esquerda == NULL) {
                arv->esquerda = new Arvore<Paciente>(*p);
            } else {
                inserir(p, arv->esquerda);
            }
        } else {
            if (arv->direita == NULL) {
                arv->direita = new Arvore<Paciente>(*p);
            } else {
                inserir(p, arv->direita);
            }
        }
    }
}

void Cadastro::imprime() {
    imprime(arvore);
}

void Cadastro::imprime(Arvore<Paciente> *arvore) {
    /// @brief Impressão da árvore em ordem infixa
    /// @param arvore arvore a ser impressa
    if (arvore == NULL) {
        cout << "Arvore vazia" << endl;
        return;
    } else {
        if (arvore->esquerda != NULL)
            imprime(arvore->esquerda);
        cout << "Paciente: " << arvore->valor.getNome() << endl;
        if (arvore->direita != NULL)
            imprime(arvore->direita);
    }

}
