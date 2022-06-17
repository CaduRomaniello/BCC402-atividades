#ifndef FUNCOES_H
#define FUNCOES_H

#include "DFS.hpp"

using namespace std;

void posicaoExata(vector<vector<vector<bool>>> cidade, int W, int H, int T, int* i, int* j); // procura se no instante de tempo T a localizacao do ladrao eh exata

void printCaminho(vector<int> ordemVisitacao, Grafo g); // funcao para realizar o output

#endif