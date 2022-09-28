#include "ponto.h"
#include <cmath>

class Linha {
    public:
    Linha(Ponto pa, Ponto pb);
    void setP1(Ponto p);
    void setP2(Ponto p);
    double getComprimento();

    private:
    Ponto p1, p2;
};
