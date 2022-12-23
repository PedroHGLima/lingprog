#include "cadastro.h"

Cadastro::Cadastro() {
    arvore = NULL;
}

void Cadastro::insere(Paciente *p) {
    //insere(p, arvore);
    if (arvore == NULL)
        arvore = new Arvore<Paciente*> (p);
    else
        *arvore = *arvore + p;
}

void Cadastro::insere(Paciente *p, Arvore<Paciente*> *arv) {
    /// @brief Insere um paciente na árvore
    /// @param p Paciente a ser inserido
    /// @param arv Árvore onde o paciente será inserido
    if (arvore == NULL) {
        arvore = new Arvore<Paciente*> (p);
    } else if ((*p) != (*(arv->valor))) {
        if (*p < *(arv->valor)) {
            if (arv->esquerda == NULL) {
                arv->esquerda = new Arvore<Paciente*> (p);
            } else {
                insere(p, arv->esquerda);
            }
        } else if (*p > *(arv->valor)) {
            if (arv->direita == NULL) {
                arv->direita = new Arvore<Paciente*> (p);
            } else {
                insere(p, arv->direita);
            }
        }
    }
    else {
        cout << "Paciente já cadastrado" << endl;
    }
}

Cadastro Cadastro::operator+(Paciente *p) {
    Arvore <Paciente*> *arv = arvore;
    if (arv == NULL)
        arv = new Arvore<Paciente*> (p);
    else
        *arv = *arvore + p;

    Cadastro c;
    c.arvore = arv;
    return c;
}

Paciente* Cadastro::busca(string nome) {
    return busca(nome, arvore);
}

Paciente* Cadastro::operator[](string nome) {
    return busca(nome);
}

Paciente* Cadastro::busca(string nome, Arvore<Paciente*> *arv) {
    /// @brief Busca um paciente na árvore
    /// @param nome Nome do paciente a ser buscado
    /// @param arv Árvore onde o paciente será buscado
    /// @return Paciente encontrado
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

void Cadastro::imprime(Arvore<Paciente*> *arvore) {
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
