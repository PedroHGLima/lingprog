#pragma once

#include <iostream>
#include <string>
#include <vector>

#define MAX 10

using namespace std; 

struct filme {
    string nome;
    string produtora;
    double nota;

    friend ostream &operator<<(ostream &os, const filme &f);
    friend istream &operator>>(istream &is, filme &f);
};

class Catalogo {
    public:
        friend ostream &operator<<(ostream &os, const filme &f);
        friend ostream &operator<<(ostream &os, const Catalogo &c);
        friend Catalogo &operator+=(Catalogo &c, filme &f);
        friend Catalogo &operator+=(Catalogo &c, vector<filme> &f);
        friend Catalogo &operator-=(Catalogo &c, filme &f);
    private:
        unsigned int const qtdFilmes = MAX;
        vector<filme> filmes;
};
