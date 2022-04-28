#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// comandos: I, C, L, V, H, K, F, S, or X

void __I(char*** image, int* rows, int* columns); // funcao para o comando 'I'
void __C(char** image, int* rows, int* columns);  // funcao para o comando 'C'
void __L(char** image, int* rows, int* columns);  // funcao para o comando 'L'
void __V(char** image, int* rows, int* columns);  // funcao para o comando 'V'
void __H(char** image, int* rows, int* columns);  // funcao para o comando 'H'
void __K(char** image, int* rows, int* columns);  // funcao para o comando 'K'
void __F(char** image, int* rows, int* columns);  // funcao para o comando 'F'
void __S(char** image, int* rows, int* columns);  // funcao para o comando 'S'
void __X(char** image, int* rows, int* columns);  // funcao para o comando 'X'

bool validCommand(char c); // funcao que avalia se um comando eh valido
void executeCommand(char*** image, char option, int* rows, int* columns); // funcao que decide qual funcao chamar baseado na opcao
void fill(char** image, int rows, int columns, int row, int column, char color, char originalColor); // preenche uma area com a cor
                                                                                                     // desejada, essa funcao eh utilizada
                                                                                                     // no comando 'F'
bool validPosition(int rows, int columns, int i, int j, int delta_i, int delta_j); // verifica se uma posicao eh valida dentro da imagem 