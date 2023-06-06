#include"normalizador.h"


string normalizador(string palavra){
    string palavraNormalizada; 
    string::iterator it; 
    for(it = palavra.begin(); it != palavra.end(); it++){
        if(isalpha(*it)){
            palavraNormalizada.push_back(tolower(*it)); 
        }
    }
    return palavraNormalizada;  
}