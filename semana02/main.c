#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int main(){

    int n;
    int* sequence;
    bool* diff;

    int i, x;
    bool missingNumber;

    while(scanf("%d", &n) != EOF){
        missingNumber = false;

        sequence = malloc(n * sizeof(int));
        diff = malloc((n-1) * sizeof(int));

        for (i = 0; i < n ; i++){
            scanf("%d", &sequence[i]);

            if(i < (n-1)){
                diff[i] = false;
            }
        }

        for (i = 0; i < (n-1); i++){
            x = abs(sequence[i] - sequence[i+1]);

            if (x <= 0 || x > (n-1) || diff[x-1]){
                missingNumber = true;
                break;
            }
            else{
                diff[x-1] = true;
            }
        }

        for(i = 0; i < n-1; i++){
            if (!diff[i]){
                missingNumber = true;
                break;
            }
        }

        if(missingNumber){
            printf("Not jolly\n");
        }
        else{
            printf("Jolly\n");
        }

        free(sequence);
        free(diff);
        
    }

    return 0;
}
