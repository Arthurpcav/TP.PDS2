#include <iostream>

#include "indice.h"
#include "normalizador.h"

using std::cout, std::endl, std::cin;

int main(){
    IndiceInvertido indiceMain;
    vector<string> documentosRelevantes;
    string busca, nomePasta = "documents";
    indiceMain.percorrerPasta(nomePasta);
    
    cout << "Digite a busca:" << endl;
    getline(cin,busca);

    documentosRelevantes = indiceMain.buscadorIndice(busca);

    for (const auto& it : documentosRelevantes){
       cout << it << endl;
    }

    return 0; 
}