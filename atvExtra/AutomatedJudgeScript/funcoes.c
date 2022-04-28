#include "funcoes.h"

void readInputLine(char** matrix, int n){
    // variaveis auxiliares que ajudam na logica do programa
    int lineBreaks = 0;
    int p = 0;
    char c;

    for(int i = 0; i < n; i++){ // loop para ler a quantidade correta de linhas
        do{ // enquanto o programa nao ler um \n e nao ultrapassar o limite de caractere sle continua lendo caracter por caracter

            scanf("%c", &c);
            matrix[lineBreaks][p++] = c;

        }while(c != '\n' && p <= 100);

        // quando ele parar de ler a linha ele reseta as variaveis auxiliares
        matrix[lineBreaks][p] = '\0';
        p = 0;
        lineBreaks++;
    }

}

void checkAnswer(char** matC, char** matS, int correctLines, int submitedLines, int execution){

    int numbersC[100];                      // armazena os numeros lidos na resposta correta
    int numbersS[100];                      // armazena os numeros lidos na resposta submetida
    int readNumbersC = 0, readNumbersS = 0; // armazena a quantidade de numeros lidos nas duas respotas
    int pC = 0, pS = 0;                     // variaveis auxiliares para percorrer as colunas da matriz de respostas
    int readLinesC = 0, readLinesS = 0;     // variaveis auxiliares para percorrer as linhas das matrizes de resposta
    char charC, charS;                      // variaveis auxiliares para analisar os caracteres correspondentes das duas matrizes

    bool correct = true;                    // variavel que verifica se as duas respostas sao identicas
    bool error = true;                      // variavel que verifica Presentation Errors

    while(readLinesC < correctLines || readLinesS < submitedLines){ // o loop funciona enquanto tiver caracteres para serem lidos em algumas
                                                                    // das matrizes

        if (readLinesC < correctLines){           // caso ainda existam caracteres a serem lidos na matriz correta
            charC = matC[readLinesC][pC++];       // le o caracter atual

            if (charC >= 48 && charC <= 57){      // caso seja um algarismo
                numbersC[readNumbersC++] = charC; // aramazena no vetor de numeros
            }

            if (charC == '\0'){                   // caso seja um \0 significa que uma linha chegou ao fim
                readLinesC++;                     // vai para a proxima linha
                pC = 0;                           // reseta o contador de colunas

                if (readLinesC >= correctLines){  // caso na tenha mais caracteres para ler
                    charC = 0;                    // o caracter atual da matriz correta eh setado com null
                }
            }
        }
        else{                                     // caso nao existam mais caracters a serem lidos
            charC = 0;                            // o caracter atual da matriz correta eh setado com null
        }

        if (readLinesS < submitedLines){          // caso ainda existam caracteres a serem lidos na matriz submetida
            charS = matS[readLinesS][pS++];       // le o caracter atual

            if (charS >= 48 && charS <= 57){      // caso seja um algarismo
                numbersS[readNumbersS++] = charS; // aramazena no vetor de numeros
            }

            if (charS == '\0'){                   // caso seja um \0 significa que uma linha chegou ao fim
                readLinesS++;                     // vai para a proxima linha
                pS = 0;                           // reseta o contador de colunas

                if (readLinesS >= submitedLines){ // caso na tenha mais caracteres para ler
                    charS = 0;                    // o caracter atual da matriz correta eh setado com null
                }
            }
        }
        else{                                     // caso nao existam mais caracters a serem lidos
            charS = 0;                            // o caracter atual da matriz correta eh setado com null
        }

        // debug
        // printf("%c %c %d %d\n", charC, charS, charC, charS);

        // caso algum dos caracteres correspondentes das duas matrizes nao sejam iguais as respsotas nao sao identicas
        if (charC != charS){
            correct = false;
        }


    }

    // depois de verificar todos os caracteres das duas matrizes, eh verificado os numeros lidos para verificar o Presentation Error
    if (readNumbersC == readNumbersS){          // se a quantidade de numeros lidos nas duas amtrizes forem iguais inicia-se a verificacao
        for (int i = 0; i < readNumbersC; i++){ // loop que percorre os dois vetores
            if (numbersC[i] != numbersS[i]){    // caso os numeros lidos nao estejam na mesma ordem
                error = false;                  // acontece o caso de Presentation Error
                break;
            }
        }
    }
    else{                                       // se a quantidade de numeros lidos nas duas matrizes nao forem iguais
        error = false;                          // o caso eh Wrong Answer
    } 


    // print final
    if (correct){
        printf("Run #%d: Accepted\n", execution);
    }
    else{
        if (error){
            printf("Run #%d: Presentation Error\n", execution);
        }
        else{
            printf("Run #%d: Wrong Answer\n", execution);
        }
    }

}