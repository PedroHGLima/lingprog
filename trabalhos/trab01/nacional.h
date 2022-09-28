#include "estadual.h"

#define ESTADOS 7

class Nacional {
    public:
        Nacional(int nEstados = ESTADOS);
        void gerarEstados(int nEstados);
        void avaliarEstabilidade();
        void avaliarEstabilidadeNacional();
        Estadual getEstado(int i);
    private:
        std::vector<Estadual> estados;
};
