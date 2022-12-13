#include "cadastro.h"

int main() {
    Cadastro c;
    c.imprime();
    c.insere(new Paciente("Joao"));
    c.insere(new Paciente("Maria"));
    c.insere(new Paciente("Jose"));
    c.insere(new Paciente("Ana"));
    c.insere(new Paciente("Pedro"));
    c.insere(new Paciente("Paulo"));
    c.imprime();

    int x = 5;
    Arvore<int> *a = new Arvore<int>(x);
    x=0b11;
    cout << "vamo ver: " << x << endl;
    Arvore<int> nova = (*a)+3;
    a = &nova;
    a->imprime();

    Paciente *p;
    p=c.busca("Joao");
    cout << "Paciente: " << p->getNome() << endl;

    return 0;
}
