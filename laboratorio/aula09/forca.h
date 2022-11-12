#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>	

using namespace std;

class Forca {
    public:
	Forca();
	void configure();
	bool teste();
	string getPalavra();
    private:
	int maxRodadas;
	string palavra, dica;
	vector<bool> encontradas;
};
