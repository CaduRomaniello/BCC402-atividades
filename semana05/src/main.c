#include "funcoes.h"

int main(){

    int correctLines, submitedLines; // variaveis que guardam a quantidade de linhas de cada resposta
    char** correctAnswer;            // matriz de caracteres que aramzena as respostas corretas
    char** submitedAnswer;           // matriz de caracteres que armazena as respostas submetidas
    char c;                          // variavel auxiliar para ler caracteres indesejaveis
    int execution = 1;               // variavel utilizada no print

    do{ // enquanto a quantidade de linhas for diferente de 0 ele continua lendo as respostas
        
        // le a quantidade de linhas da resposta correta, caso seja 0 encerra o programa, tambem le caracteres indesejados
        scanf("%d", &correctLines);
        if (correctLines <= 0){exit(0);}
        do{
            c = getchar();
        }while(c != 10);

        // aloca memoria para a matriz de respostas corretas e realiza a leitura dos dados
        correctAnswer = malloc(correctLines * sizeof(char*));
        for (int i = 0; i < correctLines; i++){
            correctAnswer[i] = malloc(101 * sizeof(char));
        }
        readInputLine(correctAnswer, correctLines);

        // le a quantidade de linhas da resposta submetida, caso seja 0 encerra o programa, tambem le caracteres indesejados
        scanf("%d", &submitedLines);
        if (submitedLines <= 0){exit(0);}
        do{
            c = getchar();
        }while(c != 10);

        // aloca memoria para a matriz de respostas submetidas e realiza a leitura dos dados
        submitedAnswer = malloc(submitedLines * sizeof(char*));
        for (int i = 0; i < submitedLines; i++){
            submitedAnswer[i] = malloc(101 * sizeof(char));
        }
        readInputLine(submitedAnswer, submitedLines);

        //faz comparacao entre as duas respostas
        checkAnswer(correctAnswer, submitedAnswer, correctLines, submitedLines, execution);
        execution++;

        //libera a memoria das duas matrizes para a proxima iteracao
        for (int i = 0; i < correctLines; i++){
            free(correctAnswer[i]);
        }
        free(correctAnswer);

        for (int i = 0; i < submitedLines; i++){
            free(submitedAnswer[i]);
        }
        free(submitedAnswer);

    } while (correctLines != 0);
    

    return 0;
}