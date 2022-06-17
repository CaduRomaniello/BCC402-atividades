#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void readInputLine(char** matrix, int n); // le os dados de entrada e os organiza na matriz
void checkAnswer(char** matC, char** matS, int correctLines, int submitedLines, int execution); // compara as duas respostas