#ifndef INDICE_H
#define INDICE_H

#include <iostream>
#include <vector>
#include <map>

using std::string, std::map, std::vector;

class IndiceInvertido {
private:
    map<string, map <string, int>> indice;

public:
    void construtorIndice(string pasta);
    vector<string> buscadorIndice(string busca);
    map<string, map <string, int>> getIndice();
};

#endif