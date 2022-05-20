// DESCOBRINDO O PROBLEMA REAL -> https://algorithmist.com/wiki/UVa_10213_-_How_Many_Pieces_of_Land_%3F
// MOSERS CIRCLE PROBLEM       -> https://medium.com/mathadam/mosers-circle-7b5e4fbb6438
// BINOMIO DE NEWTON           -> https://brasilescola.uol.com.br/matematica/binomio-de-newton.htm

#include <stdio.h>
#include <math.h>

// funcao para calcular o fatorial d eum numero n
double fatorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}

int main(){

    int cases;     // numero de casos para executar
    int n;        // numero atual de pontos para executar o algoritmo
    double total; // resultado da conta

    scanf("%d", &cases); // leitura da qntd de casos

    for (int i = 0; i < cases; i++){ // iteracao para executar todos os casos fornecidos
        scanf("%d", &n); // leitura do valor de pontos atual

        /*
        
        O problema original é conhecido como MOSERS CIRCLE PROBLEM que consiste em dado uma quantidade de pontos na borda em um circulo, descobri rem quantos "terrenos" eh possivel dividir esse circulo ligando todos os pontos. A formula final para esse problema eh a resolucao de um somatorio:

        ∑{k = 0 : n} (N-1  K)

        onde (N-1  K) eh um binomio de newton que pode ser resolvido da seguinte forma:

        (X  Y) = (X!) / (Y! * (X - Y)!)

        */

        total = 0; // reset da variavel acumuladora 
        for(int k = 0; k < n; k++){ // for para realizar o somatorio
            total += (fatorial(n - 1))/((fatorial(k)) * (fatorial((n - 1) - k))); // reoslucao do binomio de newton
        }

        printf("%.0lf\n", total); // print do resultado
    }

    return 0;
}