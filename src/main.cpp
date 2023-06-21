#include "indice.h"
#include "normalizador.h"

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

//cores
#define RESET      "\033[0m"
#define VERMELHO        "\033[31m"
#define AZUL       "\033[34m"

using std::cout, std::endl, std::cin;

int main(){
    IndiceInvertido indiceMain;
    vector<string> documentosRelevantes;
    string busca, parada, nomePasta = "documentos";
    indiceMain.percorrerPasta(nomePasta); 
    bool finalizar = false; 
    system(CLEAR_COMMAND); 

    while(!finalizar){ 
        cout << AZUL << "Digite o que deseja buscar ou pressione 'ctrl+z' para finalizar."<< RESET <<endl; 
                
        getline(cin,busca);

        try{
            documentosRelevantes = indiceMain.buscadorIndice(busca);
        }catch(BuscaNaoEncontrada& e){
            cout << VERMELHO <<"Não foi encontrado nenhum arquivo correspondente a essa busca." << RESET << endl; 
            continue; 
        }
        
        for (const auto& it : documentosRelevantes){
        cout << it << endl; 
        }
    }  
    return 0; 
}