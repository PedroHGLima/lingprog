#include "cadastro.h"
#include <stdexcept>

class PacienteNaoEncontradoException : public runtime_error {
	public:
		PacienteNaoEncontradoException (string n) : runtime_error("O paciente " + n + " nao foi encontrado"){}
};


void carregarPacientes(Cadastro &c) {
    c = c + new Paciente("Joao");
    c = c + new Paciente("Maria");
    c = c + new Paciente("Ana");
    c = c + new Paciente("Pedro");
    c = c + new Paciente("Jose");
    c = c + new Paciente("Paulo");
    c = c + new Paciente("Joana");
}

void inserirPaciente(Cadastro &c) {
    string nome;
    cout << "Digite o nome do paciente: "; cin >> nome;
    c = c + new Paciente(nome);
}

void buscarPaciente(Cadastro &c) {
    string nome;
    cout << "Digite o nome do paciente: "; cin >> nome;
    Paciente *p = c[nome];
    if (p == NULL) {
        throw PacienteNaoEncontradoException(nome);
    } else {
        cout << "Paciente encontrado: " << *p << endl;
    }
}

void imprimirPaciente(Cadastro &c) {
    cout << c;
}

void menu(Cadastro &c) {
    int comando = 9;
    while (true){
        switch (comando){
        case 1:
            inserirPaciente(c);
            break;
        case 2:
            try{
                buscarPaciente(c);
            }
            catch(PacienteNaoEncontradoException& e){
                cout << e.what() << endl;
            }
            break;
        case 3:
            imprimirPaciente(c);
            break;
        case 8:
            carregarPacientes(c);
            break;
        case 9:
            cout << "1 - Inserir paciente" << endl;
            cout << "2 - Buscar paciente" << endl;
            cout << "3 - Imprimir cadastro" << endl;
            cout << "8 - Carregar pacientes" << endl;
            cout << "9 - Imprimir menu" << endl;
            cout << "0 - Sair" << endl;
            break;
        case 0:
            cout << "Saindo..." << endl;
            return;
        default:
            cout << "Comando invalido" << endl;
            break;
        }
        cout << "\nDigite o comando: "; cin >> comando;
    }   
}


int main() {
    Cadastro c;

    menu(c);

    return 0;
}
