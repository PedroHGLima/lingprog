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
};

class Catalogo {
    public:
    /*
        ostream &operator<<(ostream &os, const Catalogo &c);
        ostream &operator<<(ostream &os, const filme &f);
        istream &operator>>(istream &is, const filme &f);
        Catalogo &operator+=(const filme &f);
        */
    private:
        int const qtdFilmes = MAX;
        vector<filme> filmes;
};
