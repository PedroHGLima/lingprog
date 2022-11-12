#include "forca.h"

int main(){
	Forca jogo;
	jogo.configure();
	cout << jogo.getPalavra() << endl;
	jogo.teste();
	return 0;
}
