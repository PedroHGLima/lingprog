#include <iostream>
#include <vector>

#define MESES 7

class Estadual {
    public:
        Estadual();
        void gerarDados();
        double mediaMovel(int numMeses = 3);
        void avaliarEstabilidade();
        std::vector<int> getVotosPorMes();
        char* getSigla();

    private:
        std::vector<int> votosPorMes;
        char sigla[3];
};
