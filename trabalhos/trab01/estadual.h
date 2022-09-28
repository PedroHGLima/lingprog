#include <iostream>
#include <vector>
#include <string>

#define MESES       7
#define CANDIDATOS  2

class Estadual {
    public:
        Estadual();
        void gerarDados(unsigned int);
        double mediaMovel(int numMeses, unsigned int candidato);
        double avaliarEstabilidade(unsigned int candidato);
        std::vector<int> getVotos(unsigned int candidato);
        std::string getSigla();

    private:
        std::vector<std::vector<int>> votos;
        std::string sigla;
};
