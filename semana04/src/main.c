/*

https://codingstrife.wordpress.com/2013/07/23/solution-uva10037-pc110403-bridge/
https://cybosocks-uva.blogspot.com/2019/12/uva-online-judge-bridge-problem.html
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=32&page=show_problem&problem=978

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "mergeSort.h"

/*
Função que busca a pessoa mais rapida
*/
int getFastest(bool* vet, int n){
    for (int i = 0; i < n; i++){
        if (vet[i]){
            return i;
        }
    }
    return -1;
}

/*
Função que busca a segunda pessoa mais rapida
*/
int getSecondFastest(bool* vet, int n){
    bool foundFirst = false;
    for (int i = 0; i < n; i++){
        if (vet[i]){
            if (foundFirst){
                return i;
            }
            else{
                foundFirst = true;
            }
        }
    }
    return -1;
}

/*
Função que busca a pessoa mais lenta
*/
int getSlowest(bool* vet, int n){
    for (int i = n-1; i >= 0; i--){
        if (vet[i]){
            return i;
        }
    }
    return -1;
}

/*
Função que busca a segunda pessoa mais lenta
*/
int getSecondSlowest(bool* vet, int n){
    bool foundFirst = false;
    for (int i = n-1; i >= 0; i--){
        if (vet[i]){
            if (foundFirst){
                return i;
            }
            else{
                foundFirst = true;
            }
        }
    }
    return -1;
}

int main(){

    int numberOfCases;                 // guarda o numero de casos
    int numberOfPeople;                // guardar o numero de pessoas do caso em questao
    int leftPeople, rightPeople;       // guarda a quantidade de pessoas que estao de cada lado
    int time;                          // armazena o tempo total
    int* people;                       // vetor contendo a velocidade de cada pessoa
    bool* leftSide;                    // vetor que verifica a presenca da pessoa do lado esquerdo
    bool* rightSide;                   // vetor que verifica a presenca da pessoa do lado direito
    char* path = malloc(sizeof(char)); // string que guardara a ordem em que as pessoas irao cruzar de um lado pro outro
    int pathSize;                      // tamanho da string dos cruzamentos
    char tempString[10];               // string auxiliar

    scanf("%d\n\n", &numberOfCases);

    for(int i = 0; i < numberOfCases; i++){

        // resetando os valores das variaveis auxiliares
        scanf("%d\n", &numberOfPeople);
        leftPeople = numberOfPeople;
        rightPeople = 0;
        time = 0;
        path = malloc(sizeof(char));
        strcpy(path, "");
        pathSize = 0;

        // alocando os vetores e lendo a velocidade das pessoas
        leftSide = malloc(numberOfPeople * sizeof(bool));
        rightSide = malloc(numberOfPeople * sizeof(bool));
        people = malloc(numberOfPeople * sizeof(int));
        for(int j = 0; j < numberOfPeople; j++){
            scanf("%d\n", &people[j]);
            leftSide[j] = true;
            rightSide[j] = false;
        }

        mergeSort(people, numberOfPeople); // ordena as pessoas por do mais rapido ate o mais lento

        /*
        
        O problema pode ser dividido em 4 partes:
        . quando ha 1 pessoa do lado esquerdo
        . quando ha 2 pessoas do lado esquerdo
        . quando ha 3 pessoas do lado esquerdo
        . quando ha 4 ou mais pessoas do lado esquerdo

        . No primeiro caso basta atravessar essa pessoa para o lado direito
        . No segundo caso basta atravessar as duas pessoas para o lado direito
        . No terceiro caso suponha tres pessoas A, B, C ordenadas da mais rápida para a mais lenta.
          Com isso, basta realizar as travessias ->AB, A<-, ->AC
        . No quarto e ultimo caso eh necessaria uma avaliacao mais cuidadosa{
            - Suponha que as pessoas do lado esquerdo sao A, B, ... , Y, Z ordenadas da mais rapida para a mais lenta
            - Existem duas possibilidades para fazer a travessia de 4 pessoas para o lado direito
            - 1º possibilidade{
                -> AB
                <- A
                -> YZ
                <- B
                -> AB
                . tempo total: B + A + Z + B + B = 3B + A + Z
            }
            - 2º possibilidade{
                -> AB
                <- A
                -> AY
                <- A
                -> AZ
                . tempo total: B + A + Y + A + Z = 2A + B + Y + Z
            }
            - Agora basta verificar qual das duas eh a mais rapida{
                . 3B + A + Z < 2A + B + Y + Z    ou    3B + A + Z > 2A + B + Y + Z
                . Manipulando as equacoes temos:
                . 2B < A + Y    ou    2B > A + Y
            }
            - Com a analise finalizada basta relaizar os movimentos
            - Vale ressaltar que caso apos a finalizacao desses movimentos ainda exista pelo menos uma pessoa do lado esquerdo, 
              a pessoa mais rapida do lado direito deve voltar para o lado esquerdo para retornar a lanterna
        }
        
        */
        while(true){
            if(leftPeople == 1){
                // ajustando o tamanho da string final para receber a nova string
                pathSize = strlen(path) + 4;
                path = realloc(path, pathSize * sizeof(char));

                // pegando a velocidade da unica pessoa do lado esquerdo
                int position = getFastest(leftSide, numberOfPeople);
                int speed = people[position];

                // atualizando a string final
                sprintf(tempString, "%d\n", speed);
                strcat(path, tempString);
                time += speed;

                // atualizando variaveis auxiliares
                leftPeople -= 1;
                leftSide[position] = false;
                rightPeople += 1;
                rightSide[position] = true;

                break;
            }
            else if(leftPeople == 2){
                // ajustando o tamanho da string final para receber a nova string
                pathSize = strlen(path) + 8;
                path = realloc(path, pathSize * sizeof(char));

                // pegando a velocidade das duas pessoas do lado esquerdo
                int position_1 = getFastest(leftSide, numberOfPeople);
                int position_2 = getSecondFastest(leftSide, numberOfPeople);
                int speed_1 = people[position_1];
                int speed_2 = people[position_2];

                // atualizando a string final
                sprintf(tempString, "%d %d\n", speed_1, speed_2);
                strcat(path, tempString);
                time += speed_2;

                // atualizando variaveis auxiliares
                leftPeople -= 2;
                leftSide[position_1] = false;
                leftSide[position_2] = false;
                rightPeople += 2;
                rightSide[position_1] = true;
                rightSide[position_2] = true;

                break;
            }
            else if(leftPeople == 3){
                // ajustando o tamanho da string final para receber a nova string
                pathSize = strlen(path) + 20;
                path = realloc(path, pathSize * sizeof(char));

                // pegando a velocidade das 3 pessoas do lado esquerdo
                int position_1 = getFastest(leftSide, numberOfPeople);
                int position_2 = getSecondFastest(leftSide, numberOfPeople);
                int position_3 = getSlowest(leftSide, numberOfPeople);
                int speed_1 = people[position_1];
                int speed_2 = people[position_2];
                int speed_3 = people[position_3];

                // atualizando a string final
                sprintf(tempString, "%d %d\n", speed_1, speed_3);
                strcat(path, tempString);
                time += speed_3;
                sprintf(tempString, "%d\n", speed_1);
                strcat(path, tempString);
                time += speed_1;
                sprintf(tempString, "%d %d\n", speed_1, speed_2);
                strcat(path, tempString);
                time += speed_2;

                // atualizando variaveis auxiliares
                leftPeople -= 3;
                leftSide[position_1] = false;
                leftSide[position_2] = false;
                leftSide[position_3] = false;
                rightPeople += 3;
                rightSide[position_1] = true;
                rightSide[position_2] = true;
                rightSide[position_3] = true;

                break;
            }
            else{
                // ajustando o tamanho da string final para receber a nova string
                pathSize = strlen(path) + 32;
                path = realloc(path, pathSize * sizeof(char));

                // pegando a velocidade das 2 pessoas mais rapidas e das 2 pessoas mais lentas do lado esquerdo
                int pos_fastest = getFastest(leftSide, numberOfPeople);
                int pos_secFastest = getSecondFastest(leftSide, numberOfPeople);
                int pos_slowest = getSlowest(leftSide, numberOfPeople);
                int pos_secSlowest = getSecondSlowest(leftSide, numberOfPeople);

                int speed_fastest = people[pos_fastest];
                int speed_secFastest = people[pos_secFastest];
                int speed_slowest = people[pos_slowest];
                int speed_secSlowest = people[pos_secSlowest];

                // atualizando variaveis auxiliares
                leftPeople -= 4;
                leftSide[pos_fastest] = false;
                leftSide[pos_secFastest] = false;
                leftSide[pos_slowest] = false;
                leftSide[pos_secSlowest] = false;
                rightPeople += 4;
                rightSide[pos_fastest] = true;
                rightSide[pos_secFastest] = true;
                rightSide[pos_slowest] = true;
                rightSide[pos_secSlowest] = true;

                // esse if faz a verificacao de qual movimento eh o mais rapido
                if((2 * speed_secFastest) < (speed_fastest + speed_slowest)){
                    // atualizando a string final
                    sprintf(tempString, "%d %d\n", speed_fastest, speed_secFastest);
                    strcat(path, tempString);
                    time += speed_secFastest;
                    sprintf(tempString, "%d\n", speed_fastest);
                    strcat(path, tempString);
                    time += speed_fastest;
                    sprintf(tempString, "%d %d\n", speed_secSlowest, speed_slowest);
                    strcat(path, tempString);
                    time += speed_slowest;
                    sprintf(tempString, "%d \n", speed_secFastest);
                    strcat(path, tempString);
                    time += speed_secFastest;
                    sprintf(tempString, "%d %d\n", speed_fastest, speed_secFastest);
                    strcat(path, tempString);
                    time += speed_secFastest;

                    // tratando o caso em que ainda sobram pessoas do lado esquerdo
                    if (leftPeople > 0){
                        pathSize = strlen(path) + 4;
                        path = realloc(path, pathSize * sizeof(char));

                        leftPeople++;
                        leftSide[pos_fastest] = true;
                        rightPeople--;
                        rightSide[pos_fastest] = false;

                        sprintf(tempString, "%d\n", speed_fastest);
                        strcat(path, tempString);
                        time += speed_fastest;
                    }
                    // caso nao existam pessoas do lado esquerdo o progrmaa pode ser finalizado
                    else{
                        break;
                    }
                }
                else{
                    // atualizando a string final
                    sprintf(tempString, "%d %d\n", speed_fastest, speed_secFastest);
                    strcat(path, tempString);
                    time += speed_secFastest;
                    sprintf(tempString, "%d\n", speed_fastest);
                    strcat(path, tempString);
                    time += speed_fastest;
                    sprintf(tempString, "%d %d\n", speed_fastest, pos_secSlowest);
                    strcat(path, tempString);
                    time += pos_secSlowest;
                    sprintf(tempString, "%d \n", speed_fastest);
                    strcat(path, tempString);
                    time += speed_fastest;
                    sprintf(tempString, "%d %d\n", speed_fastest, pos_slowest);
                    strcat(path, tempString);
                    time += pos_slowest;

                    // tratando o caso em que ainda sobram pessoas do lado esquerdo
                    if (leftPeople > 0){
                        pathSize = strlen(path) + 4;
                        path = realloc(path, pathSize * sizeof(char));

                        leftPeople++;
                        leftSide[pos_fastest] = true;
                        rightPeople--;
                        rightSide[pos_fastest] = false;

                        sprintf(tempString, "%d\n", speed_fastest);
                        strcat(path, tempString);
                        time += speed_fastest;
                    }
                    // caso nao existam pessoas do lado esquerdo o progrmaa pode ser finalizado
                    else{
                        break;
                    }
                }
            }
        }

        // relaizando o print final
        printf("%d\n", time);
        printf("%s\n", path);

        // liberando os vetores alocados dinamicamente
        free(people);
        free(leftSide);
        free(rightSide);

    }

    return 0;
}