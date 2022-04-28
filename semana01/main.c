/*@JUDGE ID:1275455 100 C “3n+1 problem”*/

/* @BEGIN OF SOURCE CODE */
#include <stdio.h>

int main(){

    int min, max;       // aramzena os valores maximo e minimo fornecidos
    int count = 0;      // conta o ciclo do numero n, sendo que min <= n <= max
    int maxCycle = 0;   // armazena o maior ciclo
    int it;             // iterador
    int countPrint = 0; // variavel auxiliar para facilitar na hora do print

    while (scanf("%d %d", &min, &max) != EOF){ // enquanto houverem numeros a serem processados na entrada leia-os
        maxCycle = 0;                   // reseta o maior ciclo

        if (countPrint != 0){           // condicao para print do \n para ser aceito no online judge
            /*printf("\n");*/
        }
        
        for(it = min; it <= max; it++){ // loop que testa o clico para cada numero n, min <= n <= max

            int actualNumber = it;      // armazena o numero atual em outra variavel apra n interferir no for
            count = 1;                  // comeca a contagem do ciclo

            // esse while segue o pseudocodigo fornecido no enunciado
            while (actualNumber != 1){
                if (actualNumber % 2 == 0){
                    actualNumber = actualNumber / 2;
                }
                else{
                    actualNumber = (actualNumber * 3) + 1;
                }

                count++;
            }

            if (it == min){             // caso seja a primeira iteracao do for
                maxCycle = count;       // o maior ciclo recebe o contador atual
            }
            else{                       // caso contrario
                if (count > maxCycle){  // se o contador atual for maior que o maior ciclo armazenado
                    maxCycle = count;   // o maior cilco recebe o contados
                }
            }
        }

        printf("%d %d %d\n", min, max, maxCycle); // realiza o print
        countPrint++;                             // incrementa a variavel auxiliar
    }

    return 0;
}

/* @END OF SOURCE CODE */
