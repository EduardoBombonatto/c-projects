#include <stdio.h>

int main()
{
    float principal, rate, time, interest;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the annual interest rate: ");
    scanf("%f", &rate);

    printf("Enter the time period (in years): ");
    scanf("%f", &time);

    interest = principal * (rate / 100) * time;

    printf("\nInput Values:\n");
    printf("Principal: $%.2f\n", principal);
    printf("Interest Rate: %.2f%%\n", rate);
    printf("Time Period: %.2f years\n", time);
    printf("\nCalculated Simple Interest: $%.2f\n", interest);
    printf("Total Amount:         $%10.2f\n", principal + interest);

    return 0;
}