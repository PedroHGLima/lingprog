#include <fstream>

#include "catalogo.h"

void criar_filmes(Catalogo &c){
    filme f;

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
    c += f;

    f.nome = "Pulp Fiction";
    f.produtora = "Miramax";
    f.nota = 8.9;
    c += f;

    f.nome = "Coringa";
    f.produtora = "Warner Bros.";
    f.nota = 8.5;
    c += f;
}

string pegar_nome(){
    string nome;
    cout << "Digite o nome do filme: ";
    cin.clear();
    cin.ignore();
    getline(cin, nome);
    return nome;
}

void ler_arquivo(Catalogo &c, string nome_arquivo){
    ifstream arq;
    arq.open(nome_arquivo);
    if(arq.is_open()){
        arq>>c;
    }
    arq.close();
}

void salvar_arquivo(Catalogo &c, string nome_arquivo){
    ofstream arq;
    cout << "Salvando catálogo em " << nome_arquivo << endl;
    arq.open(nome_arquivo);
    if(arq.is_open()){
        arq << c;
    }
    arq.close();
}

int main() {
    Catalogo c;
    int comando = 9;
    string nome_arquivo = "filmes.txt";

    while (true) {
        switch (comando) {
            case 1:
                cout << c;
                break;
            case 2: {
                string nome = pegar_nome();
                cout << "+" << setfill('-') << setw(50) << "+" << endl;
                cout << c(c(nome));
                cout << "+" << setfill('-') << setw(50) << "+" << endl;
                break;
            }
            case 3: {
                cout << "Digite o nome, produtora e nota do filme: " << endl;
                filme f;
                cin >> f;
                int ind = (c += f);
                if (ind == -1) {
                    cout << "Filme já existe" << endl;
                }
                else {
                    cout << "Filme adicionado com índice " << ind << endl;
                }
                break;
            }
            case 4: {
                string nome = pegar_nome();
                int ind = c(nome);
                if (ind == -1) {
                    cout << "Filme não existe" << endl;
                }
                else {
                    ind = (c -= c(c(nome)));
                    cout << "Filme removido com índice " << ind << endl;
                }
                break;
            }
            case 5: {
                string nome = pegar_nome();
                cout << nome << " tem indice " << c(nome) << " no catálogo" << endl;
                break;
            }
            case 6: {
                float nova;
                bool ficar=true;
                string nome=pegar_nome(), att, novo;
                while (c(nome)==-1) {
                    cout << "Filme não existe, tente novamente: ";
                    getline(cin, nome);
                    cout << nome << endl;
                }
                
                while (ficar) {
                    cout << "Digite o atributo: "; cin >> att;
                    if (att == "nota") {
                        cout << "Digite a nova nota: "; cin >> nova;
                        if (nova<0 || nova>10) {
                            cout << "Nota inválida, tente novamente" << endl;
                        }
                        else {
                            ficar=false;
                            c(nome, att, nova);
                        }
                    }
                    else if (att == "produtora" || att == "nome") {
                        cout << "Digite o novo valor: ";
                        cin.clear();
                        cin.ignore();
                        getline(cin, novo);
                        c(nome, att, novo);
                        ficar = false;
                    }
                    else {
                        cout << "Atributo inválido" << endl;
                    }
                }
                break;
            }
            case 7:
                cout << "O melhor filme é: " << c(c.melhor_avaliado());
                break;
            case 8:
                cout << "Digite f, p ou nome do arquivo: "; cin >> nome_arquivo;
                if (nome_arquivo == "f") {
                    nome_arquivo = "filmes.txt";
                    criar_filmes(c);
                }
                else if (nome_arquivo == "p") {
                    nome_arquivo = "filmes.txt";
                    ler_arquivo(c, nome_arquivo);
                }
                else {
                    ler_arquivo(c, nome_arquivo);
                }
                break;
            case 9:
                // Impressão da ajuda
                cout << "1 - Imprimir o catálogo" << endl;
                cout << "2 - Imprimir um filme" << endl;
                cout << "3 - Adicionar um filme" << endl;
                cout << "4 - Remover um filme" << endl;
                cout << "5 - Busca de um filme" << endl;
                cout << "6 - Alterar um filme" << endl;
                cout << "7 - Encontrar o filme melhor avaliado" << endl;
                cout << "8 - Carregar filmes salvos" << endl;
                cout << "9 - Imprimir a ajuda" << endl;
                cout << "0 - Sair" << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                if (c.ta_vazio()) cout << "Catálogo vazio" << endl;
                else salvar_arquivo(c, nome_arquivo);
                return 0;
                break;
            default:
                cout << "Comando inválido" << endl;
                break;
        }
        cout << endl << "Digite o comando: ";
        cin >> comando;
    }

    return 0;
}
