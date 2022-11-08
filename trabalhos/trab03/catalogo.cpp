#include "catalogo.h"

ostream filme::operator<<(ostream &os, const Catalogo &c) {
    os << f.nome << " " << f.produtora << " " << f.nota << endl;
    return os;
}

ostream Catalogo::operator<<(ostream &os, const Catalogo &c) {
    for (size_t i = 0; i < c.filmes.size(); i++) {
        os << c.filmes[i];
    }
    return os;
}

istream Catalogo::operator>>(istream &is, const filme &f) {
    is >> f.nome >> f.produtora >> f.nota;
    return is;
}

Catalogo Catalogo::operator+=(const filme &f) {
    int nFilmes = (int) filmes.size();
    if (filmes.size() < qtdFilmes) {
        for (size_t i = 0; i < filmes.size(); i++) {
            if (f.compare(filmes[i]) < 0) {
                filmes.insert(filmes.begin() + i, f);
                break;
            }
        }
    }
    return *this;
}
