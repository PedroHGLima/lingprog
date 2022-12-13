#include "cadastro.h"

Cadastro::Cadastro() {
    cout << "Construindo cadastro" << endl;
    arvore = NULL;
}

void Cadastro::insere(Paciente *p) {
    insere(p, arvore);
}

void Cadastro::insere(Paciente *p, Arvore<Paciente> *arv) {
    if (arv == NULL) {
        arvore = new Arvore<Paciente>(*p);
    } else {
        Arvore<Paciente> aux = (*arv) + (*p);
        arv = &aux;
    }
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
