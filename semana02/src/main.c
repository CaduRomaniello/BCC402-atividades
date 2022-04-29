#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int main(){

    int n;         // armazena a quantidade de numeros da sequencia
    int* sequence; // vetor com o snumeros da sequencia
    bool* diff;    // vetor de booleanos que verifica se a diferenca ja foi contabilizada

    int i, x; // iteradores
    bool missingNumber; // verifica se alguma diferenca nao foi contabilizada

    while(scanf("%d", &n) != EOF){                 // o loop ocorre enquanto houverem valores a serem lidos
        missingNumber = false;                     // reseta o valor da variavel auxiliar

        sequence = malloc(n * sizeof(int));        // aloca o vetor da sequencia
        diff = malloc((n-1) * sizeof(int));        // aloca o vetor das diferencas

        for (i = 0; i < n ; i++){                  // loop para leitura dos dados
            scanf("%d", &sequence[i]);

            if(i < (n-1)){                         // caso o iterador esteja nos limites do vetor de diferencas
                diff[i] = false;                   // inicializa o vetor de diferencas com false
            }
        }

        for (i = 0; i < (n-1); i++){               // loop que ira realizar a conta das diferencas entre os numeros da sequencia
            x = abs(sequence[i] - sequence[i+1]);  // calcula o valor absoluto da diferenca

            if (x <= 0 || x > (n-1) || diff[x-1]){ // caso a diferenca seja invalida
                missingNumber = true;              // a sequencia nao eh um jolly jumper
                break;
            }
            else{                                  // caso contrario
                diff[x-1] = true;                  // sinaliza que a diferenca foi contabilizada no vetor de diferencas
            }
        }

        for(i = 0; i < n-1; i++){                  // percorre o vetor de diferencas
            if (!diff[i]){                         // caso alguma diferenca nao tenha sido contabilizada
                missingNumber = true;              // a sequencia nao eh um jolly jumper
                break;
            }
        }

        // print final
        if(missingNumber){
            printf("Not jolly\n");
        }
        else{
            printf("Jolly\n");
        }

        // libera  amemoria alocada
        free(sequence);
        free(diff);
        
    }

    return 0;
}
