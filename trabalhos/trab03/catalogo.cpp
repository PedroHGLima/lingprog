#include "catalogo.h"

ostream &operator<<(ostream &os, const filme &f) {
    os << "Nome: " << f.nome << endl;
    os << "Produtora: " << f.produtora << endl;
    os << "Nota: " << f.nota << endl;
    return os;
}

ostream &operator<<(ostream &os, const Catalogo &c) {
    for (size_t i = 0; i < c.filmes.size(); i++) {
        os << c.filmes[i];
    }
    return os;
}

istream &operator>>(istream &is, filme &f) {
    cout << "Nome: ";
    getline(is, f.nome);
    cout << "Produtora: ";
    getline(is, f.produtora);
    cout << "Nota: ";
    is >> f.nota;
    return is;
}

Catalogo& operator+=(Catalogo &c, filme &f) {
    if (c.filmes.size() == 0) {
        c.filmes.push_back(f);
    }
    else {
        if (c.filmes.size() < c.qtdFilmes) {
            for (size_t i = 0; i < c.filmes.size(); i++) {
                if (c.filmes.at(i).nome > f.nome) {
                    c.filmes.insert(c.filmes.begin() + i, f);
                    return c;
                }
            }
            c.filmes.push_back(f);
        } else {
            cout << "O catálogo está cheio!" << endl;
        }
    }
    return c;
}

Catalogo& operator+=(Catalogo &c, vector<filme> &f) {
    for (size_t i = 0; i < f.size(); i++) {
        c += f[i];
    }
    return c;
}

Catalogo& operator-=(Catalogo &c, filme &f) {
    for (size_t i = 0; i < c.filmes.size(); i++) {
        if (c.filmes.at(i).nome == f.nome) {
            c.filmes.erase(c.filmes.begin() + i);
            return c;
        }
    }
    return c; // aqui o filme não foi encontrado
}

void Catalogo::fodase() {
    cout << filmes.size() << endl;
}