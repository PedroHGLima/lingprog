#include "estadual.h"

#define ESTADOS 7

class Nacional {
    public:
        Nacional();
        void gerarEstados();
    private:
        std::vector<Estadual> estados;
};
