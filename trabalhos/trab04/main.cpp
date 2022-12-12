#include "cadastro.h"

int main() {
    Cadastro c;
    c.imprime();
    c.inserir(new Paciente("Joao"));
    c.inserir(new Paciente("Maria"));
    c.inserir(new Paciente("Jose"));
    c.inserir(new Paciente("Ana"));
    c.inserir(new Paciente("Pedro"));
    c.inserir(new Paciente("Paulo"));
    c.imprime();

    int x = 5;
    Arvore<int> a(5);
    x=3;
    a = a+x;

    cout << a.esquerda->valor << endl;

    return 0;
}
