/*@JUDGE ID:1275455 100 C “3n+1 problem”*/

/* @BEGIN OF SOURCE CODE */
#include <stdio.h>

int main(){

    int min, max;
    int count = 0;
    int maxCycle = 0;
    int it;
    int countPrint = 0;

    while (scanf("%d %d", &min, &max) != EOF){
        maxCycle = 0;

        if (countPrint != 0){
            /*printf("\n");*/
        }
        
        for(it = min; it <= max; it++){

            int actualNumber = it;
            count = 1;

            while (actualNumber != 1){
                if (actualNumber % 2 == 0){
                    actualNumber = actualNumber / 2;
                }
                else{
                    actualNumber = (actualNumber * 3) + 1;
                }

                count++;
            }

            if (it == min){
                maxCycle = count;
            }
            else{
                if (count > maxCycle){
                    maxCycle = count;
                }
            }
        }

        printf("%d %d %d\n", min, max, maxCycle);
        countPrint++;
    }

    return 0;
}

/* @END OF SOURCE CODE */
