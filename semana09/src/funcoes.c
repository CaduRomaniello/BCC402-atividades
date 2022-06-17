#include "funcoes.h"

void apuraInformacoes(int*** cidade, int t, int left, int top, int right, int bottom){

    for (int i = top - 1; i < bottom - 1; i++){
        for (int j  = left - 1; j < right - 1; j++){
            cidade[t][i][j] = 0;
        }
    }

}

void posicaoExataInicial(int*** cidade, int W, int H, int* iInicial, int* jInicial, bool* achou, bool* escapou){

    int coord_i = -1;
    int coord_j = -1;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < H; j++){
            if (cidade[0][i][j] == 1){
                if (coord_i == -1){
                    coord_i = i;
                    coord_j = j;
                }
                else{
                    *achou = false;
                    *escapou = false;
                    return;
                }
            }
        }
    }

    if (coord_i == -1){
        *achou = false;
        *escapou = true;
        return;
    }
    *iInicial = coord_i;
    *jInicial = coord_j;
    *achou = true;
    *escapou = false;

}

void posicaoExataFinal(int*** cidade, int W, int H, int T, int* iFinal, int* jFinal, bool* achou, bool* escapou){
    int coord_i = -1;
    int coord_j = -1;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < H; j++){
            if (cidade[T - 1][i][j] == 1){
                if (coord_i == -1){
                    coord_i = i + 1;
                    coord_j = j + 1;
                }
                else{
                    *achou = false;
                    *escapou = false;
                    return;
                }
            }
        }
    }

    if (coord_i == -1){
        *achou = false;
        *escapou = true;
        return;
    }
    *iFinal = coord_i;
    *jFinal = coord_j;
    *achou = true;
    *escapou = false;
}

void posicaoExataFinal(int*** cidade, int W, int H, int T, int* i, int* j, bool* achou, bool* escapou){
    int coord_i = -1;
    int coord_j = -1;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < H; j++){
            if (cidade[T - 1][i][j] == 1){
                if (coord_i == -1){
                    coord_i = i + 1;
                    coord_j = j + 1;
                }
                else{
                    *achou = false;
                    *escapou = false;
                    return;
                }
            }
        }
    }

    if (coord_i == -1){
        *achou = false;
        *escapou = true;
        return;
    }
    *i = coord_i;
    *j = coord_j;
    *achou = true;
    *escapou = false;
}

void achaCaminho(int*** cidade, int W, int H, int T, int iInicial, int jInicial, int iFinal, int jFinal){

    for (int m = 2; m < T; m++){

    }

}