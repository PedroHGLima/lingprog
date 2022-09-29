#include "estadual.h"

#define ESTADOS 7

class Nacional {
    public:
        Nacional(int nEstados = ESTADOS);
        void gerarEstados(int nEstados);
        double avaliarEstabilidade(unsigned int candidato);
        Estadual encontrarAlta(unsigned int candidato);
        int calcularVantagem();
        Estadual getEstado(int i);
    private:
        std::vector<Estadual> estados;
};
