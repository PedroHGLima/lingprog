#pragma once

#include <vector>

using namespace std;

class Vertice {
    public:
        Vertice ();
        Vertice (int id);
        int get_id ();
        void set_id (int id);
    private:
        int id;
};
