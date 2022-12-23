#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Arvore {
    public:
        Arvore();
        Arvore(T valor);
        Arvore(const Arvore<T> &arv);
        ~Arvore();
        void inserir(T valor);
        Arvore<T> operator+(T valor);
        Arvore<T> operator=(Arvore<T> arv);
        T *operator[](T valor);
        T *busca (T valor);
        void imprime();
        T valor;
        Arvore<T> *esquerda;
        Arvore<T> *direita;
};

template <class T>
Arvore<T>::Arvore() {
    esquerda = NULL;
    direita = NULL;
}

template <class T>
Arvore<T>::Arvore(T valor) {
    this->valor = valor;
    esquerda = NULL;
    direita = NULL;
}

template <class T>
Arvore<T>::~Arvore() {
    if (esquerda != NULL) {
        delete esquerda;
    }
    if (direita != NULL) {
        delete direita;
    }
}

template <class T>
Arvore<T>::Arvore(const Arvore<T> &arv) {
    this->valor = arv.valor;
    if (arv.esquerda != NULL) {
        this->esquerda = new Arvore<T>(*(arv.esquerda));
    } else {
        this->esquerda = NULL;
    }
    if (arv.direita != NULL) {
        this->direita = new Arvore<T>(*(arv.direita));
    } else {
        this->direita = NULL;
    }
}

template <class T>
void Arvore<T>::inserir(T valor) {
    if (valor == this->valor) {
        cout << "Valor já existe na árvore" << endl;
        return;
    } else {
        if (valor < this->valor) {
            if (this->esquerda == NULL) {
                this->esquerda = new Arvore<T>(valor);
            } else {
                this->esquerda->inserir(valor);
            }
        } else {
            if (this->direita == NULL) {
                this->direita = new Arvore<T>(valor);
            } else {
                this->direita->inserir(valor);
            }
        }
    }
}

template <class T>
Arvore<T> Arvore<T>::operator+(T valor) {
    Arvore<T> *arv = new Arvore<T>(*(this));
    arv->inserir(valor);
    return *arv;
}

template <class T>
Arvore<T> Arvore<T>::operator=(Arvore<T> arv) {
    this->valor = arv.valor;
    if (arv.esquerda != NULL) {
        this->esquerda = new Arvore<T>(*(arv.esquerda));
    } else {
        this->esquerda = NULL;
    }
    if (arv.direita != NULL) {
        this->direita = new Arvore<T>(*(arv.direita));
    } else {
        this->direita = NULL;
    }
    return *this;
}

template <class T>
void Arvore<T>::imprime() {
    cout << "imprime:" << endl;
    if (this->esquerda != NULL) {
        this->esquerda->imprime();
    }
    cout << this->valor << endl;
    if (this->direita != NULL) {
        cout << "direita:" << endl;
        this->direita->imprime();
    }
}
