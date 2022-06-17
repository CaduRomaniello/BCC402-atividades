#include "funcoes.hpp"

void posicaoExata(vector<vector<vector<bool>>> cidade, int W, int H, int T, int* i, int* j){

    int coord_i = -1;
    int coord_j = -1;

    // percorremos a matriz no tempo T procurando as celulas em que o ladrao poderia estar
    for (int i = 0; i < H; i++){
        for (int j = 0; j < H; j++){
            if (cidade[T - 1][i][j]){
                if (coord_i == -1){ // caso a celula seja a primeira celula true a ser encontrada guardamos seus indices
                    coord_i = i + 1;
                    coord_j = j + 1;
                }
                else{ // caso a celula nao seja a primeira celula true saimos da funcao ja que queremos a posicao exata
                    return;
                }
            }
        }
    }

    // caso n tenha sido possivel encontrar nenhuma celula true, saimos da funcao
    if (coord_i == -1){
        return;
    }

    // caso tenha sido encontrado apenas uma celula com o valor true atualizamos os ponteiros das coordenadas com as coordenadas salvas
    *i = coord_i;
    *j = coord_j;

}

void printCaminho(vector<int> ordemVisitacao, Grafo g){

    // percorre o vetor de caminho printando suas informacoes
    for (auto i : ordemVisitacao){
        cout << "Time step " << g.vertices[i-1].t << ": The robber has been at " << g.vertices[i-1].j << "," << g.vertices[i - 1].i << "." << endl;

    }
    cout << endl;
}