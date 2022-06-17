#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct msg{
    int Ti;
    int left;
    int top;
    int right;
    int bottom;
}MSG;

int main(){

    int W;
    int H;
    int T;
    int qntdMsgs;
    int contador = 1;

    while(scanf("%d %d %d", &W, &H, &T) != EOF){

        printf("Robbery #%d\n", contador++);

        int*** cidade;
        cidade = malloc(T * sizeof(int**));
        for (int i = 0; i < T; i++){
            cidade[i] = malloc(H * sizeof(int*));
            for (int j = 0; j < H; j++){
                cidade[i][j] = malloc(W * sizeof(int));
                for (int k = 0; k < W; k++){
                    cidade[i][j][k] = 1;
                }
            }
        }

        //scanf("%d", &qntdMsgs);
        //MSG* mensagem = malloc(qntdMsgs * sizeof(MSG));
        int Ti;
        int left;
        int top;
        int right;
        int bottom;
        for(int i = 0; i < qntdMsgs; i++){
            scanf("%d %d %d %d %d", &Ti, &left, &top, &right, &bottom);
            apuraInformacoes(cidade, Ti, left, top, right, bottom);
        }

        int iInicial = -1;
        int jInicial = -1;
        int iFinal = -1;
        int jFinal = -1;
        bool achou = false;
        bool escapou = false;

        posicaoExata(cidade, W, H, 1, &iInicial, &jInicial, &achou, &escapou);
        if (escapou && !achou){
            printf("The robber has escaped.\n\n");
            continue;
        }

        if (!achou && !escapou){
            printf("Nothing known.\n\n");
            continue;
        }

        achou = false;
        escapou = false;
        posicaoExata(cidade, W, H, T, &iFinal, &jFinal, &achou, &escapou);
        if (escapou && !achou){
            printf("The robber has escaped.\n\n");
            continue;
        }

        if (!achou && !escapou){
            printf("Nothing known.\n\n");
            continue;
        }

        if (abs(iFinal - iInicial) + abs(jFinal - jInicial) != T){
            printf("Nothing known.\n\n");
            continue;
        }

        printf("Time step 1: The robber has been at %d,%d.\n", iInicial, jInicial);
        achaCaminho(cidade, W, H, T, iInicial, jInicial, iFinal, jFinal);
        printf("Time step %d: The robber has been at %d,%d.\n", T, iFinal, jFinal);

    }

    return 0;
}