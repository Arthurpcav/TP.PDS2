#include "indice.h"
#include "normalizador.h"

void IndiceInvertido::construtorIndice(string pasta){

}

vector<string> IndiceInvertido::buscadorIndice(string busca){
    string palavra;
    string palavraNormalizada;
    vector<string> documentosRelevantes;
    while(busca >> palavra){
        palavraNormalizada = normalizador(palavra);
        if(!palavraNormalizada.empty){
            if(getIndice().find(palavraNormalizada) != getIndice.end()){
                while(map<string, int> interador : getIndice()[palavraNormalizada]){
                    
                }
            }
        }
    }
}

map<string, map <string, int>> IndiceInvertido::getIndice(){
    return this->indice;
}