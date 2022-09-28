#include <iostream>
#include <string>

#include "agenda.h"

using namespace std;

void Agenda::setNames() {
    string buffer;
    for (int i = 0; i < 3; i++) {
        cout << "Digite o nome " << i + 1 << ": ";
        cin >> buffer;
        if (buffer.length() > 10) {
            cout << "Nome muito grande, truncando..." << endl;
            nomes[i] = buffer.substr(0, 10);
        } else {
            nomes[i] = buffer;
        }
    }
}

void Agenda::getNames() {
    for (int i = 0; i < 3; i++) {
        cout << "Nome " << i + 1 << ": " << nomes[i] << endl;
    }
}
