#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(){

    
    int x; // represeta o menor inteiro x que satisfaz a equacao presente no pdf
    int a; // numero lido
    int i = 0; // iterador do somatorio
    long int p; // resultado do somatorio

    /*
    
    Dado um numero 'a' que sera lido da entrada, existe algum numero 'p' que eh multiplo de 'a' que na sua notacao decimal eh uma sequencia de 1's. Exemplo:
        - 111 em notacao decimal -> (1*10⁰) + (1*10¹) + (1*10²)
        - 1111 em notacao decimal -> (1*10⁰) + (1*10¹) + (1*10²) + (1*10³)

    O objetivo eh encontrar a quantidade de digitos do menor numero 'p' que eh multiplo de 'a' que em sua notacao decimal eh uma sequencia de 1's

    Para fazer isso testaremos para todos os numeros formados por sequencias de 1's se ele eh um multiplo de 'a'
    
    */
    while(scanf("%d", &a) != EOF){ // lendo os valores do input enquanto existirem

        if (a % 2 == 0 || a % 5 == 0){ // o numero lido nao pode ser divisel por 2 e nem por 5, caso isso ocorra lemos o proximo inteiro da entrada
            continue;
        }

        p = 0; // resetando a variavel que contera o resultado do somatorio
        i = 0; // resetando o iterador do somatorio
        
        for(x = 1; true; x++){ // precisamos encontrar o menor valor de x > 0 que satisfaz a equacao, para isos iremos testar para todos os valores x enquanto a equacao nao for satisfeita
            p += pow(10, i++); // adicionando em 'p' a proxima parte da notacao decimal

            if (p % a == 0){ // caso a equacao tenha sido satisfeita saimos do loop
                break;
            }
        }

        printf("%d\n", x);

    }

    return 0;
}