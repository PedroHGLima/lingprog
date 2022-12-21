#include "cadastro.h"
#include "phospitalar.h"
#include <stdexcept>

class PacienteNaoEncontradoException : public runtime_error {
	public:
		PacienteNaoEncontradoException (string n) : runtime_error("O paciente " + n + " nao foi encontrado"){}
};


void carregarPacientes(Cadastro &c) {
    c = c + new PacienteHospitalar("Joao");
    c = c + new PacienteHospitalar("Maria");
    c = c + new PacienteHospitalar("Ana");
    c = c + new PacienteHospitalar("Pedro");
    c = c + new PacienteHospitalar("Jose");
    c = c + new PacienteHospitalar("Paulo");
    c = c + new PacienteHospitalar("Joana");
}

void inserirPaciente(Cadastro &c) {
    string nome, sintoma;
    cout << "Digite o nome do paciente: "; cin >> nome;
    cout << "Digite o sintoma: ";
    cin.ignore();
    getline(cin, sintoma);
    c = c + new PacienteHospitalar(nome, sintoma);
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

void inserirSintoma(Cadastro &c) {
    string nome;
    cout << "Digite o nome do paciente: "; cin >> nome;
    PacienteHospitalar *p = c[nome];
    if (p == NULL) {
        throw PacienteNaoEncontradoException(nome);
    } else {
        string sintoma;
        cout << "Digite o sintoma: ";
        cin.ignore();
        getline(cin, sintoma);
        p->setSintomas(sintoma);
    }
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
        case 4:
            inserirSintoma(c);
            break;
        case 8:
            carregarPacientes(c);
            break;
        case 9:
            cout << "1 - Inserir paciente" << endl;
            cout << "2 - Buscar paciente" << endl;
            cout << "3 - Imprimir cadastro" << endl;
            cout << "4 - Inserir sintoma" << endl;
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
