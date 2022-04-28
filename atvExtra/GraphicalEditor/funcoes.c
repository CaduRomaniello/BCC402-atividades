#include "funcoes.h"
//I, C, L, V, H, K, F, S, or X

void __I(char*** image, int* rows, int* columns){
    
    // inicializa a imagem e a preenche com 'O'

    scanf("%d", columns);
    scanf("%d", rows);

    (*image) = malloc((*rows) * sizeof(char*));
    for (int i = 0; i < (*rows); i++){
        (*image)[i] = malloc((*columns) * sizeof(int));
    }

    for (int i = 0; i < (*rows); i++){
        for (int j = 0; j < (*columns); j++){
            (*image)[i][j] = 'O';
        }
    }

}

void __C(char** image, int* rows, int* columns){

    // preenche todos os pixels da imagem com 'O'

    for (int i = 0; i < (*rows); i++){
        for (int j = 0; j < (*columns); j++){
            image[i][j] = 'O';
        }
    }
}

void __L(char** image, int* rows, int* columns){

    // preenche o pixel (i, j) com a cor 'color'

    int i, j;
    char color;

    scanf("%d", &j);
    scanf("%d", &i);
    getchar();
    scanf("%c", &color);

    image[i-1][j-1] = color;
}

void __V(char** image, int* rows, int* columns){

    // cria uma linha na vertical na coluna 'column' que comeca em 'rowStart' e termina e 'rowEnd' com a cor 'color'

    int column, rowStart, rowEnd;
    char color;

    scanf("%d", &column);
    scanf("%d", &rowStart);
    scanf("%d", &rowEnd);
    getchar();
    scanf("%c", &color);

    for (int i = rowStart - 1; i <= rowEnd - 1; i++){
        image[i][column - 1] = color;
    }

}

void __H(char** image, int* rows, int* columns){

    // cria uma linha na horizontal na linha 'row' que comeca em 'columnStart' e termina e 'columnEnd' com a cor 'color'

    int row, columnStart, columnEnd;
    char color;

    scanf("%d", &columnStart);
    scanf("%d", &columnEnd);
    scanf("%d", &row);
    getchar();
    scanf("%c", &color);

    for (int i = columnStart - 1; i <= columnEnd - 1; i++){
        image[row - 1][i] = color;
    }
}

void __K(char** image, int* rows, int* columns){

    // preenche uma regiao em formato de retangulo na com o vertice superior esquerdo em (upperRow, upperColumn)
    // e vertice inferior (lowerRow, lowerColumn) com a cor 'color'

    int upperRow, upperColumn, lowerRow, lowerColumn;
    char color;

    scanf("%d", &upperColumn);
    scanf("%d", &upperRow);
    scanf("%d", &lowerColumn);
    scanf("%d", &lowerRow);
    getchar();
    scanf("%c", &color);

    for(int row = upperRow - 1; row <= lowerRow - 1; row++){
        for(int column = upperColumn - 1; column <= lowerColumn - 1; column++){
            image[row][column] = color;
        }
    }

}

void __F(char** image, int* rows, int* columns){
    
    // preenche uma regiao 'R' com a cor 'color'
    // a regiao 'R' eh definida da seguinte forma: o pixel inicial (row, column) possui cor 'originalColor'
    // todos os pixels adjacentes ao pixel inicial que possuem a cor 'originalColor' também serão preenchidos com 'color'

    int row, column;
    char color, originalColor;

    scanf("%d", &column);
    scanf("%d", &row);
    getchar();
    scanf("%c", &color);
    originalColor = image[row][column];

    fill(image, *rows, *columns, row, column, color, originalColor); // essa funcao faz o passo recursivo para preencher os pixels
                                                                     // adjacentes
}

void __S(char** image, int* rows, int* columns){

    // essa funcao printa a imagem no terminal com um nome 'name'

    char name[13];
    int tam;

    getchar();
    fgets(name, 13, stdin);

    printf("%s", name);

    // caso a string 'name' nao termine com '\n' um quebra de linha e inserida no terminal
    tam = strlen(name);
    if (name[tam - 1] != '\n'){
        printf("\n");
    }

    for (int i = 0; i < (*rows); i++){
        for (int j = 0; j < (*columns); j++){
            printf("%c ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void __X(char** image, int* rows, int* columns){

    // essa funcao encerra o programa
    // ela foi implementada somente por organizacao pois sua funcao eh executada no do-while da funcao main

    exit(0);
}

bool validCommand(char c){

    // essa funcao testa se o comando escolhido eh valido

    if (c == 'I' || c == 'C' || c == 'L' || c == 'V' || c == 'H' || c == 'K' || c == 'F' || c == 'S' || c == 'X'){
        return true;
    }

    return false;
}

void executeCommand(char*** image, char option, int* rows, int* columns){

    // essa funcao dado um comando chama a funcao correspondente

    if (option == 'I'){ __I(image, rows, columns); }
    else if(option == 'C'){ __C(*image, rows, columns); }
    else if(option == 'L'){ __L(*image, rows, columns); }
    else if(option == 'V'){ __V(*image, rows, columns); }
    else if(option == 'H'){ __H(*image, rows, columns); }
    else if(option == 'K'){ __K(*image, rows, columns); }
    else if(option == 'F'){ __F(*image, rows, columns); }
    else if(option == 'S'){ __S(*image, rows, columns); }
    else{
        return;
    }
}

void fill(char** image, int rows, int columns, int row, int column, char color, char originalColor){

    // essa funcao realiza a recursao apra poder preencher uma area

    if (image[row - 1][column - 1] == originalColor){ // caso o pixel seja da mesma cor da regiao que se deseja preencher, ele eh preenchido
        image[row - 1][column - 1] = color;
    }
    else{ // caso contrario paramos a recursao
        return;
    }

    if (validPosition(rows, columns, row, column, -1, -1)){ // upper left
        // chamada da recursao para o pixel superior esquerdo em relacao ao pixel inicial
        fill(image, rows, columns, row - 1, column - 1, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, -1, 0)){ // upper
        // chamada da recursao para o pixel superior em relacao ao pixel inicial
        fill(image, rows, columns, row - 1, column, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, -1, 1)){ // upper right
        // chamada da recursao para o pixel superior direito em relacao ao pixel inicial
        fill(image, rows, columns, row - 1, column + 1, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, 0, -1)){ // left
        // chamada da recursao para o pixel esquerdo em relacao ao pixel inicial
        fill(image, rows, columns, row, column - 1, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, 0, 1)){ // right
        // chamada da recursao para o pixel direito em relacao ao pixel inicial
        fill(image, rows, columns, row, column + 1, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, 1, -1)){ // lower left
        // chamada da recursao para o pixel inferior esquerdo em relacao ao pixel inicial
        fill(image, rows, columns, row + 1, column - 1, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, 1, 0)){ // lower
        // chamada da recursao para o pixel inferior em relacao ao pixel inicial
        fill(image, rows, columns, row + 1, column, color, originalColor);
    }

    if (validPosition(rows, columns, row, column, 1, 1)){ // lower right
        // chamada da recursao para o pixel inferior direito em relacao ao pixel inicial
        fill(image, rows, columns, row + 1, column + 1, color, originalColor);
    }


}

bool validPosition(int rows, int columns, int i, int j, int delta_i, int delta_j){

    // essa funcao dado um pixel (i, j) verifica se o pixel (i + delta_i, j + delta_j) eh valido na imagem

    if (i + delta_i <= 0 || i + delta_i > rows){
        return false;
    }
    if ((j + delta_j <= 0 || j + delta_j > columns)){
        return false;
    }

    return true;

}