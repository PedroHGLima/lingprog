#include "estadual.h"

#define ESTADOS 7

class Nacional {
    public:
        Nacional(int nEstados = ESTADOS);
        double mediaMovel(unsigned int candidato, int mes=0);
        void gerarEstados(int nEstados);
        double avaliarEstabilidade(unsigned int candidato);
        Estadual encontrarAlta(unsigned int candidato);
        Estadual encontrarBaixa(unsigned int candidato);
        int calcularVantagem();
        Estadual getEstado(int i);
    private:
        std::vector<Estadual> estados;
};
