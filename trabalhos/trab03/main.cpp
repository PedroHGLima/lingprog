#include "catalogo.h"

int main() {
    vector<filme> fs;
    filme f;
    Catalogo c;
    f.nome = "O Poderoso Chefão";
    f.produtora = "Paramount Pictures";
    f.nota = 9.2;
    c += f;

    f.nome = "Clube da Luta";
    f.produtora = "20th Century Fox";
    f.nota = 8.8;
    c += f;

    f.nome = "O Senhor dos Anéis: A Sociedade do Anel";
    f.produtora = "New Line Cinema";
    f.nota = 8.8;
    c += f;

    f.nome = "O Senhor dos Anéis: As Duas Torres";
    f.produtora = "New Line Cinema";
    f.nota = 8.7;
    c += f;

    f.nome = "O Senhor dos Anéis: O Retorno do Rei";
    f.produtora = "New Line Cinema";
    f.nota = 8.9;
    fs.push_back(f);

    f.nome = "Pulp Fiction";
    f.produtora = "Miramax";
    f.nota = 8.9;
    fs.push_back(f);

    f.nome = "Coringa";
    f.produtora = "Warner Bros.";
    f.nota = 8.5;
    fs.push_back(f);

    c += fs;

    c.fodase();
    cout << c;

    c -=  f;
    c.fodase();
    cout << c;
    return 0;
}
