#include <stdio.h>
#include <math.h>

// Previous function and method definitions remain the same
double f(double x)
{
    return x * x - 4;
}

double f_derivative(double x)
{
    return 2 * x;
}

double newton_method(double initial_guess, int max_iterations, double tolerance)
{
    double x = initial_guess;

    printf("Newton's Method Root Approximation\n");
    printf("-----------------------------------\n");
    printf("Initial Guess: %f\n", x);
    printf("Tolerance: %e\n", tolerance);
    printf("Max Iterations: %d\n\n", max_iterations);

    for (int i = 0; i < max_iterations; i++)
    {
        double fx = f(x);
        double fpx = f_derivative(x);

        if (fabs(fpx) < tolerance)
        {
            printf("Error: Derivative too close to zero.\n");
            return x;
        }

        double x_next = x - fx / fpx;

        printf("Iteration %d:\n", i + 1);
        printf("  Current x: %f\n", x_next);
        printf("  f(x): %f\n", f(x_next));
        printf("  |x_next - x|: %e\n\n", fabs(x_next - x));

        if (fabs(x_next - x) < tolerance)
        {
            printf("Convergence achieved!\n");
            return x_next;
        }

        x = x_next;
    }

    printf("Maximum iterations reached.\n");
    return x;
}

int main()
{
    double initial_guess = 1.0;
    int max_iterations = 10;
    double tolerance = 1e-6;

    double root = newton_method(initial_guess, max_iterations, tolerance);

    printf("Final Results:\n");
    printf("-------------\n");
    printf("Approximate Root: %f\n", root);
    printf("f(root): %f\n", f(root));
    printf("Absolute Error: %e\n", fabs(f(root)));

    return 0;
}