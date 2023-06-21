#ifndef INDICE_H
#define INDICE_H

#include <iostream>
#include <vector>
#include <map>

using std::string, std::map, std::vector;

struct BuscaNaoEncontrada{

}; 

class IndiceInvertido {
private:
    map<string, map <string, int>> indice;

public:

    void percorrerArquivo(string nomeArquivo);
    void percorrerPasta(string nomePasta); 
    vector<string> buscadorIndice(string busca);
    map<string, map <string, int>> getIndice();
};

#endif