#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void apuraInformacoes(int*** cidade, int t, int left, int top, int right, int bottom);
void posicaoExataInicial(int*** cidade, int W, int H, int* iInicial, int* jInicial, bool* achou, bool* escapou);
void posicaoExataFinal(int*** cidade, int W, int H, int T, int* iFinal, int* jFinal, bool* achou, bool* escapou);
void achaCaminho(int*** cidade, int W, int H, int T, int iInicial, int jInicial, int iFinal, int jFinal);

void posicaoExata(int*** cidade, int W, int H, int T, int* i, int* j, bool* achou, bool* escapou);