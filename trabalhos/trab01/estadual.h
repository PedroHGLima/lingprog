#include <iostream>
#include <vector>

#define MESES 7

class Estadual {
    public:
        Estadual(unsigned int candidatos = 2);
        void gerarDados(unsigned int);
        double mediaMovel(int numMeses, unsigned int candidato);
        double avaliarEstabilidade(unsigned int candidato);
        std::vector<int> getVotos(unsigned int candidato);
        char* getSigla();

    private:
        std::vector<std::vector<int>> votos;
        char sigla[3];
};
