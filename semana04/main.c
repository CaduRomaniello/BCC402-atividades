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

int getFastest(bool* vet, int n){
    for (int i = 0; i < n; i++){
        if (vet[i]){
            return i;
        }
    }
    return -1;
}

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

int getSlowest(bool* vet, int n){
    for (int i = n-1; i >= 0; i--){
        if (vet[i]){
            return i;
        }
    }
    return -1;
}

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

    int numberOfCases;
    int numberOfPeople;
    int leftPeople, rightPeople;
    int* people;
    bool* leftSide;
    bool* rightSide;
    char* path = "";

    scanf("%d\n\n", &numberOfCases);

    for(int i = 0; i < numberOfCases; i++){

        scanf("%d\n", &numberOfPeople);
        leftPeople = numberOfPeople;
        rightPeople = 0;

        leftSide = malloc(numberOfPeople * sizeof(bool));
        rightSide = malloc(numberOfPeople * sizeof(bool));
        people = malloc(numberOfPeople * sizeof(int));
        for(int j = 0; j < numberOfPeople; j++){
            scanf("%d\n", &people[j]);
            leftSide[j] = true;
        }

        mergeSort(people, numberOfPeople);

        while(true){
            if(leftPeople == 1){
                int position = getFastest(leftSide, numberOfPeople);
                int speed = people[position];
                sprintf(path, "%d\n", speed);

                leftPeople -= 1;
                leftSide[position] = false;
                rightPeople += 1;
                rightSide[position] = true;
            }
            else if(leftPeople == 2){
                int position_1 = getFastest(leftSide, numberOfPeople);
                int position_2 = getSecondFastest(leftSide, numberOfPeople);
                int speed_1 = people[position_1];
                int speed_2 = people[position_2];
                sprintf(path, "%d %d\n", speed_1, speed_2);

                leftPeople -= 2;
                leftSide[position_1] = false;
                leftSide[position_2] = false;
                rightPeople += 2;
                rightSide[position_1] = true;
                rightSide[position_2] = true;
            }
            else if(leftPeople == 3){
                int position_1 = getFastest(leftSide, numberOfPeople);
                int position_2 = getSecondFastest(leftSide, numberOfPeople);
                int position_3 = getSlowest(leftSide, numberOfPeople);
                int speed_1 = people[position_1];
                int speed_2 = people[position_2];
                int speed_3 = people[position_3];
                sprintf(path, "%d %d\n%d\n%d %d", speed_1, speed_3, speed_1, speed_1, speed_2);

                leftPeople -= 3;
                leftSide[position_1] = false;
                leftSide[position_2] = false;
                leftSide[position_3] = false;
                rightPeople += 3;
                rightSide[position_1] = true;
                rightSide[position_2] = true;
                rightSide[position_3] = true;
            }
            else{
                int pos_fastest = getFastest(leftSide, numberOfPeople);
                int pos_secFastest = getSecondFastest(leftSide, numberOfPeople);
                int pos_slowest = getSlowest(leftSide, numberOfPeople);
                int pos_secslowest = getSecondSlowest(leftSide, numberOfPeople);
            }
        }











        free(people);
        free(leftSide);
        free(rightSide);

    }

    return 0;
}