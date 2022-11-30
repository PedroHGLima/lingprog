#include "catalogo.h"


ostream &operator<<(ostream &os, const filme &f) {
    os << "Nome: " << f.nome << endl;
    os << "Produtora: " << f.produtora << endl;
    os << "Nota: " << f.nota << endl;
    return os;
}

ostream &operator<<(ostream &os, const Catalogo &c) {
    for (size_t i = 0; i < c.filmes.size(); i++) {
        os << "---------------------" << i << "---------------------" << endl;
        os << c.filmes.at(i);
    }
    return os;
}

istream &operator>>(istream &is, filme &f) {
    string nome, produtora, nota;
    float c_nota;
    cin.ignore();
   // getline(is, nome);
    getline(is, nome);
    getline(is, produtora);
    getline(is, nota);
    c_nota = stof(nota);
    f.nome = nome;
    f.produtora = produtora;
    f.nota = c_nota;
    return is;
}

istream &operator>>(istream &is, Catalogo &c) {
    string nome, produtora, nota;
    float c_nota;
    filme f;
    cin.ignore();
    while (getline(is, nome)) {
        getline(is, nome);
        getline(is, produtora);
        getline(is, nota);
        c_nota = stof(nota.substr(6, nota.size()));
        f.nome = nome.substr(6, nome.size());
        f.produtora = produtora.substr(11, produtora.size());
        f.nota = c_nota;
        c += f;
    }
    return is;
}

int Catalogo::operator+=(filme &f) {
    int i = 0;
    if (filmes.size() == 0) {
        filmes.push_back(f);
    }
    else {
        if (filmes.size() < qtdFilmes) {
            for (i = 0; i < (int)filmes.size(); i++) {
                if (filmes.at(i) > f) {
                    filmes.insert(filmes.begin() + i, f);
                    return i;
                }
                if (filmes.at(i) == f) {
                    cout << "Filme já existe no catálogo!" << endl;
                    return -1;
                }
            }
            filmes.push_back(f);
        } else {
            cout << "O catálogo está cheio!" << endl;
            return -1;
        }
    }
    return i;
}

int Catalogo::operator+=(vector<filme> &f) {
    size_t i;
    for (i = 0; i < f.size(); i++) {
        *this += f[i];
    }
    return (int)i;
}

int Catalogo::operator-=(filme &f) {
    for (size_t i = 0; i < filmes.size(); i++) {
        if (filmes.at(i) == f) {
            filmes.erase(filmes.begin() + i);
            return (int)i;        }
    }
    return -1; // aqui o filme não foi encontrado
}

int Catalogo::operator()(string nome) {
    for (size_t i = 0; i < filmes.size(); i++) {
        if (filmes.at(i).nome == nome) {
            return i;
        }
    }
    return -1; // aqui o filme não foi encontrado
}

filme& Catalogo::operator()(int indice) {
    if (indice > (int)filmes.size() || indice == -1) {
        cout << "O filme não existe" << endl;
        if (filmes.size() == 0) {
            // se o catálogo estiver vazio, adiciona um filme vazio
            filme f;
            filmes.push_back(f);
        }
        return filmes.at(0);
    }
    else {
        return filmes.at(indice);
    }
}

int Catalogo::operator() (string nome, string att, string novo) {
    for (size_t i = 0; i < filmes.size(); i++) {
        if (filmes.at(i).nome == nome) {
            if (att == "nome") {
                filmes.at(i).nome = novo;
                return (int)i;
            }
            else if (att == "produtora") {
                filmes.at(i).produtora = novo;
                return (int)i;
            }
        }
    }
    return -1; // aqui o filme não foi encontrado
}

int Catalogo::operator() (string nome, string att, float novo) {
    for (size_t i = 0; i < filmes.size(); i++) {
        if (filmes.at(i).nome == nome) {
                if (att == "nota") {
                    if (novo >= 0 && novo <= 10) {
                        filmes.at(i).nota = novo;
                        return (int)i;
                    }
                    else {
                        cout << "Nota inválida!" << endl;
                        return -1;
                    }
            }
        }
    }
    return -1; // aqui o filme não foi encontrado
}

bool filme::operator<(float n) {
    if (nota < n)
        return true;
    else
        return false;
}

bool filme::operator>(float n) {
    if (nota > n)
        return true;
    else
        return false;
}

int filme::operator>(filme &f) {
    return nome > f.nome;
}

int filme::operator<(filme &f) {
    return nome < f.nome;
}

bool filme::operator==(filme &f) {
    if (nome == f.nome)
        return true;
    else
        return false;
}

int Catalogo::melhor_avaliado() {
    float maior = 0;
    int indice = -1;
    for (size_t i = 0; i < filmes.size(); i++) {
        if (filmes.at(i) > maior) {
            maior = filmes.at(i).nota;
            indice = (int)i;
        }
    }
    return indice;
}

bool Catalogo::ta_vazio() {
    if (filmes.size() == 0)
        return true;
    else
        return false;
}
