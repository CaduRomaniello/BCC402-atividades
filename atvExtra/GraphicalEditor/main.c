#include "funcoes.h"

int main(){

    char** image = malloc(1 * sizeof(char)); // Variavel que guardara a imagem
    int rows, columns;                       // variaveis que serao passadas como ponteiros que representam a quantidade de linhas e colunas
    char option;                             // variavel que armazena a opcao atual


    do // esse loop ira ler uma opcao ate que ela seja igual a 'X'
    {
        do // esse loop previne que o programa leia caracteres indesejados como opcoes
        {
            scanf("%c", &option);
        } while (option == ' ' || option == '\n' || option == 13);

        if (validCommand(option)){ // checa se o comando eh valido

            executeCommand(&image, option, &rows, &columns); // caso o comando seja valido chama uma funcao auxiliar que decide o que fazer
                                                             // de acordo com a opcao

        }

    } while (option != 'X');
    

    return 0;
}