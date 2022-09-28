#include "estadual.h"

#define ESTADOS 7

class Nacional {
    public:
        Nacional(int nEstados = ESTADOS);
        void gerarEstados(int nEstados);
        void avaliarEstabilidade();
    private:
        std::vector<Estadual> estados;
};
