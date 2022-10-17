#pragma once

using namespace std;

class Vertice {
    public:
        Vertice(char id);
        char getId();
        void setId(int id);
    private:
        char id;
};