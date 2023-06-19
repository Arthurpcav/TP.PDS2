#include "indice.h"
#include "normalizador.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>

using std::to_string;

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

void IndiceInvertido::percorrerPasta(string nomePasta){
    vector<string> nomesArquivos; 
    for(const auto& it : std::filesystem::directory_iterator(nomePasta)){
        if(it.is_regular_file()){
            nomesArquivos.push_back(it.path().string());
        }
    } 
    for(string y : nomesArquivos){
        percorrerArquivo(y, this->indice); 
    }
}

vector<string> IndiceInvertido::buscadorIndice(string busca){
    int numero;
    string palavra, palavraNormalizada, nomeDocumento, documento;
    vector<string> palavras, documentosRelevantes;
    vector<string> ordemDocumentos;
    map<string, int> hits;
    map<string, int> resultado;

    std::istringstream iss(busca);
    while (iss >> palavra) {
        palavras.push_back(palavra);
    }

    for (const auto& it : palavras) {
        palavraNormalizada = normalizador(it);
        for (const auto& it : this->indice) {
            if (it.first == palavraNormalizada) {
                resultado = it.second;
            }

            for (const auto& it : resultado){
                nomeDocumento = it.first.substr(10);
                hits[nomeDocumento] = hits[nomeDocumento] + it.second;   
            }
        }
    }

    for (const auto& it : hits) {
        ordemDocumentos.push_back(it.first);
    }
    
    sort(ordemDocumentos.begin(), ordemDocumentos.end(), [&](string a, string b) {
        return hits[a] > hits[b] && a < b;
    });

    //reutilização da variavel numero;
    numero = 0;

    for(auto const& it : ordemDocumentos){
        documentosRelevantes.push_back(ordemDocumentos[numero]);
        numero++;
    }

    return documentosRelevantes;
}   

map<string, map <string, int>> IndiceInvertido::getIndice(){
    return this->indice;
}