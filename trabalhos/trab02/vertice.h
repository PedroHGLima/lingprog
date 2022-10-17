#pragma once

using namespace std;

class Vertice {
    public:
        Vertice (int id);
        int get_id ();
        void set_id (int id);
    private:
        int id;
};
