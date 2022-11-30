#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define MAX 10

using namespace std; 

struct filme {
    string nome;
    string produtora;
    float nota;

    friend ostream &operator<<(ostream &os, const filme &f);
    friend istream &operator>>(istream &is, filme &f);
    bool operator<(float n);
    bool operator>(float n);
    int operator>(filme &f);
    int operator<(filme &f);
    bool operator==(filme &f);
};

class Catalogo {
    friend ostream &operator<<(ostream &os, const filme &f);
    friend ostream &operator<<(ostream &os, const Catalogo &c);
    friend istream &operator>>(istream &is, Catalogo &c);
    public:
        int operator+=(filme &f);
        int operator+=(vector<filme> &f);
        int operator-=(filme &f);
        int operator()(string nome);
        filme& operator()(int indice);
        int operator()(string nome, string att, string novo);
        int operator()(string nome, string att, float novo);
        int melhor_avaliado();
        bool ta_vazio();
    private:
        unsigned int const qtdFilmes = MAX;
        vector<filme> filmes;
};
