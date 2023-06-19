#include "indice.h"
#include "normalizador.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>

using std::to_string;

using std::to_string; 

void IndiceInvertido::percorrerArquivo(string nomeArquivo){
    std::ifstream arq(nomeArquivo); 
    string linha; 
    string palavra; 

    while(std::getline(arq, linha)){
        std::istringstream iss(linha); 
        while(iss >> palavra){
            indice[normalizador(palavra)][nomeArquivo]++; 
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
        percorrerArquivo(y); 
    }
}

vector<string> IndiceInvertido::buscadorIndice(string busca){
    int numero;
    string palavra, palavraNormalizada, nomeDocumento;
    vector<string> palavras, documentosRelevantes, ordemDocumentos;
    map<string, int> hits, numeroPalavras, resultado;

    std::istringstream iss(busca);
    while (iss >> palavra) {
        if(!(find(palavras.begin(), palavras.end(), palavra) != palavras.end())){
            palavras.push_back(palavra);
        }
    }
    int quantidade = palavras.size();

    for (const auto& it : palavras) {
        palavraNormalizada = normalizador(it);
        for (const auto& it : this->indice) {
            if (it.first == palavraNormalizada) {
                resultado = it.second;
                for (const auto& it : resultado){
                    nomeDocumento = it.first.substr(10);
                    hits[nomeDocumento] = hits[nomeDocumento] + it.second;
                    numeroPalavras[nomeDocumento] = numeroPalavras[nomeDocumento] +1; 
                }
            }
        }
    }

    for (const auto& it : hits) {
        if(numeroPalavras[it.first] == quantidade){
            ordemDocumentos.push_back(it.first);
        }
    }

    sort(ordemDocumentos.begin(), ordemDocumentos.end(), [&](string a, string b) {
        if(hits[a] == hits[b]) {
            return hits[a] > hits[b] && a < b;
        }
        else {
            return hits[a] > hits[b]; 
        }
    });

    //reutilização da variavel numero;
    numero = 0;

    for(auto const& it : ordemDocumentos){
        documentosRelevantes.push_back(ordemDocumentos[numero]);
        numero++;
    }

    if(documentosRelevantes.size()==0){
        BuscaNaoEncontrada x; 
        throw x; 
    }else{
        return documentosRelevantes; 
    }

}

map<string, map <string, int>> IndiceInvertido::getIndice(){
    return this->indice;
}
