#include "forca.h"

vector<string> split(string s, char sep=',') {
	vector<string>r;
	int pos;
	pos = s.find(sep);
	r.push_back(s.substr(0,pos));
	r.push_back(s.substr(pos+2,s.size()));
	return r;
}

Forca::Forca(){
	maxRodadas=6;
	srand(time(NULL));
}

void Forca::configure(){
	// Escolhe a palavra que deve ser usada na forca
	ifstream file ("palavras.txt");
	string linha;
	vector<string> linhas;
	
	if (file.is_open()){
		while (getline(file, linha)){
			linhas.push_back(linha);
		}
	}

	int randomIndex = rand() % linhas.size();
	palavra = split(linhas.at(randomIndex)).at(0);
	dica    = split(linhas.at(randomIndex)).at(1);
	encontradas.resize(palavra.size());
}

bool Forca::teste(){
	char caractere;
	cout << "Insira um caractere: "; cin >> caractere;
	if (palavra.find(caractere)!=string::npos){
		while (palavra.find(caractere)!=string::npos){
			cout << palavra.find(caractere) << endl;
			encontradas.at(palavra.find(caractere)) = true;
			palavra.at(palavra.find(caractere))='0'; //valor invalido significa que ja foi encontrado
		}
		return true;
	}
	else return false;
}

string Forca::getPalavra(){return palavra;}
