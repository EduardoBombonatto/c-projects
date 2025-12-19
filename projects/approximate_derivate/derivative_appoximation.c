#include <stdio.h>
#include <math.h>

double f(double x){
    return x * x + 2 * x + 1;
}

double analytical_derivative(double x) {
    return 2 * x + 2;
}

double approximate_derivative(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

int main(){
    double x = 2.0; 
    double h_values[] = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8};
    int num_h = sizeof(h_values) / sizeof(h_values[0]);

    double true_derivative = analytical_derivative(x);

    printf("Function: f(x) = x^2 + 2x + 1\n");
    printf("Derivative Point: x = %.2f\n", x);
    printf("Analytical Derivative: %.4f\n\n", true_derivative);

    printf("Derivative Approximation Results:\n");
    printf("-----------------------------------\n");
    printf("Step Size (h)   Approximate Derivative   Error\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < num_h; i++) {
        double h = h_values[i];
        double approx_derivative = approximate_derivative(x, h);
        double error = fabs(true_derivative - approx_derivative);

        printf("%.1e             %.4f               %.6f\n",
               h, approx_derivative, error);
    }

    return 0;
}