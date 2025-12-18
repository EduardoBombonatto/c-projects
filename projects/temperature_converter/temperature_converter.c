#include <stdio.h>

int main()
{
    float celsius, fahrentheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrentheit = (float) (celsius * 9.0 / 5.0) + 32.0;
    printf("Temperature in Fahrentheit: %.2f\n", fahrentheit);

    return 0;
}