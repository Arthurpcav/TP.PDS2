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

vector<string> IndiceInvertido::buscadorIndice(string busca){
    int numero;
    string palavra, palavraNormalizada, numeroString, documento;
    vector<string> documentosRelevantes;
    vector<string> palavras;
    vector<int> ordemDocumentos;
    map<int, int> hits;
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
                break;  
            }

            for (const auto& it : resultado){
                numeroString = it.first.substr(1, it.first.find(".txt") - 1);
                int numero = stoi(numeroString);
                hits[numero] = hits[numero] + it.second;   
            }
        }
    }
    for (const auto& it : hits) {
        ordemDocumentos.push_back(it.first);
    }
    
    sort(ordemDocumentos.begin(), ordemDocumentos.end(), [&](int a, int b) {
        return hits[a] > hits[b];
    });

    //reutilização da variavel numero;
    numero = 0;

    for(auto const& it : hits){
        documento = "d" + to_string(ordemDocumentos[numero]) + ".txt";
        documentosRelevantes.push_back(documento);
        numero++;
    }

    return documentosRelevantes;
}   

map<string, map <string, int>> IndiceInvertido::getIndice(){
    return this->indice;
}