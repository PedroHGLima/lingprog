#include "cadastro.h"
#include "phospitalar.h"
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

void carregarPacientesHospitalares(Cadastro &c) {
    c = c + new PacienteHospitalar("Ravi", "Gripe", 5);
    c = c + new PacienteHospitalar("Gabriel" , "Dengue", 3);
    c = c + new PacienteHospitalar("Maya" , "Covid", 2);
    c = c + new PacienteHospitalar("Guilherme" , "Constusao", 1);
    c = c + new PacienteHospitalar("Samuel" , "Gripe", 4);
    c = c + new PacienteHospitalar("Lucas" , "Calculo renal", 6);
    c = c + new PacienteHospitalar("Alice" , "Recuperacao", 7);
}

void carregarPacientesClinicos(Cadastro &c) {
    c = c + new PacienteClinico("Mariana", "Corisa", 700);
    c = c + new PacienteClinico("Lara" , "Dor de cabeca", 800);
    c = c + new PacienteClinico("Miguel" , "Tontura", 1130);
    c = c + new PacienteClinico("Benjamin" , "Coceira", 2000);
    c = c + new PacienteClinico("Laura" , "Perda de oufato", 930);
    c = c + new PacienteClinico("Matheus" , "Labirintite", 1300);
    c = c + new PacienteClinico("Cecilia" , "Otite", 1750);
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
            cout << c;
            break;
        case 8:{
            int tipo;
            cout << "1 - Pacientes" << endl;
            cout << "2 - Pacientes Hospitalares" << endl;
            cout << "3 - Pacientes Clinicos" << endl;
            cout << "Digite o tipo de paciente: "; cin >> tipo;
            switch (tipo){
                case 1:
                    carregarPacientes(c);
                    break;
                case 2:
                    carregarPacientesHospitalares(c);
                    break;
                case 3:
                    carregarPacientesClinicos(c);
                    break;
                default:
                    cout << "Tipo invalido" << endl;
                    break;
            }   
            break;
        }
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
