#include <stdio.h>

int main(){
    int scores[5];
    int sum = 0;
    printf("Enter your 5 scores:\n");
    for(int i = 0; i < 5; i++){
        printf("Score %d: ", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }
    float average = sum / 5.0;
    printf("Average score: %.2f\n", average);
    return 0;
}