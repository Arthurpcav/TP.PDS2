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
    try{
        getline(cin,busca);

        documentosRelevantes = indiceMain.buscadorIndice(busca);
    }catch(BuscaNaoEncontrada e){
        cout << "Não foi encontrado nenhum arquivo correspondente a essa busca." << endl;
    }
    
    for (const auto& it : documentosRelevantes){
       cout << it << endl;
    }

    return 0; 
}