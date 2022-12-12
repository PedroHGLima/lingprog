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
        Arvore operator+(T valor);
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
Arvore<T> Arvore<T>::operator+(T valor) {
    if (valor < this->valor) {
        if (esquerda == NULL) {
            esquerda = new Arvore<T>(valor);
        } else {
            *esquerda + valor;
        }
    } else {
        if (direita == NULL) {
            direita = new Arvore<T>(valor);
        } else {
            *direita + valor;
        }
    }
    return *this;
}
