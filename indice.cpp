#include "indice.h"
#include "normalizador.h"
#include<fstream>
#include<sstream>
#include<filesystem>

void IndiceInvertido::percorrerArquivo(string nomeArquivo, map<string, map<string, int>>& x){
    std::ifstream arq(nomeArquivo); 
    string linha; 
    string palavra; 

    while(std::getline(arq, linha)){
        std::istringstream iss(linha); 
        while(iss >> palavra){
            x[normalizador(palavra)][nomeArquivo]++; 
        }
    }

    arq.close(); 
}

void IndiceInvertido::percorrerPasta(string nomePasta, map<string, map<string, int>>& x){
    vector<string> nomesArquivos; 
    for(auto it : std::filesystem::directory_iterator(nomePasta)){
        if(it.is_regular_file()){
            nomesArquivos.push_back(it.path().string());
        }
    } 
    for(string y : nomesArquivos){
        percorrerArquivo(y, x); 
    }
}

/*vector<string> IndiceInvertido::buscadorIndice(string busca){
    string palavra;
    string palavraNormalizada;
    vector<string> documentosRelevantes;
    while(busca >> palavra){
        palavraNormalizada = normalizador(palavra);
        if(!palavraNormalizada.empty()){
            if(getIndice().find(palavraNormalizada) != getIndice().end()){
                while(map<string, int> interador : getIndice()[palavraNormalizada]){
                    
                }
            }
        }
    }
}
*/
map<string, map <string, int>> IndiceInvertido::getIndice(){
    return this->indice;
}