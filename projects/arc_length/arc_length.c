#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x)
{
    return x * x;
}

// Calculate derivative of f(x)
double derivative_f(double x)
{
    return 2 * x;
}

// Approximate arc length using trapezoidal method
double calculate_arc_length(double a, double b, int n)
{
    double width = (b - a) / n;
    double arc_length = 0.0;

    for (int i = 0; i < n; i++)
    {
        double x0 = a + i * width;
        double x1 = a + (i + 1) * width;

        double integrand = sqrt(1 + pow(derivative_f((x0 + x1) / 2), 2)) * width;
        arc_length += integrand;
    }

    return arc_length;
}

// Theoretical arc length calculation
double theoretical_arc_length(double a, double b)
{
    // For f(x) = x^2, the theoretical arc length can be calculated
    return 0.5 * (sqrt(1 + 4 * b * b) + sqrt(1 + 4 * a * a) - 2);
}

int main()
{
    double a = 0.0; // Start of the interval
    double b = 2.0; // End of the interval
    int n = 1000;   // Number of trapezoids for approximation

    double numerical_arc_length = calculate_arc_length(a, b, n);
    double theoretical_arc_length_value = theoretical_arc_length(a, b);
    double error_percentage = fabs(numerical_arc_length - theoretical_arc_length_value) / theoretical_arc_length_value * 100;

    // Print detailed results
    printf("Arc Length Calculation Results\n");
    printf("-----------------------------\n");
    printf("Function: f(x) = x^2\n");
    printf("Interval: [%.1f, %.1f]\n", a, b);
    printf("\nNumerical Approximation Method:\n");
    printf("Number of Trapezoids: %d\n", n);
    printf("Approximated Arc Length: %.4f\n", numerical_arc_length);

    printf("\nTheoretical Arc Length: %.4f\n", theoretical_arc_length_value);
    printf("Approximation Error: %.2f%%\n", error_percentage);

    return 0;
}