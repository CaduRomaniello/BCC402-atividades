//https://github.com/lamphanviet/competitive-programming/blob/master/uva-online-judge/accepted-solutions/850%20-%20Crypt%20Kicker%20II.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define KEY "the quick brown fox jumps over the lazy dog\n"
#define ALPHABET_SIZE 26

int readInput(char input[][81]){

    bool readLineBreak = false; // true caso o ultimo caractere lido seja \n
    char c;                     // caractere atual
    int row = 0, column = 0;    // linha e coluna atuais
    int scanfFailureCheck;      // retorno da funcao scanf

    while(true){ // o loop executa ate q uma das condicoes de parada seja atingida
        do{
            scanfFailureCheck = scanf("%c", &c);
        } while (c == 13); // esse loop evita a leitura de caracteres indesejados

        if (scanfFailureCheck == -1){ // caso ocorra um erro na leitura inserimos o \0 no final da ultima frase e encerramos a funcao
            input[row][column] = '\0';
            row++;
            return row;
        }

        input[row][column] = c;              // aramzenando o caractere lido na matriz

        if (c == '\n'){                      // caso o caractere lido seja \n
            if (readLineBreak){              // caso o caractere lido anteriormente tambem seja \n
                input[row][column] = '\0';   // colocamos \0 a palavra atual
                row++;                       // atualizamos a quantidade de frases lidas
                return row;                  // retornamos a quantidade de frases lidas
            }
            else{                            // caso o caractere lido anteriormente nao seja \n
                readLineBreak = true;        // atualizamos a flag
                input[row][column+1] = '\0'; // colocamos \0 na palavra atual
                row++;                       // vamos para a proxima frase
                column = 0;                  // resetamos o contador das colunas
            }
        }
        else{                                // caso o caractere lido nao seja /n
            column++;                        // atualizamos o contador das colunas
            readLineBreak = false;           // atualizamos a flag
        }
    }

    /*
        a funcao abaixo funcionou nos computadores do laboratorio para realizar a leitura do input
        porem, na minha maquina pessoal foi necessario lidar com a presenca de caracteres indesejados
        por isso a leitura na funcao de cima foi feita caractere por caractere
    */

    //////////////////////////////////////////////////////////////////////////

    // int i = 0;
    // fgets(input[i], 80, stdin); // le uma string do STDIN de no maximo 80 caracteres

    // /*
    // a condição do while é ser != de '\0' pois o '\0' é para a string o que o NULL é para os tipos numéricos
    // */
    // while(input[i][0] != '\0'){ // enquanto puder ler alguma string, a leitura continua
    //     i++;
    //     fgets(input[i], 80, stdin);
    // }

    // return i; // retorna a quantidade de frases lidas

}

int findKey(char input[][81], int numberOfPhrases, int sizeOfKey){

    /*

    de acordo com a quantidade de frases lidas do input, são realizados testes para achar uma frase que é semelhante a chave
    para isso, primeiro é verificado se o tamanho da frase candidata é o mesmo da chave
    caso verdadeiro, é verificado se a frase candidata e a chave possuem a mesma quantidade de palavras e se elas são do mesmo tamanho    

    */
    for (int i = 0; i < numberOfPhrases; i++){
        if (strlen(input[i]) == sizeOfKey){
            bool equalSpaces = true;

            for (int j = 0; j < sizeOfKey; j++){
                if (KEY[j] == ' ' && input[i][j] != ' '){
                    equalSpaces = false;
                    break;
                }
            }

            if (equalSpaces){
                return i;
            }
        }
    }

    return 0;

}

void matchLetters(char input[][81], char* alphabet, int keyPhrasePosition){

    int letterPosition;

    /*

    para cada letra da frase semelhante a chave é registrado sua equivalente da chave
    caso essa letra da frase semelhante já estiver mapeada e o valor for diferente do prévio, significa que a frase não é semelhante a chave então o programa encerra
    
    */
    for (int i = 0; i < strlen(KEY); i++){
        letterPosition = input[keyPhrasePosition][i] - 97;
        
        if(input[keyPhrasePosition][i] == '\n'){ // caso o caractere lido seja \n a frase acabou
            break;
        }
        if(input[keyPhrasePosition][i] == ' '){ // caso o caractere lido seja ' ' ele nao precisa ser mapeado
            continue;
        }

        if (alphabet[letterPosition] != '\0'){
            if (KEY[i] != alphabet[letterPosition]){
                printf("No solution.\n");
                exit(1);
            }
        }

        alphabet[letterPosition] = KEY[i];
    }

}

int main(){

    /*

    numberOfCases     - numero inicial do output
    sizeOfKey         - tamanho da chave
    numberOfPhrases   - quantidade de frases do input
    keyPhrasePosition - posicao da frase do input que combina com a chave
    alphabet          - vetor para representar as letras correspondentes do alfabeto
    input             - matriz com as frases do input

    */

    int numberOfCases, sizeOfKey = strlen(KEY), numberOfPhrases, keyPhrasePosition;
    char alphabet[ALPHABET_SIZE];
    char input[100][81];

    scanf("%d\n\n", &numberOfCases);

    for (int i = 0; i < numberOfCases; i++){

        for(int j = 0; j < 100; j++){
            input[j][0] = '\0';
        }
        
        if (i != 0){ // caso for necessário fazer a tradução mais de uma vez os blocos de frases devem ser separados por uma linha em branco
            printf("\n");
        }

        for (int i = 0; i < ALPHABET_SIZE; i++){ // iniciando o alfabeto com '\0' para fazer verificacoes futuras
            alphabet[i] = '\0';
        }

        numberOfPhrases = readInput(input);                             // lendo o input
        keyPhrasePosition = findKey(input, numberOfPhrases, sizeOfKey); // procurando frase que combina com a chave

        matchLetters(input, alphabet, keyPhrasePosition);               // faz o casamento das letras

        for (int j = 0; j < numberOfPhrases;j++){ // printa as frases traduzidas de acordo com o alfabeto "novo"
            for (int k = 0; k < strlen(input[j]); k++){
                if (input[j][k] == ' '){
                    printf(" ");
                }
                else if (input[j][k] == '\n'){
                    printf("\n");
                }
                else{
                    printf("%c", alphabet[input[j][k] - 97]);
                }
            }
        }
        printf("\n");

    }



    return 0;
}

// frtjrpgguvj otvxmdxd prm iev prmvx xnmqq
// programming contests are fun arent the
