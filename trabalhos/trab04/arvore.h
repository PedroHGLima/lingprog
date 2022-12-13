#pragma once

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Arvore {
    public:
        Arvore();
        Arvore(T valor);
        ~Arvore();
        Arvore operator+(T val);
        void inserir(T valor);
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
Arvore<T> Arvore<T>::operator+(T val) {
    Arvore<T> a;
    a.inserir(val);
    return a;
}

template <class T>
void Arvore<T>::inserir(T valor) {
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

template <class T>
T* Arvore<T>::operator[](T valor) {
    return busca(valor);
}

template <class T>
T* Arvore<T>::busca(T valor) {
    if (valor == this->valor) {
        return &(this->valor);
    } else if (valor < this->valor) {
        if (this->esquerda == NULL) {
            return NULL;
        } else {
            return this->esquerda->busca(valor);
        }
    } else {
        if (this->direita == NULL) {
            return NULL;
        } else {
            return this->direita->busca(valor);
        }
    }
}

template <class T>
void Arvore<T>::imprime() {
    if (this->esquerda != NULL) {
        this->esquerda->imprime();
    }
    cout << this->valor << endl;
    if (this->direita != NULL) {
        this->direita->imprime();
    }
}
