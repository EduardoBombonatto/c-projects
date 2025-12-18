#include <stdio.h>

int main(){
    int grade;
    printf("Enter your numerical grade (0-100): ");
    scanf("%d", &grade);

    if (grade >= 90 && grade <= 100) {
        printf("Letter Grade: A\n");
    } else if (grade >= 80 && grade < 90) {
        printf("Letter Grade: B\n");
    } else if (grade >= 70 && grade < 80) {
        printf("Letter Grade: C\n");
    } else if (grade >= 60 && grade < 70) {
        printf("Letter Grade: D\n");
    } else if (grade >= 0 && grade < 60) {
        printf("Letter Grade: F\n");
    } else {
        printf("Invalid grade entered. Please enter a grade between 0 and 100.\n");
    }
    return 0;
}